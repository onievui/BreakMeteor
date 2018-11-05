#pragma once

#include "BlockManager.h"
#include "BlockFactory.h"
#include "StageData.h"


using namespace StageData;

#include <assert.h>

BlockManager::BlockManager() {
	Vector2 pos;
	//int STAGE_DATA2[][8] = STAGE_DATA2;
	int row = sizeof(STAGE_DATA2) / sizeof(STAGE_DATA2[0]);
	int column = sizeof(STAGE_DATA2[0]) / sizeof(STAGE_DATA2[0][0]);
	for (int i = 0; i < row*column; ++i) {
		BLOCK_TYPE type = (BLOCK_TYPE)STAGE_DATA2[i / column][i % column];
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
		blocks.emplace_back(std::move(block));
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
