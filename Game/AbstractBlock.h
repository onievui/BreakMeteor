#pragma once

#include "Vector2.h"
#include "Color.h"
#include "Collider.h"
#include <memory>

class AbstractBlock {

protected:
	Vector2 pos;                            //中心座標
	Vector2 vel;							//速度
	float width;                            //横幅
	float height;                           //縦幅
	int hp;			                        //耐久力
	std::unique_ptr<Color> color;	        //色
	std::unique_ptr<RectCollider> collider; //当たり判定

public:
	AbstractBlock() = default;
	virtual ~AbstractBlock() = default;

	virtual void update() = 0;
	virtual void draw() const = 0;
	virtual bool collisionBall() = 0;
	RectCollider* getCollider() const;
};