#pragma once

#include "AbstractScene.h"
#include "Paddle.h"
#include "BallManager.h"
#include "BlockManager.h"
#include "Collision.h"
#include <memory>



class PlayScene : public AbstractScene {

private:
	std::unique_ptr<Paddle> paddle;
	std::unique_ptr<BallManager> ballManager;
	std::unique_ptr<BlockManager> blockManager;
	std::unique_ptr<Collision> collision;

public:
	//�V�[���؂�ւ��C���^�t�F�[�X�̓o�^
	PlayScene(RequestSceneListener *_impl);
	~PlayScene();

	//������
	void initialize() override;

	//�X�V
	void update() override;

	//�`��
	void render() override;

	//�I������
	void finalize() override;
};