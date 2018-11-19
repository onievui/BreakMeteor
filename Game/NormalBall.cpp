#pragma once
#include "NormalBall.h"
#include "Field.h"
#include "MyMath.h"


/// <summary>
/// コンストラクタ
/// </summary>
NormalBall::NormalBall()
	: AbstractBall::AbstractBall(Vector2(320,300), Vector2(0,0), 6.f, PI / 4, 5.f) {
	//速度優先の為、イニシャライザ未使用
	collider = std::make_unique<CircleCollider>(&pos, Vector2(0, 0), &vel, radius);
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
/// <param name="_ref_normal">反射点の法線</param>
void NormalBall::reflect(const float _time, const float _ref_normal) {
	pos += vel * _time;
	float rotate = PI / 2 - _ref_normal;
	float rotate_angle = angle + rotate;
	if (sinf(rotate_angle) < 0) {
		angle = PI * 2 - rotate_angle - rotate;
	}
	normalizeAngle();
	vel = Vector2::createWithAngleNorm(angle, speed)*(1.f - _time);
}

/// <summary>
/// 角度の正規化
/// </summary>
void NormalBall::normalizeAngle() {
	angle = std::fmodf(angle, PI2);
	if (angle < 0) {
		angle += PI2;
	}
}

/// <summary>
/// 角度の調整
/// </summary>
void NormalBall::regulateAngle()  {
	//角度の正規化
	normalizeAngle();
	//角度の調整
	float tmp_angle = std::fmodf(angle, PI / 2);
	if (tmp_angle < PI / 12) {
		angle += PI / 12;
	}
	else if (tmp_angle > PI * 11 / 12) {
		angle -= PI / 12;
	}
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
		regulateAngle();
	}
	if (pos.y - radius <= FIELD::TOP || pos.y + radius >= FIELD::BOTTOM) {
		angle = PI * 2 - angle;
		regulateAngle();
	}
}
