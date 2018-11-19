#pragma once

#include "BlockFactory.h"
#include "NormalBlock.h"
#include "RotateBlock.h"

/// <summary>
/// ブロックの生成
/// </summary>
/// <param name="_pos">座標</param>
/// <param name="_type">種類</param>
/// <returns>
/// 成功：生成したブロック
/// 失敗：nullptr
/// </returns>
std::unique_ptr<AbstractBlock> BlockFactroy::createBlock(const Vector2 &_pos, const BlockType _type) {
	//エラーチェック
	if (_type <= BlockType::NONE || _type >= BlockType::TYPE_NUM) {
		MessageBox(NULL, "ブロックの生成の呼び出しで不正な値が渡されました", "", MB_OK);
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
		MessageBox(NULL, "ブロックの生成で不正な値が渡されました", "", MB_OK);
		return nullptr;
		break;
	}

	return block;
}
