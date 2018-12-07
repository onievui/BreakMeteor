#include "MoveBlock.h"
#include "Field.h"
#include "MyMath.h"
#include "Sound.h"


/// <summary>
/// �R���X�g���N�^
/// </summary>
/// <param name="_pos">���W</param>
/// <param name="_width">����</param>
/// <param name="_height">�c��</param>
/// <param name="_hp">�ϋv�x</param>
/// <param name="_score">�X�R�A</param>
/// <param name ="_color">�F</param>
MoveBlock::MoveBlock(const Vector2 &_pos, const float _width, const float _height, const int _hp, const int _score, std::unique_ptr<Color> &_color)
	: AbstractBlock(_pos, _width, _height, _hp, _score)
	, moveSpeed(2) 
	, faceLeft(true) {
	color = std::move(_color);
	collider = std::make_unique<RectRotateCollider>(&pos, Vector2(0, 0), &vel, width, height, &angle);
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
MoveBlock::~MoveBlock() {

}

/// <summary>
/// �X�V
/// </summary>
void MoveBlock::update() {
	pos += vel;
	vel = { 0,0 };
	vel.x = moveSpeed * (faceLeft ? -1.f : 1.f);
	vel.y = 0.5f;
	collisionWall();
}

/// <summary>
/// �`��
/// </summary>
void MoveBlock::draw() const {
	//�e���_���W�̌v�Z
	Vector2 vertex[4];
	for (int i = 0; i < 4; ++i) {
		int xc = (i == 0 || i == 3) ? -1 : 1;
		int yc = (i < 2) ? -1 : 1;
		vertex[i] = Vector2::rotate(Vector2(width / 2.f * xc, height / 2.f * yc), angle) + pos;
	}

	DrawQuadrangleAA(vertex[0].x, vertex[0].y, vertex[1].x, vertex[1].y, vertex[2].x, vertex[2].y, vertex[3].x, vertex[3].y, color->getColor(), true);
	DrawQuadrangleAA(vertex[0].x, vertex[0].y, vertex[1].x, vertex[1].y, vertex[2].x, vertex[2].y, vertex[3].x, vertex[3].y, COLOR_WHITE, false);
}

/// <summary>
/// �{�[���ƏՓ˂����Ƃ��̏���
/// </summary>
void MoveBlock::onHitBall(float _time) {
	vel *= _time;
	hp -= 1;
	if (hp <= 0) {
		isValid = false;
		SoundPlayer::getIns()->setSound(SOUND_DESTROY);
	}
}

int MoveBlock::getScore() const {
	if (!isValid) {
		return score;
	}
	return 0;
}

/// <summary>
/// �ǂƂ̓����蔻��
/// </summary>
void MoveBlock::collisionWall() {
	float next_x = pos.x + vel.x;
	if (next_x - width / 2 < FIELD::LEFT) {
		faceLeft = !faceLeft;
	}
	else if (next_x + width / 2 > FIELD::RIGHT) {
		faceLeft = !faceLeft;
	}
}
