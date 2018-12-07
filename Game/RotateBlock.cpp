#include "RotateBlock.h"
#include "MyMath.h"
#include "Sound.h"

/// <summary>
/// コンストラクタ
/// </summary>
/// <param name="_pos">座標</param>
/// <param name="_width">横幅</param>
/// <param name="_height">縦幅</param>
/// <param name="_hp">耐久度</param>
/// /// <param name="_score">スコア</param>
/// <param name="_color">色</param>
RotateBlock::RotateBlock(const Vector2 &_pos, const float _width, const float _height, const int _hp, const int _score, std::unique_ptr<Color> &_color)
	: AbstractBlock(_pos, _width, _height, _hp, _score) 
	, rotateSpeed(PI / 60) {
	color = std::move(_color);
	collider = std::make_unique<RectRotateCollider>(&pos, Vector2(0, 0), &vel, width, height, &angle);
}

/// <summary>
/// デストラクタ
/// </summary>
RotateBlock::~RotateBlock() {

}

/// <summary>
/// 更新
/// </summary>
void RotateBlock::update() {
	pos += vel;
	angle += rotateSpeed;
	vel = { 0,0 };
	vel.y += 0.8f;
}

/// <summary>
/// 描画
/// </summary>
void RotateBlock::draw() const {
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
void RotateBlock::onHitBall(float _time) {
	vel *= _time;
	hp -= 1;
	if (hp <= 0) {
		isValid = false;
		SoundPlayer::getIns()->setSound(SOUND_DESTROY);
	}
}

int RotateBlock::getScore() const {
	if (!isValid) {
		return score;
	}
	return 0;
}
