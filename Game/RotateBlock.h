#pragma once

#include "AbstractBlock.h"


//回転ブロッククラス
class RotateBlock : public AbstractBlock {

private:
	float rotateSpeed;			//回転スピード

public:
	RotateBlock(const Vector2 &_pos, const float _width, const float _height, const int _hp, const int _score, std::unique_ptr<Color> &_color);
	~RotateBlock();

	void update() override;			        //更新
	void draw() const override;		        //描画
	void onHitBall(float _time) override;	//ボールと衝突したときの処理
	int getScore() const override;				//スコアの取得
};