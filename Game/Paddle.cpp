#include "Paddle.h"
#include "Field.h"
#include "Pad.h"



Paddle::Paddle() {
	initialize();
}

void Paddle::initialize() {
	pos    = { (int)DEFAULT_POS_X,(int)DEFAULT_POS_Y };
	vel    = { 0,0 };
	angle  = 0;
	width  = 80;
	height = 16;
	speed  = 5;
	color  = COLOR_WHITE;
}

void Paddle::update() {
	move();
}

void Paddle::draw() const {
	DrawBoxAA(pos.x - width / 2, pos.y - height / 2, pos.x + width / 2, pos.y + height / 2, color, true);
}

void Paddle::move() {
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

	pos += vel;
}