#include "LogoScene.h"
#include "Pad.h"

/// <summary>
/// �V�[���؂�ւ��C���^�t�F�[�X�̓o�^
/// </summary>
/// <param name="_impl">���X�i�[�ւ̃|�C���^</param>
LogoScene::LogoScene(RequestSceneListener *_impl) 
	: AbstractScene(_impl) {
	initialize();
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
LogoScene::~LogoScene() {

}

/// <summary>
/// �V�[���̏�����
/// </summary>
void LogoScene::initialize() {

}

/// <summary>
/// �V�[���̍X�V
/// </summary>
void LogoScene::update() {
	if (Pad::getIns()->isDown(PadCode::Z)) {
		implRequestScene->requestScene(SCENE_TITLE);
	}
}


/// <summary>
/// �V�[���̕`��
/// </summary>
void LogoScene::render() {
	DrawFormatString(10, 10, COLOR_WHITE, "LOGO press Z");
}

/// <summary>
/// �V�[���̏I������
/// </summary>
void LogoScene::finalize() {
	
}

/// <summary>
/// �V�[����������
/// </summary>
/// <param name="_impl">�C���^�t�F�[�X�ւ̃|�C���^</param>
/// <returns>
/// �V�[���I�u�W�F�N�g
/// </returns>
std::unique_ptr<AbstractScene> LogoScene::create(RequestSceneListener * _impl) {
	return std::move(std::make_unique<LogoScene>(_impl));
}
