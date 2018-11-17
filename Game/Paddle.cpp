#include "Paddle.h"
#include "Field.h"
#include "MyMath.h"
#include "Pad.h"


/// <summary>
/// �R���X�g���N�^
/// </summary>
Paddle::Paddle() {
	initialize();
}

/// <summary>
/// ������
/// </summary>
void Paddle::initialize() {
	pos    = { (int)DEFAULT_POS_X,(int)DEFAULT_POS_Y };
	vel    = { 0,0 };
	angle  = 0;
	width  = 80;
	height = 16;
	speed  = 5;
	collider = std::make_unique<RectRotateCollider>(&pos, Vector2(0, 0), &vel, width, height, &angle);
	color = std::make_unique<RGBColor>(ColorCode::COLOR_WHITE);
}

/// <summary>
/// �X�V
/// </summary>
void Paddle::update() {
	move();
	if (Pad::getIns()->statePress(PadCode::Z))
		angle += PI / 90;
}

/// <summary>
/// �`��
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
/// �{�[���ƏՓ˂����Ƃ��̏���
/// </summary>
/// <param name="_time">�Փ˂܂ł̎���</param>
void Paddle::onHitBall(const float _time) {
	vel *= _time;
}

/// <summary>
/// �����蔻��̎擾
/// </summary>
/// <returns>�����蔻��̃|�C���^</returns>
RectRotateCollider* Paddle::getCollider() const {
	return collider.get();
}

const Vector2& Paddle::getPos() const {
	return pos;
}

//�ړ�
void Paddle::move() {
	pos += vel;
	vel = { 0,0 };
	float move_speed;
	switch (Pad::getIns()->statePressLater(PadCode::LEFT, PadCode::RIGHT)) {
	//�ړ����Ă��Ȃ�
	case 0:
		move_speed = 0;
		break;
	//���Ɉړ�
	case 1:
		move_speed = -speed;
		break;
	//�E�Ɉړ�
	case 2:
		move_speed = speed;
		break;
	default:
		MessageBox(NULL, "�p�h���̈ړ��ŕs���Ȓl���n����܂���", "", MB_OK);
		return;
		break;
	}

	//�t�B�[���h�O�ɏo�Ȃ��悤�ɂ���
	float next_x = pos.x + move_speed;
	if (next_x - width / 2 < FIELD::LEFT) {
		move_speed -= (next_x - width / 2 - FIELD::LEFT);
	}
	else if (next_x + width / 2 > FIELD::RIGHT) {
		move_speed -= (next_x + width / 2 - FIELD::RIGHT);
	}
	vel.x = move_speed;
}
