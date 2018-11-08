#pragma once

#include "Vector2.h"
#include "Collider.h"
#include "Color.h"
#include <memory>



//�p�h���N���X
class Paddle {
private:
	const static int DEFAULT_POS_X = 320; //�p�h���̏���X���W
	const static int DEFAULT_POS_Y = 440; //�p�h���̏���Y���W

	Vector2 pos;                            //���W
	Vector2 vel;                            //���x
	float angle;                            //�p�x
	float width;		                    //����
	float height;		                    //�c��
	float speed;		                    //�ړ����x
	std::unique_ptr<RectCollider> collider;	//�����蔻��
	std::unique_ptr<Color> color;           //�p�h���̐F

public:
	Paddle();
	~Paddle() = default;

	void initialize();
	void update();
	void draw() const;
	RectCollider* getCollider() const;

private:
	//�p�h���̈ړ�
	void move();

	
};