#pragma once

#include "Vector2.h"



//パドルクラス
class Paddle {
private:
	const static int DEFAULT_POS_X = 320; //パドルの初期X座標
	const static int DEFAULT_POS_Y = 440; //パドルの初期Y座標

	Vector2 pos;        //座標
	Vector2 vel;        //速度
	float angle;        //角度
	float width;		//横幅
	float height;		//縦幅
	float speed;		//移動速度
	unsigned int color; //パドルの色

public:
	Paddle();
	~Paddle() = default;

	void initialize();

	void update();

	void draw() const;

private:
	//パドルの移動
	void move();


};