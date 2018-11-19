#pragma once

#include "BlockManager.h"
#include "BlockFactory.h"
#include "Field.h"



/// <summary>
/// �R���X�g���N�^
/// �X�e�[�W�̐���
/// </summary>
/// <param name="_collision">�����蔻��N���X�̎Q��</param>
BlockManager::BlockManager(std::unique_ptr<Collision> &_collision) {

	//�����蔻��p�ɔz��̃|�C���^��n��
	_collision->setBlocks(&blocks);

	//�J�E���g�̏�����
	count = 0;

}

/// <summary>
/// �f�X�g���N�^
/// </summary>
BlockManager::~BlockManager() {

}

/// <summary>
/// �X�V
/// </summary>
void BlockManager::update() {
	destroyCheck();
	for (const auto &block : blocks) {
		block->update();
	}

	if (count % 400 == 0) {
		Vector2 pos;
		BlockType type = BlockType(GetRand(5) + 1);
		for (int i = 0; i < 5; ++i) {
			pos.x = 56.f + i * 80.f;
			pos.y = -10.f;
			auto block = BlockFactroy::createBlock(pos, type);
			//�����Ɏ��s�������΂�
			if (block == nullptr) {
				continue;
			}
			blocks.emplace_back(std::move(block));
		}
	}

	if (count % 150 == 0) {
		Vector2 pos;
		BlockType type = BlockType::ROTATE_RED;
		pos.x = float(FIELD::WIDTH*(GetRand(3) + 1) / 5 + FIELD::LEFT);
		pos.y = -10.f;
		auto block = BlockFactroy::createBlock(pos, type);
		if (block != nullptr) {
			blocks.emplace_back(std::move(block));
		}
	}

	++count;
}

/// <summary>
/// �`��
/// </summary>
void BlockManager::render() const {
	for (const auto &block : blocks) {
		if (!block->isDestroyed()) {
			block->draw();
		}
	}
}

/// <summary>
/// ���Ă���u���b�N�����邩�̊m�F
/// </summary>
void BlockManager::destroyCheck() {
	auto it = blocks.begin();
	while (it != blocks.end()) {
		if (it->get()->isDestroyed()) {
			it = blocks.erase(it);
		}
		else {
			it++;
		}
	}
}

