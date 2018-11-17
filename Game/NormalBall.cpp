#pragma once
#include "NormalBall.h"
#include "Field.h"
#include "MyMath.h"


/// <summary>
/// �R���X�g���N�^
/// </summary>
NormalBall::NormalBall()
	: AbstractBall::AbstractBall(Vector2(320,300), Vector2(0,0), 5.f, PI / 4, 3.f) {
	//���x�D��ׁ̈A�C�j�V�����C�U���g�p
	collider = std::make_unique<CircleCollider>(&pos, Vector2(0, 0), &vel, radius);
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
/// <param name="_ref_normal">���˓_�̖@��</param>
/// <param name="_hit_pos_x">���˓_��X���W</param>
void NormalBall::reflect(const float _time, const float _ref_normal, const float _hit_pos_x) {
	pos += vel * _time;
	//���E���瓖�������ꍇ
	//if (FloatEqual(_ref_normal, 0.f) && vel.x < 0.f || FloatEqual(_ref_normal, PI) && vel.x > 0.f) {
	//	if (angle < PI) {
	//		angle = PI - angle;
	//	}
	//	else {
	//		angle = PI * 3 - angle;
	//	}
	//}
	////�㉺���瓖�������ꍇ
	//else  {
	//	angle = PI * 2 - angle;
	//	//�p�x�����炷
	//	if (!FloatEqual(_hit_pos_x, -1.f)) {
	//		angle -= (PI / 10)*((pos.x - _hit_pos_x) / 40.f);
	//	}
	//}
	float rotate = PI / 2 - _ref_normal;
	float rotate_angle = angle + rotate;
	if (sinf(rotate_angle) < 0) {
		angle = PI * 2 - rotate_angle - rotate;
	}
	regulateAngle();
	vel = Vector2::createWithAngleNorm(angle, speed)*(1.f - _time);
}

/// <summary>
/// �p�x�̒���
/// </summary>
void NormalBall::regulateAngle()  {
	//�p�x�̐��K��
	angle = std::fmodf(angle, PI2);
	if (angle < 0) {
		angle += PI2;
	}
	//�p�x�̒���
	//float tmp_angle = std::fmodf(angle, PI / 2);
	//if (tmp_angle < PI / 12) {
	//	angle += PI / 12;
	//}
	//else if (tmp_angle > PI * 11 / 12) {
	//	angle -= PI / 12;
	//}
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
