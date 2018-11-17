#include "Paddle.h"
#include "Field.h"
#include "MyMath.h"
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
	rotateVel = 0;
	width  = 80;
	height = 16;
	speed  = 5;
	collider = std::make_unique<RectRotateCollider>(&pos, Vector2(0, 0), &vel, width, height, &angle);
	color = std::make_unique<RGBColor>(ColorCode::COLOR_WHITE);
}

/// <summary>
/// 更新
/// </summary>
void Paddle::update() {
	move();
	if (Pad::getIns()->statePress(PadCode::Z)) {
		rotateVel = PI / 90;
	}
}

/// <summary>
/// 描画
/// </summary>
void Paddle::draw() const {

	Vector2 seg_pos[2];
	seg_pos[0] = pos + Vector2::createWithAngleNorm(angle, width / 2);
	seg_pos[1] = pos + Vector2::createWithAngleNorm(angle + PI, width / 2);

	Vector2 ver_pos[4];
	ver_pos[0] = seg_pos[0] + Vector2::createWithAngleNorm(angle - PI / 2, height / 2);
	ver_pos[1] = seg_pos[0] + Vector2::createWithAngleNorm(angle + PI / 2, height / 2);
	ver_pos[2] = seg_pos[1] + Vector2::createWithAngleNorm(angle + PI / 2, height / 2);
	ver_pos[3] = seg_pos[1] + Vector2::createWithAngleNorm(angle - PI / 2, height / 2);

	DrawQuadrangleAA(ver_pos[0].x, ver_pos[0].y, ver_pos[1].x, ver_pos[1].y, ver_pos[2].x, ver_pos[2].y, ver_pos[3].x, ver_pos[3].y, color->getColor(), true);
}

/// <summary>
/// ボールと衝突したときの処理
/// </summary>
/// <param name="_time">衝突までの時間</param>
void Paddle::onHitBall(const float _time) {
	vel *= _time;
}

/// <summary>
/// 当たり判定の取得
/// </summary>
/// <returns>当たり判定のポインタ</returns>
RectRotateCollider* Paddle::getCollider() const {
	return collider.get();
}

/// <summary>
/// 座安俵の取得
/// </summary>
/// <returns>
/// 座標
/// </returns>
const Vector2& Paddle::getPos() const {
	return pos;
}

/// <summary>
/// 回転後の角度の取得
/// </summary>
/// <returns>
/// 回転後の角度
/// </returns>
float Paddle::getRotatedAngle() const {
	return angle + rotateVel;
}

/// <summary>
/// 移動の中止
/// </summary>
void Paddle::cancelMove() {
	vel = { 0,0 };
	rotateVel = 0;
}

/// <summary>
/// 回転させる
/// </summary>
void Paddle::rotate() {
	angle += rotateVel;
}


/// <summary>
/// 移動処理
/// </summary>
void Paddle::move() {
	pos += vel;
	vel = { 0,0 };
	rotateVel = 0;
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
