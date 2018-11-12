#pragma once

#include "AbstractBlock.h"


//ノーマルブロッククラス
class NormalBlock : public AbstractBlock {

public:
	NormalBlock(const Vector2 &_pos, const float _width, const float _height, const int _hp,std::unique_ptr<Color> &_color);
	~NormalBlock();

	void update() override;			//更新
	void draw() const override;		//描画
	void collisionBall() override;	//ボールと衝突したときの処理
};