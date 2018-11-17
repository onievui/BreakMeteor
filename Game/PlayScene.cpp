#include "PlayScene.h"


/// <summary>
/// �V�[���؂�ւ��C���^�t�F�[�X�̓o�^
/// </summary>
/// <param name="_impl">���X�i�[�ւ̃|�C���^</param>
PlayScene::PlayScene(RequestSceneListener *_impl) 
	: AbstractScene(_impl) {
	initialize();
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
PlayScene::~PlayScene() {
}

/// <summary>
/// �V�[���̏�����
/// </summary>
void PlayScene::initialize() {
	collision = std::make_unique<Collision>();
	paddle = std::make_unique<Paddle>();
	collision->setPaddle(&paddle);
	ballManager = std::make_unique<BallManager>(collision);
	blockManager = std::make_unique<BlockManager>(collision);
}

/// <summary>
/// �V�[���̍X�V
/// </summary>
void PlayScene::update() {
	paddle->update();
	ballManager->update();
	blockManager->update();
	collision->update();
}


/// <summary>
/// �V�[���̕`��
/// </summary>
void PlayScene::render() {
	paddle->draw();
	ballManager->render();
	blockManager->render();
}

/// <summary>
/// �V�[���̏I������
/// </summary>
void PlayScene::finalize() {
	
}

/// <summary>
/// �V�[����������
/// </summary>
/// <param name="_impl">�C���^�t�F�[�X�ւ̃|�C���^</param>
/// <returns>
/// �V�[���I�u�W�F�N�g
/// </returns>
std::unique_ptr<AbstractScene> PlayScene::create(RequestSceneListener * _impl) {
	return std::move(std::make_unique<PlayScene>(_impl));
}
