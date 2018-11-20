#pragma once

#include "AbstractBlock.h"


//ムーブブロッククラス
class MoveBlock : public AbstractBlock {

private:
	float moveSpeed;	//移動速度
	bool faceLeft;		//左向きかどうか

public:
	MoveBlock(const Vector2 &_pos, const float _width, const float _height, const int _hp, const int _score, std::unique_ptr<Color> &_color);
	~MoveBlock();

	void update() override;			        //更新
	void draw() const override;		        //描画
	void onHitBall(float _time) override;	//ボールと衝突したときの処理
	int getScore() const override;			//スコアの取得

private:
	void collisionWall();		//壁との当たり判定
};