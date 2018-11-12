#pragma once
#include "NormalBall.h"
#include "Field.h"
#include "MyMath.h"


/// <summary>
/// コンストラクタ
/// </summary>
NormalBall::NormalBall()
	: AbstractBall::AbstractBall(Vector2(320,300), Vector2(0,0), 5.f, PI / 4, 4.f) {
	//速度優先の為、イニシャライザ未使用
	collider = std::make_unique<RectCollider>(&pos, Vector2(0, 0), &vel, radius, radius);
	color = std::make_unique<RGBColor>(ColorCode::COLOR_YELLOW);
	
}

/// <summary>
/// デストラクタ
/// </summary>
NormalBall::~NormalBall() {

}

/// <summary>
/// 更新
/// </summary>
void NormalBall::update() {
	pos += vel;
	collisionWall();
	vel = { 0,0 };
	vel = Vector2::createWithAngleNorm(angle, speed);
}

/// <summary>
/// 描画
/// </summary>
void NormalBall::draw() const {
	DrawCircleAA(pos.x, pos.y, radius, 16, color->getColor(), true);
}

/// <summary>
/// 反射
/// </summary>
/// <param name="_time">当たるまでの時間</param>
/// <param name="_ref_normal">反射面の法線</param>
void NormalBall::reflect(const float _time, const float _ref_normal) {
	pos += vel * _time;
	//左右から当たった場合
	if (FloatEqual(_ref_normal, 0.f) && vel.x < 0.f || FloatEqual(_ref_normal, PI) && vel.x > 0.f) {
		if (angle < PI) {
			angle = PI - angle;
		}
		else {
			angle = PI * 3 - angle;
		}
	}
	//上下から当たった場合
	else  {
		angle = PI * 2 - angle;
	}
	vel = Vector2::createWithAngleNorm(angle, speed)*(1.f - _time);
}

/// <summary>
/// 壁と衝突したときの処理
/// </summary>
void NormalBall::collisionWall() {
	if (pos.x - radius <= FIELD::LEFT && vel.x < 0.f || pos.x + radius >= FIELD::RIGHT && vel.x > 0.f) {
		if (angle < PI) {
			angle = PI - angle;
		}
		else {
			angle = PI * 3 - angle;
		}
	}
	if (pos.y - radius <= FIELD::TOP || pos.y + radius >= FIELD::BOTTOM) {
		angle = PI * 2 - angle;
	}
}
