#include "NormalBlock.h"


/// <summary>
/// コンストラクタ
/// </summary>
/// <param name="_pos">座標</param>
/// <param name="_width">横幅</param>
/// <param name="_height">縦幅</param>
/// <param name="_hp">耐久度</param>
/// <param name="_color">色</param>
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
/// デストラクタ
/// </summary>
NormalBlock::~NormalBlock() {

}

/// <summary>
/// 更新
/// </summary>
void NormalBlock::update() {

}

/// <summary>
/// 描画
/// </summary>
void NormalBlock::draw() const {
	DrawBoxAA(pos.x - width / 2, pos.y - height / 2, pos.x + width / 2, pos.y + height / 2, color->getColor(), true);
	DrawBoxAA(pos.x - width / 2, pos.y - height / 2, pos.x + width / 2, pos.y + height / 2, ColorCode::COLOR_WHITE, false);
}

/// <summary>
/// ボールと衝突したときの処理
/// </summary>
void NormalBlock::collisionBall() {
	hp -= 1;
	if (hp <= 0) {
		isValid = false;
	}
}
