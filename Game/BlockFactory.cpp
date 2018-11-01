#pragma once

#include "BlockFactory.h"
#include "NormalBlock.h"



std::unique_ptr<AbstractBlock> BlockFactroy::createBlock(const Vector2 &_pos, const BLOCK_TYPE _type) {
	//�G���[�`�F�b�N
	if (_type <= BLOCK_TYPE::NONE || _type >= BLOCK_TYPE::TYPE_NUM) {
		MessageBox(NULL, "�u���b�N�̐����̌Ăяo���ŕs���Ȓl���n����܂���", "", MB_OK);
		return nullptr;
	}

	std::unique_ptr<AbstractBlock> block;

	switch (_type) {
	case NORMAL_RED:
		block = std::make_unique<NormalBlock>(_pos, 80, 20, 1, COLOR_RED);
		break;
	case NORMAL_GREEN:
		block = std::make_unique<NormalBlock>(_pos, 80, 20, 1, COLOR_GREEN);
		break;
	case NORMAL_BLUE:
		block = std::make_unique<NormalBlock>(_pos, 80, 20, 1, COLOR_BLUE);
		break;
	default:
		MessageBox(NULL, "�u���b�N�̐����ŕs���Ȓl���n����܂���", "", MB_OK);
		return nullptr;
		break;
	}

	return block;
}
