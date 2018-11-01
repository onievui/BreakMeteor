#pragma once

#include "BlockManager.h"
#include "NormalBlock.h"



BlockManager::BlockManager() {
	unsigned int color;
	for (int i = 0; i < 24; ++i) {
		switch (i/8) {
		case 0:  color = COLOR_RED;   break;
		case 1:  color = COLOR_GREEN; break;
		case 2:  color = COLOR_BLUE;  break;
		default: color = COLOR_WHITE; break;
		}

		blocks.emplace_back(std::make_unique<NormalBlock>(Vector2{ 40.0f + (i%8) * 80,40.0f + (i/8) * 20 }, 80, 20, 1, color));
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
