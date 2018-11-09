#pragma once

#include "AbstractBlock.h"
#include "Collision.h"
#include <vector>
#include <memory>

class BlockManager {

private:
	std::vector<std::unique_ptr<AbstractBlock>> blocks;

public:
	BlockManager(std::unique_ptr<Collision> &_collision);
	~BlockManager();

	void update();
	void render() const;

};