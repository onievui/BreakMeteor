#include "Paddle.h"
#include "Field.h"
#include "MyMath.h"
#include "Pad.h"


const int Paddle::DEFAULT_POS_X = 225; //パドルの初期X座標
const int Paddle::DEFAULT_POS_Y = 700; //パドルの初期Y座標


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
	pos    = { (float)DEFAULT_POS_X,(float)DEFAULT_POS_Y };
	vel    = { 0,0 };
	angle  = 0;
	rotateVel = 0;
	width  = 80;
	height = 16;
	speed  = 5;
	score = 0;
	isAlive = true;
	collider = std::make_unique<RectRotateCollider>(&pos, Vector2(0, 0), &vel, width, height, &angle);
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

	//各頂点座標の計算
	Vector2 vertex[4];
	for (int i = 0; i < 4; ++i) {
		int xc = (i == 0 || i == 3) ? -1 : 1;
		int yc = (i < 2) ? -1 : 1;
		vertex[i] = Vector2::rotate(Vector2(width / 2.f * xc, height / 2.f * yc), angle) + pos;
	}
	
	DrawQuadrangleAA(vertex[0].x, vertex[0].y, vertex[1].x, vertex[1].y, vertex[2].x, vertex[2].y, vertex[3].x, vertex[3].y, color->getColor(), true);
	DrawFormatString(20, 20, COLOR_WHITE, "SCORE : %d", score);
}

/// <summary>
/// ボールと衝突したときの処理
/// </summary>
/// <param name="_time">衝突までの時間</param>
void Paddle::onHitBall(const float _time) {
	vel *= _time;
}

/// <summary>
/// ブロックと衝突したときの処理
/// </summary>
void Paddle::onHitBlock() {
	isAlive = false;
}

/// <summary>
/// 当たり判定の取得
/// </summary>
/// <returns>当たり判定のポインタ</returns>
RectRotateCollider* Paddle::getCollider() const {
	return collider.get();
}

/// <summary>
/// 座標の取得
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
/// スコアの追加
/// </summary>
/// <param name="_score">スコア</param>
void Paddle::addScore(const int _score) {
	score += _score;
}

int Paddle::getScore() {
	return score;
}

bool Paddle::checkIsAlive() const {
	return isAlive;
}


/// <summary>
/// 移動処理
/// </summary>
void Paddle::move() {
	pos += vel;
	vel = { 0,0 };
	rotateVel = 0;

	//左右移動
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
	
	//回転
	switch (Pad::getIns()->statePressLater(PadCode::Z, PadCode::X)) {
		//回転していない
	case 0:
		rotateVel = 0;
		break;
		//左に回転
	case 1:
		rotateVel = -PI / 90;
		break;
		//右に回転
	case 2:
		rotateVel = PI / 90;
		break;
	default:
		MessageBox(NULL, "パドルの回転で不正な値が渡されました", "", MB_OK);
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
