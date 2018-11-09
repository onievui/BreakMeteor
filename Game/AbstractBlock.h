#pragma once

#include "Vector2.h"
#include "Color.h"
#include "Collider.h"
#include <memory>

class AbstractBlock {

protected:
	Vector2 pos;                            //���S���W
	Vector2 vel;							//���x
	float width;                            //����
	float height;                           //�c��
	int hp;			                        //�ϋv��
	std::unique_ptr<Color> color;	        //�F
	std::unique_ptr<RectCollider> collider; //�����蔻��

public:
	AbstractBlock() = default;
	virtual ~AbstractBlock() = default;

	virtual void update() = 0;
	virtual void draw() const = 0;
	virtual bool collisionBall() = 0;
	RectCollider* getCollider() const;
};