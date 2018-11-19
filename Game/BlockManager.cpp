#pragma once

#include "BlockManager.h"
#include "BlockFactory.h"
#include "Field.h"



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

	if (count % 400 == 0) {
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

	if (count % 150 == 0) {
		Vector2 pos;
		BlockType type = BlockType::ROTATE_RED;
		pos.x = float(FIELD::WIDTH*(GetRand(3) + 1) / 5 + FIELD::LEFT);
		pos.y = -10.f;
		auto block = BlockFactroy::createBlock(pos, type);
		if (block != nullptr) {
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

