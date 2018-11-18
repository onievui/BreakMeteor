#pragma once

#include "BlockManager.h"
#include "BlockFactory.h"
#include "StageData.h"


using namespace StageData;


/// <summary>
/// コンストラクタ
/// ステージの生成
/// </summary>
/// <param name="_collision">当たり判定クラスの参照</param>
BlockManager::BlockManager(std::unique_ptr<Collision> &_collision) {

	//当たり判定用に配列のポインタを渡す
	_collision->setBlocks(&blocks);

	//カウントの初期化
	count = 0;

	//Vector2 pos;
	////int STAGE_DATA2[][8] = STAGE_DATA2;
	//int row = sizeof(STAGE_DATA2) / sizeof(STAGE_DATA2[0]);
	//int column = sizeof(STAGE_DATA2[0]) / sizeof(STAGE_DATA2[0][0]);
	//for (int i = 0; i < row*column; ++i) {
	//	BLOCK_TYPE type = (BLOCK_TYPE)STAGE_DATA2[i / column][i % column];
	//	pos.x = 40.0f + (i % column) * 80;
	//	pos.y = 40.0f + (i / column) * 20;
	//	//空白なら飛ばす
	//	if (type == BLOCK_TYPE::NONE) {
	//		continue;
	//	}
	//	auto block = BlockFactroy::createBlock(pos, type);
	//	//生成に失敗したら飛ばす
	//	if (block == nullptr) {
	//		continue;
	//	}
	//	blocks.emplace_back(std::move(block));
	//}
}

/// <summary>
/// デストラクタ
/// </summary>
BlockManager::~BlockManager() {

}

/// <summary>
/// 更新
/// </summary>
void BlockManager::update() {
	destroyCheck();
	for (const auto &block : blocks) {
		block->update();
	}

	if (count % 300 == 0) {
		Vector2 pos;
		BLOCK_TYPE type = BLOCK_TYPE(GetRand(5) + 1);
		for (int i = 0; i < 5; ++i) {
			pos.x = 56.f + i * 80.f;
			pos.y = -10.f;
			auto block = BlockFactroy::createBlock(pos, type);
			//生成に失敗したら飛ばす
			if (block == nullptr) {
				continue;
			}
			blocks.emplace_back(std::move(block));
		}
	}

	++count;
}

/// <summary>
/// 描画
/// </summary>
void BlockManager::render() const {
	for (const auto &block : blocks) {
		if (!block->isDestroyed()) {
			block->draw();
		}
	}
}

/// <summary>
/// 壊れているブロックがあるかの確認
/// </summary>
void BlockManager::destroyCheck() {
	auto it = blocks.begin();
	while (it != blocks.end()) {
		if (it->get()->isDestroyed()) {
			it = blocks.erase(it);
		}
		else {
			it++;
		}
	}
}

