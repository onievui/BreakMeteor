#pragma once

#include "RequestSceneListener.h"
#include <memory>




/// <summary>
/// �V�[���̒��ۃN���X
/// </summary>
class AbstractScene {

protected:
	//�V�[���؂�ւ��C���^�t�F�[�X
	RequestSceneListener *implRequestScene;

public:
	AbstractScene() = default;
	//�V�[���؂�ւ��C���^�t�F�[�X�̓o�^
	AbstractScene(RequestSceneListener *_impl);
	virtual ~AbstractScene() = default;

	//�V�[���̏�����
	virtual void initialize() = 0;

	//�V�[���̍X�V
	virtual void update() = 0;

	//�V�[���̕`��
	virtual void render() = 0;

	//�V�[���̏I������
	virtual void finalize() = 0;
};