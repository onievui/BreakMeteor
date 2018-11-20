#pragma once

#include "AbstractBlock.h"
#include "Collision.h"
#include <vector>
#include <memory>


//ブロック管理クラス
class BlockManager {

private:
	static const int LEVEL_UP_SPEED;					//レベルが上がる間隔
	std::vector<std::unique_ptr<AbstractBlock>> blocks;	//管理するブロックの配列
	int count;											//経過フレーム数
	int level;											//難易度

public:
	BlockManager(std::unique_ptr<Collision> &_collision);
	~BlockManager();

	void update();			//更新
	void render() const;	//描画

private:
	void destroyCheck();	//壊れているブロックがあるかの確認
};