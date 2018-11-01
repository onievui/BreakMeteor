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
	paddle = std::make_unique<Paddle>();
	ballManager = std::make_unique<BallManager>();
	blockManager = std::make_unique<BlockManager>();
}

/// <summary>
/// �V�[���̍X�V
/// </summary>
void PlayScene::update() {
	paddle->update();
	ballManager->update();
	blockManager->update();
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
