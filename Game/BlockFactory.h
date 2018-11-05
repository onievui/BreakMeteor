#pragma once

#include "AbstractBlock.h"
#include <memory>



enum BLOCK_TYPE {
	NONE,
	NORMAL_RED,
	NORMAL_GREEN,
	NORMAL_BLUE,
	TYPE_NUM,
};



class BlockFactroy {

public:
	BlockFactroy() = default;
	~BlockFactroy() = default;

	static std::unique_ptr<AbstractBlock> createBlock(const Vector2 &_pos, const BLOCK_TYPE _type);


};