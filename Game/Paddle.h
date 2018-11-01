#pragma once

#include "Vector2.h"



//�p�h���N���X
class Paddle {
private:
	const static int DEFAULT_POS_X = 320; //�p�h���̏���X���W
	const static int DEFAULT_POS_Y = 440; //�p�h���̏���Y���W

	Vector2 pos;        //���W
	Vector2 vel;        //���x
	float angle;        //�p�x
	float width;		//����
	float height;		//�c��
	float speed;		//�ړ����x
	unsigned int color; //�p�h���̐F

public:
	Paddle();
	~Paddle() = default;

	void initialize();

	void update();

	void draw() const;

private:
	//�p�h���̈ړ�
	void move();


};