#pragma once

#include "Paddle.h"
#include "AbstractBall.h"
#include "AbstractBlock.h"
#include <vector>


//当たり判定クラス
class Collision {

private:
	std::unique_ptr<Paddle> *paddle;						//パドルへのポインタ
	std::vector<std::unique_ptr<AbstractBall>> *balls;		//ボール配列へのポインタ
	std::vector<std::unique_ptr<AbstractBlock>> *blocks;	//ブロック配列へのポインタ

public:
	Collision();
	~Collision() = default;

	void update();	//更新

	void setPaddle(std::unique_ptr<Paddle> *_paddle);						//パドルのポインタの設定
	void setBalls(std::vector<std::unique_ptr<AbstractBall>> *_balls);		//ボール配列のポインタの設定
	void setBlocks(std::vector<std::unique_ptr<AbstractBlock>> *_blocks);	//ブロック配列のポインタの設定

};