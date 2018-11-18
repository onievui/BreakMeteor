#include "NormalBlock.h"
#include "MyMath.h"

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
	angle    = 0;
	width    = _width;
	height   = _height;
	hp       = _hp;
	isValid  = true;
	color    = std::move(_color);
	collider = std::make_unique<RectRotateCollider>(&pos, Vector2(0, 0), &vel, width, height, &angle);
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
	pos.y += 0.5f;
}

/// <summary>
/// 描画
/// </summary>
void NormalBlock::draw() const {
	//各頂点座標の計算
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
/// ボールと衝突したときの処理
/// </summary>
void NormalBlock::onHitBall() {
	hp -= 1;
	if (hp <= 0) {
		isValid = false;
	}
}
