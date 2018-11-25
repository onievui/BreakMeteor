#include "Paddle.h"
#include "Field.h"
#include "MyMath.h"
#include "Pad.h"


const int Paddle::DEFAULT_POS_X = 225; //�p�h���̏���X���W
const int Paddle::DEFAULT_POS_Y = 700; //�p�h���̏���Y���W


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
/// �X�V
/// </summary>
void Paddle::update() {
	move();
}

/// <summary>
/// �`��
/// </summary>
void Paddle::draw() const {

	//�e���_���W�̌v�Z
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
/// �{�[���ƏՓ˂����Ƃ��̏���
/// </summary>
/// <param name="_time">�Փ˂܂ł̎���</param>
void Paddle::onHitBall(const float _time) {
	vel *= _time;
}

/// <summary>
/// �u���b�N�ƏՓ˂����Ƃ��̏���
/// </summary>
void Paddle::onHitBlock() {
	isAlive = false;
}

/// <summary>
/// �����蔻��̎擾
/// </summary>
/// <returns>�����蔻��̃|�C���^</returns>
RectRotateCollider* Paddle::getCollider() const {
	return collider.get();
}

/// <summary>
/// ���W�̎擾
/// </summary>
/// <returns>
/// ���W
/// </returns>
const Vector2& Paddle::getPos() const {
	return pos;
}

/// <summary>
/// ��]��̊p�x�̎擾
/// </summary>
/// <returns>
/// ��]��̊p�x
/// </returns>
float Paddle::getRotatedAngle() const {
	return angle + rotateVel;
}

/// <summary>
/// �ړ��̒��~
/// </summary>
void Paddle::cancelMove() {
	vel = { 0,0 };
	rotateVel = 0;
}

/// <summary>
/// ��]������
/// </summary>
void Paddle::rotate() {
	angle += rotateVel;
}

/// <summary>
/// �X�R�A�̒ǉ�
/// </summary>
/// <param name="_score">�X�R�A</param>
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
/// �ړ�����
/// </summary>
void Paddle::move() {
	pos += vel;
	vel = { 0,0 };
	rotateVel = 0;

	//���E�ړ�
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
	
	//��]
	switch (Pad::getIns()->statePressLater(PadCode::Z, PadCode::X)) {
		//��]���Ă��Ȃ�
	case 0:
		rotateVel = 0;
		break;
		//���ɉ�]
	case 1:
		rotateVel = -PI / 90;
		break;
		//�E�ɉ�]
	case 2:
		rotateVel = PI / 90;
		break;
	default:
		MessageBox(NULL, "�p�h���̉�]�ŕs���Ȓl���n����܂���", "", MB_OK);
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
