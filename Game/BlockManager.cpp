#pragma once

#include "BlockManager.h"
#include "BlockFactory.h"
#include "Field.h"
#include <algorithm>



const int BlockManager::LEVEL_UP_SPEED = 1200;


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

	//レベルの初期化
	level = 0;

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
	//ブロックが壊れていないか確認
	destroyCheck();
	//ブロックの更新
	for (const auto &block : blocks) {
		block->update();
	}

	//ノーマルブロックの生成
	if (count % (500 - 50 * (std::min)(level, 6)) == 0) {
		Vector2 pos;
		BlockType type = BlockType(GetRand(5) + 1);
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

	//回転ブロックの生成
	if (level > 1 && count % (300 - 20 * (std::min)(level - 2, 5)) == 0) {
		Vector2 pos;
		BlockType type = BlockType::ROTATE_RED;
		pos.x = float(FIELD::WIDTH * 3 / 5 * GetRand(10000) / 10000 + (FIELD::LEFT + FIELD::WIDTH / 5));
		pos.y = -10.f;
		auto block = BlockFactroy::createBlock(pos, type);
		if (block != nullptr) {
			blocks.emplace_back(std::move(block));
		}
	}


	//難易度の調整
	if (count % LEVEL_UP_SPEED == 0) {
		level++;
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

