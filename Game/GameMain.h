#pragma once

#include "AbstractScene.h"
#include <memory>



// �萔�̒�` ==============================================================
// <�V�X�e��> ----------------------------------------------------------
const char* const GAME_TITLE = "Break Meteor";    // �Q�[���^�C�g��


// <���> --------------------------------------------------------------
const int SCREEN_WIDTH    = 432;    // ��ʂ̕�[pixel]
const int SCREEN_HEIGHT   = 768;    // ��ʂ̍���[pixel]

const int SCREEN_TOP      = 0;                    // ��ʂ̏�[
const int SCREEN_BOTTOM   = SCREEN_HEIGHT;        // ��ʂ̉��[
const int SCREEN_LEFT     = 0;                    // ��ʂ̍��[
const int SCREEN_RIGHT    = SCREEN_WIDTH;         // ��ʂ̉E�[

const int SCREEN_CENTER_X = SCREEN_WIDTH  / 2;    // ��ʂ̒���(X���W)
const int SCREEN_CENTER_Y = SCREEN_HEIGHT / 2;    // ��ʂ̒���(Y���W)




/// <summary>
/// �Q�[���N���X
/// </summary>
class Game : public RequestSceneListener {

private:
	using SceneFactoryMethod = std::unique_ptr<AbstractScene>(*)(RequestSceneListener *_impl);	//�V�[�������֐�

	std::unique_ptr<AbstractScene> nowScene;	                //���݂̃V�[��
	SceneID nextScene;							                //���Ɏ��s����V�[��
	SceneFactoryMethod sceneFactoryMethods[SceneID::SCENE_NUM];	//�V�[�������֐��̃|�C���^

public:
	Game();
	~Game();

	void changeScene();	//�V�[���؂�ւ�

public:
	void initialize(void);
	void update(void);
	void render(void);
	void finalize(void);

	void requestScene(const SceneID _id) override; 	//�V�[���؂�ւ��v��

private:
	void addScene(const SceneID _id, SceneFactoryMethod _scene_factory_method);
};
