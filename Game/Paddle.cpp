#include "Paddle.h"
#include "Field.h"
#include "Pad.h"


/// <summary>
/// コンストラクタ
/// </summary>
Paddle::Paddle() {
	initialize();
}

/// <summary>
/// 初期化
/// </summary>
void Paddle::initialize() {
	pos    = { (int)DEFAULT_POS_X,(int)DEFAULT_POS_Y };
	vel    = { 0,0 };
	angle  = 0;
	width  = 80;
	height = 16;
	speed  = 5;
	collider = std::make_unique<RectCollider>(&pos, Vector2(0, 0), &vel, width, height);
	color = std::make_unique<RGBColor>(ColorCode::COLOR_WHITE);
}

/// <summary>
/// 更新
/// </summary>
void Paddle::update() {
	move();
}

/// <summary>
/// 描画
/// </summary>
void Paddle::draw() const {
	DrawBoxAA(pos.x - width / 2, pos.y - height / 2, pos.x + width / 2, pos.y + height / 2, color->getColor(), true);
}

/// <summary>
/// ボールと衝突したときの処理
/// </summary>
/// <param name="_time">衝突までの時間</param>
void Paddle::collisionBall(const float _time) {
	vel *= _time;
}

/// <summary>
/// 当たり判定の取得
/// </summary>
/// <returns>当たり判定のポインタ</returns>
RectCollider* Paddle::getCollider() const {
	return collider.get();
}

//移動
void Paddle::move() {
	pos += vel;
	vel = { 0,0 };
	float move_speed;
	switch (Pad::getIns()->statePressLater(PadCode::LEFT, PadCode::RIGHT)) {
	//移動していない
	case 0:
		move_speed = 0;
		break;
	//左に移動
	case 1:
		move_speed = -speed;
		break;
	//右に移動
	case 2:
		move_speed = speed;
		break;
	default:
		MessageBox(NULL, "パドルの移動で不正な値が渡されました", "", MB_OK);
		return;
		break;
	}

	//フィールド外に出ないようにする
	float next_x = pos.x + move_speed;
	if (next_x - width / 2 < FIELD::LEFT) {
		move_speed -= (next_x - width / 2 - FIELD::LEFT);
	}
	else if (next_x + width / 2 > FIELD::RIGHT) {
		move_speed -= (next_x + width / 2 - FIELD::RIGHT);
	}
	vel.x = move_speed;
}
