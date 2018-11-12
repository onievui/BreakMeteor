#pragma once
#include "NormalBall.h"
#include "Field.h"
#include "MyMath.h"


/// <summary>
/// �R���X�g���N�^
/// </summary>
NormalBall::NormalBall()
	: AbstractBall::AbstractBall(Vector2(320,300), Vector2(0,0), 5.f, PI / 4, 4.f) {
	//���x�D��ׁ̈A�C�j�V�����C�U���g�p
	collider = std::make_unique<RectCollider>(&pos, Vector2(0, 0), &vel, radius, radius);
	color = std::make_unique<RGBColor>(ColorCode::COLOR_YELLOW);
	
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
NormalBall::~NormalBall() {

}

/// <summary>
/// �X�V
/// </summary>
void NormalBall::update() {
	pos += vel;
	collisionWall();
	vel = { 0,0 };
	vel = Vector2::createWithAngleNorm(angle, speed);
}

/// <summary>
/// �`��
/// </summary>
void NormalBall::draw() const {
	DrawCircleAA(pos.x, pos.y, radius, 16, color->getColor(), true);
}

/// <summary>
/// ����
/// </summary>
/// <param name="_time">������܂ł̎���</param>
/// <param name="_ref_normal">���˖ʂ̖@��</param>
void NormalBall::reflect(const float _time, const float _ref_normal) {
	pos += vel * _time;
	//���E���瓖�������ꍇ
	if (FloatEqual(_ref_normal, 0.f) && vel.x < 0.f || FloatEqual(_ref_normal, PI) && vel.x > 0.f) {
		if (angle < PI) {
			angle = PI - angle;
		}
		else {
			angle = PI * 3 - angle;
		}
	}
	//�㉺���瓖�������ꍇ
	else  {
		angle = PI * 2 - angle;
	}
	vel = Vector2::createWithAngleNorm(angle, speed)*(1.f - _time);
}

/// <summary>
/// �ǂƏՓ˂����Ƃ��̏���
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
