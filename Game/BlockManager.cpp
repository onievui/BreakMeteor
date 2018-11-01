#pragma once

#include "BlockManager.h"
#include "BlockFactory.h"


using namespace StageData;

BlockManager::BlockManager() {
	Vector2 pos;
	int row = sizeof(STAGE_DATA1) / sizeof(STAGE_DATA1[0]);
	int column = sizeof(STAGE_DATA1[0]) / sizeof(STAGE_DATA1[0][0]);
	for (int i = 0; i < row*column; ++i) {
		BLOCK_TYPE type = (BLOCK_TYPE)STAGE_DATA1[i / column][i % column];
		pos.x = 40.0f + (i % column) * 80;
		pos.y = 40.0f + (i / column) * 20;
		//‹ó”’‚È‚ç”ò‚Î‚·
		if (type == BLOCK_TYPE::NONE) {
			continue;
		}
		auto block = BlockFactroy::createBlock(pos, type);
		//¶¬‚ÉŽ¸”s‚µ‚½‚ç”ò‚Î‚·
		if (block == nullptr) {
			continue;
		}
		blocks.push_back(std::move(block));
	}
}

BlockManager::~BlockManager() {

}

void BlockManager::update() {
	for (const auto &block : blocks) {
		block->update();
	}
}

void BlockManager::render() const {
	for (const auto &block : blocks) {
		block->draw();
	}
}
