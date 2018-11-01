#pragma once

#include "AbstractBlock.h"
#include <vector>
#include <memory>

class BlockManager {

private:
	const static int BLOCK_MAX = 24;

	std::vector<std::unique_ptr<AbstractBlock>> blocks;

public:
	BlockManager();
	~BlockManager();

	void update();

	void render() const;
};