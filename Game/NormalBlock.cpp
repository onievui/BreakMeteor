#include "NormalBlock.h"
#include "MyMath.h"

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
	angle    = 0;
	width    = _width;
	height   = _height;
	hp       = _hp;
	isValid  = true;
	color    = std::move(_color);
	collider = std::make_unique<RectRotateCollider>(&pos, Vector2(0, 0), &vel, width, height, &angle);
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
	Vector2 seg_pos[2];
	seg_pos[0] = pos + Vector2::createWithAngleNorm(angle, width / 2);
	seg_pos[1] = pos + Vector2::createWithAngleNorm(angle + PI, width / 2);

	Vector2 ver_pos[4];
	ver_pos[0] = seg_pos[0] + Vector2::createWithAngleNorm(angle - PI / 2, height / 2);
	ver_pos[1] = seg_pos[0] + Vector2::createWithAngleNorm(angle + PI / 2, height / 2);
	ver_pos[2] = seg_pos[1] + Vector2::createWithAngleNorm(angle + PI / 2, height / 2);
	ver_pos[3] = seg_pos[1] + Vector2::createWithAngleNorm(angle - PI / 2, height / 2);

	DrawQuadrangleAA(ver_pos[0].x, ver_pos[0].y, ver_pos[1].x, ver_pos[1].y, ver_pos[2].x, ver_pos[2].y, ver_pos[3].x, ver_pos[3].y, color->getColor(), true);
	DrawQuadrangleAA(ver_pos[0].x, ver_pos[0].y, ver_pos[1].x, ver_pos[1].y, ver_pos[2].x, ver_pos[2].y, ver_pos[3].x, ver_pos[3].y, COLOR_WHITE, false);
	//DrawBoxAA(pos.x - width / 2, pos.y - height / 2, pos.x + width / 2, pos.y + height / 2, color->getColor(), true);
	//DrawBoxAA(pos.x - width / 2, pos.y - height / 2, pos.x + width / 2, pos.y + height / 2, ColorCode::COLOR_WHITE, false);
}

/// <summary>
/// �{�[���ƏՓ˂����Ƃ��̏���
/// </summary>
void NormalBlock::onHitBall() {
	hp -= 1;
	if (hp <= 0) {
		isValid = false;
	}
}
