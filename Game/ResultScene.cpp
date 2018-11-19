#include "ResultScene.h"
#include "Pad.h"

/// <summary>
/// �V�[���؂�ւ��C���^�t�F�[�X�̓o�^
/// </summary>
/// <param name="_impl">���X�i�[�ւ̃|�C���^</param>
ResultScene::ResultScene(RequestSceneListener *_impl) 
	: AbstractScene(_impl) {
	initialize();
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
ResultScene::~ResultScene() {

}

/// <summary>
/// �V�[���̏�����
/// </summary>
void ResultScene::initialize() {

}

/// <summary>
/// �V�[���̍X�V
/// </summary>
void ResultScene::update() {
	if (Pad::getIns()->isDown(PadCode::SPACE)) {
		implRequestScene->requestScene(SCENE_TITLE);
	}
}


/// <summary>
/// �V�[���̕`��
/// </summary>
void ResultScene::render() {
	DrawFormatString(10, 10, COLOR_WHITE, "RESULT press Space");
}

/// <summary>
/// �V�[���̏I������
/// </summary>
void ResultScene::finalize() {
	
}

/// <summary>
/// �V�[����������
/// </summary>
/// <param name="_impl">�C���^�t�F�[�X�ւ̃|�C���^</param>
/// <returns>
/// �V�[���I�u�W�F�N�g
/// </returns>
std::unique_ptr<AbstractScene> ResultScene::create(RequestSceneListener * _impl) {
	return std::move(std::make_unique<ResultScene>(_impl));
}
