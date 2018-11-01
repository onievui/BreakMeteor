#pragma once

#include "AbstractBlock.h"
#include "StageData.h"
#include <memory>





class BlockFactroy {

public:
	BlockFactroy() = default;
	~BlockFactroy() = default;

	static std::unique_ptr<AbstractBlock> createBlock(const Vector2 &_pos, const BLOCK_TYPE _type);


};