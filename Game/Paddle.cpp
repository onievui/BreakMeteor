#include "Paddle.h"
#include "Field.h"
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
	collider = std::make_unique<RectCollider>(&pos, Vector2(0, 0), &vel, width, height);
	color = std::make_unique<RGBColor>(ColorCode::COLOR_WHITE);
}

/// <summary>
/// �X�V
/// </summary>
void Paddle::update() {
	move();
}

/// <summary>
/// �`��
/// </summary>
void Paddle::draw() const {
	DrawBoxAA(pos.x - width / 2, pos.y - height / 2, pos.x + width / 2, pos.y + height / 2, color->getColor(), true);
}

/// <summary>
/// �{�[���ƏՓ˂����Ƃ��̏���
/// </summary>
/// <param name="_time">�Փ˂܂ł̎���</param>
void Paddle::collisionBall(const float _time) {
	vel *= _time;
}

/// <summary>
/// �����蔻��̎擾
/// </summary>
/// <returns>�����蔻��̃|�C���^</returns>
RectCollider* Paddle::getCollider() const {
	return collider.get();
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
