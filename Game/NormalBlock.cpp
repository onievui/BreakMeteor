#include "NormalBlock.h"


/// <summary>
/// �R���X�g���N�^
/// </summary>
/// <param name="_pos">���W</param>
/// <param name="_width">����</param>
/// <param name="_height">�c��</param>
/// <param name="_hp">�ϋv�x</param>
/// <param name="_color">�F</param>
NormalBlock::NormalBlock(const Vector2 &_pos, const float _width, const float _height, const int _hp,std::unique_ptr<Color> &_color) {
	pos      = _pos;
	vel      = Vector2(0, 0);
	width    = _width;
	height   = _height;
	hp       = _hp;
	isValid  = true;
	color    = std::move(_color);
	collider = std::make_unique<RectCollider>(&pos, Vector2(0, 0), &vel, width, height);
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
NormalBlock::~NormalBlock() {

}

/// <summary>
/// �X�V
/// </summary>
void NormalBlock::update() {

}

/// <summary>
/// �`��
/// </summary>
void NormalBlock::draw() const {
	DrawBoxAA(pos.x - width / 2, pos.y - height / 2, pos.x + width / 2, pos.y + height / 2, color->getColor(), true);
	DrawBoxAA(pos.x - width / 2, pos.y - height / 2, pos.x + width / 2, pos.y + height / 2, ColorCode::COLOR_WHITE, false);
}

/// <summary>
/// �{�[���ƏՓ˂����Ƃ��̏���
/// </summary>
void NormalBlock::collisionBall() {
	hp -= 1;
	if (hp <= 0) {
		isValid = false;
	}
}
