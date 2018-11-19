#pragma once

#include "Vector2.h"
#include "Collider.h"
#include "Color.h"
#include <memory>


//�p�h���N���X
class Paddle {
private:
	static const int DEFAULT_POS_X; //�p�h���̏���X���W
	static const int DEFAULT_POS_Y; //�p�h���̏���Y���W

	Vector2 pos;                                    //���W
	Vector2 vel;                                    //���x
	float angle;                                    //�p�x
	float rotateVel;                                //�p���x
	float width;		                            //����
	float height;		                            //�c��
	float speed;		                            //�ړ����x
	int score;										//�l���X�R�A
	bool isAlive;									//�����Ă��邩�ǂ���
	std::unique_ptr<RectRotateCollider> collider;	//�����蔻��
	std::unique_ptr<Color> color;                   //�p�h���̐F

public:
	Paddle();
	~Paddle() = default;

	void initialize();                            //������
	void update();                                //�X�V
	void draw() const;                            //�`��

	void onHitBall(const float _time);		      //�{�[���ƏՓ˂����Ƃ��̏���
	void onHitBlock();							  //�u���b�N�ƏՓ˂����Ƃ��̏���

	RectRotateCollider* getCollider() const;      //�����蔻��̎擾
	const Vector2& getPos() const;	              //���W�̎擾
	float getRotatedAngle() const;	              //��]��̊p�x�̎擾
	void cancelMove();							  //�ړ��𒆎~����
	void rotate();								  //��]������

	void addScore(const int _score);              //�X�R�A�̒ǉ�
	int getScore();								  //�X�R�A�̎擾
	bool checkIsAlive() const;					  //�u���b�N�ƏՓ˂��Ă��Ȃ����̊m�F

private:
	void move();	//�p�h���̈ړ�

	
};