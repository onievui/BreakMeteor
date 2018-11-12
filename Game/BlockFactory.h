#pragma once

#include "AbstractBlock.h"
#include <memory>


//ブロックの種類
enum BLOCK_TYPE {
	NONE,
	NORMAL_RED,
	NORMAL_GREEN,
	NORMAL_BLUE,
	NORMAL_PINK,
	NORMAL_AQUA,
	NORMAL_GRAY_HP2,
	TYPE_NUM,
};


//ブロック生成クラス
class BlockFactroy {

public:
	BlockFactroy() = default;
	~BlockFactroy() = default;

	static std::unique_ptr<AbstractBlock> createBlock(const Vector2 &_pos, const BLOCK_TYPE _type);	//ブロックの生成

};