#pragma once

#include "BlockFactory.h"
#include "NormalBlock.h"
#include "RotateBlock.h"

/// <summary>
/// �u���b�N�̐���
/// </summary>
/// <param name="_pos">���W</param>
/// <param name="_type">���</param>
/// <returns>
/// �����F���������u���b�N
/// ���s�Fnullptr
/// </returns>
std::unique_ptr<AbstractBlock> BlockFactroy::createBlock(const Vector2 &_pos, const BlockType _type) {
	//�G���[�`�F�b�N
	if (_type <= BlockType::NONE || _type >= BlockType::TYPE_NUM) {
		MessageBox(NULL, "�u���b�N�̐����̌Ăяo���ŕs���Ȓl���n����܂���", "", MB_OK);
		return nullptr;
	}

	std::unique_ptr<AbstractBlock> block;
	std::unique_ptr<Color> color;

	switch (_type) {
	case NORMAL_RED:
		color = std::make_unique<RGBColor>(ColorCode::COLOR_RED);
		block = std::make_unique<NormalBlock>(_pos, 80.f, 20.f, 1, 100, color);
		break;
	case NORMAL_GREEN:
		color = std::make_unique<RGBColor>(ColorCode::COLOR_LIME);
		block = std::make_unique<NormalBlock>(_pos, 80.f, 20.f, 1, 100, color);
		break;
	case NORMAL_BLUE:
		color = std::make_unique<RGBColor>(ColorCode::COLOR_BLUE);
		block = std::make_unique<NormalBlock>(_pos, 80.f, 20.f, 1, 100, color);
		break;
	case NORMAL_PINK:
		color = std::make_unique<RGBColor>(ColorCode::COLOR_FUCHSIA);
		block = std::make_unique<NormalBlock>(_pos, 80.f, 20.f, 1, 100, color);
		break;
	case NORMAL_AQUA:
		color = std::make_unique<RGBColor>(ColorCode::COLOR_AQUA);
		block = std::make_unique<NormalBlock>(_pos, 80.f, 20.f, 1, 100, color);
		break;
	case NORMAL_GRAY_HP2:
		color = std::make_unique<RGBColor>(ColorCode::COLOR_GRAY);
		block = std::make_unique<NormalBlock>(_pos, 80.f, 20.f, 2, 150, color);
		break;
	case ROTATE_RED:
		color = std::make_unique<RGBColor>(ColorCode::COLOR_RED);
		block = std::make_unique<RotateBlock>(_pos, 80.f, 80.f, 1, 150, color);
		break;
	default:
		MessageBox(NULL, "�u���b�N�̐����ŕs���Ȓl���n����܂���", "", MB_OK);
		return nullptr;
		break;
	}

	return block;
}
