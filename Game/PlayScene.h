#pragma once

#include "AbstractScene.h"
#include "Paddle.h"
#include "BallManager.h"
#include "BlockManager.h"
#include "Collision.h"
#include <memory>



class PlayScene : public AbstractScene {

private:
	std::unique_ptr<Paddle> paddle;				//�p�h���I�u�W�F�N�g
	std::unique_ptr<BallManager> ballManager;	//�{�[���Ǘ��I�u�W�F�N�g
	std::unique_ptr<BlockManager> blockManager;	//�u���b�N�Ǘ��I�u�W�F�N�g
	std::unique_ptr<Collision> collision;		//�����蔻��p�I�u�W�F�N�g

public:
	PlayScene(RequestSceneListener *_impl);
	~PlayScene();


	void initialize() override;	//������
	void update() override;	    //�X�V
	void render() override;	    //�`��
	void finalize() override;	//�I������

	static std::unique_ptr<AbstractScene> create(RequestSceneListener *_impl);	//�V�[�������֐�
};