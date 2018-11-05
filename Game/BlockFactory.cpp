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
	std::unique_ptr<Color> color;

	switch (_type) {
	case NORMAL_RED:
		color = std::make_unique<RGBColor>(0, 0, 0);
		color->setColor(ColorCode::COLOR_RED);
		block = std::make_unique<NormalBlock>(_pos, 80.f, 20.f, 1, color);
		break;
	case NORMAL_GREEN:
		color = std::make_unique<RGBColor>(0, 0, 0);
		color->setColor(ColorCode::COLOR_GREEN);
		block = std::make_unique<NormalBlock>(_pos, 80.f, 20.f, 1, color);
		break;
	case NORMAL_BLUE:
		color = std::make_unique<RGBColor>(0, 0, 0);
		color->setColor(ColorCode::COLOR_BLUE);
		block = std::make_unique<NormalBlock>(_pos, 80.f, 20.f, 1, color);
		break;
	default:
		MessageBox(NULL, "�u���b�N�̐����ŕs���Ȓl���n����܂���", "", MB_OK);
		return nullptr;
		break;
	}

	return block;
}
