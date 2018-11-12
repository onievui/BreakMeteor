#pragma once

#include "BlockManager.h"
#include "BlockFactory.h"
#include "StageData.h"


using namespace StageData;

#include <assert.h>

BlockManager::BlockManager(std::unique_ptr<Collision> &_collision) {

	//�����蔻��p�ɔz��̃|�C���^��n��
	_collision->setBlocks(&blocks);

	Vector2 pos;
	//int STAGE_DATA2[][8] = STAGE_DATA2;
	int row = sizeof(STAGE_DATA2) / sizeof(STAGE_DATA2[0]);
	int column = sizeof(STAGE_DATA2[0]) / sizeof(STAGE_DATA2[0][0]);
	for (int i = 0; i < row*column; ++i) {
		BLOCK_TYPE type = (BLOCK_TYPE)STAGE_DATA2[i / column][i % column];
		pos.x = 40.0f + (i % column) * 80;
		pos.y = 40.0f + (i / column) * 20;
		//�󔒂Ȃ��΂�
		if (type == BLOCK_TYPE::NONE) {
			continue;
		}
		auto block = BlockFactroy::createBlock(pos, type);
		//�����Ɏ��s�������΂�
		if (block == nullptr) {
			continue;
		}
		blocks.emplace_back(std::move(block));
	}
}

BlockManager::~BlockManager() {

}

void BlockManager::update() {
	destroyCheck();
	for (const auto &block : blocks) {
		block->update();
	}
}

void BlockManager::render() const {
	for (const auto &block : blocks) {
		if (!block->isDestroyed()) {
			block->draw();
		}
	}
}

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

