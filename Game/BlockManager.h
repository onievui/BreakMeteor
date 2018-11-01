#pragma once

#include "AbstractBlock.h"
#include <vector>
#include <memory>

class BlockManager {

private:
	std::vector<std::unique_ptr<AbstractBlock>> blocks;

public:
	BlockManager();
	~BlockManager();

	void update();

	void render() const;
};