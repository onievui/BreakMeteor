#pragma once

#include "Vector2.h"
#include "Color.h"
#include "Collider.h"
#include <memory>

//ブロックの抽象クラス
class AbstractBlock {

protected:
	Vector2 pos;                                  //中心座標
	Vector2 vel;							      //速度
	float angle;								  //角度
	float width;                                  //横幅
	float height;                                 //縦幅
	int hp;			                              //耐久力
	int score;									  //スコア
	bool isValid;							      //存在するか
	std::unique_ptr<Color> color;	              //色
	std::unique_ptr<RectRotateCollider> collider; //当たり判定

public:
	AbstractBlock() = default;
	AbstractBlock(const Vector2 &_pos, const float _width, const float _height, const int _hp, const int _score);
	virtual ~AbstractBlock() = default;

	virtual void update() = 0;			        //更新
	virtual void draw() const = 0;		        //描画
	virtual void onHitBall(float _time) = 0;	//ボールとの衝突処理
	RectRotateCollider* getCollider() const;	//当たり判定の取得
	virtual int getScore() const = 0;			//スコアの取得
	bool isDestroyed() const;			        //存在するかどうか
};