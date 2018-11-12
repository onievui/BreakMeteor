#pragma once

#include "Vector2.h"
#include "Collider.h"
#include "Color.h"
#include <memory>


//パドルクラス
class Paddle {
private:
	const static int DEFAULT_POS_X = 320; //パドルの初期X座標
	const static int DEFAULT_POS_Y = 440; //パドルの初期Y座標

	Vector2 pos;                            //座標
	Vector2 vel;                            //速度
	float angle;                            //角度
	float width;		                    //横幅
	float height;		                    //縦幅
	float speed;		                    //移動速度
	std::unique_ptr<RectCollider> collider;	//当たり判定
	std::unique_ptr<Color> color;           //パドルの色

public:
	Paddle();
	~Paddle() = default;

	void initialize();                      //初期化
	void update();                          //更新
	void draw() const;                      //描画
	void collisionBall(const float _time);	//ボールと衝突したときの処理
	RectCollider* getCollider() const;      //当たり判定の取得

private:
	void move();	//パドルの移動

	
};