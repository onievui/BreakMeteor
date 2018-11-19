#pragma once

#include "Vector2.h"
#include "Collider.h"
#include "Color.h"
#include <memory>


//パドルクラス
class Paddle {
private:
	static const int DEFAULT_POS_X; //パドルの初期X座標
	static const int DEFAULT_POS_Y; //パドルの初期Y座標

	Vector2 pos;                                    //座標
	Vector2 vel;                                    //速度
	float angle;                                    //角度
	float rotateVel;                                //角速度
	float width;		                            //横幅
	float height;		                            //縦幅
	float speed;		                            //移動速度
	std::unique_ptr<RectRotateCollider> collider;	//当たり判定
	std::unique_ptr<Color> color;                   //パドルの色

public:
	Paddle();
	~Paddle() = default;

	void initialize();                            //初期化
	void update();                                //更新
	void draw() const;                            //描画
	void onHitBall(const float _time);		      //ボールと衝突したときの処理
	void onHitBlock();							  //ブロックと衝突したときの処理
	RectRotateCollider* getCollider() const;      //当たり判定の取得
	const Vector2& getPos() const;	              //座標の取得
	float getRotatedAngle() const;	              //回転後の角度の取得
	void cancelMove();							  //移動を中止する
	void rotate();								  //回転させる

private:
	void move();	//パドルの移動

	
};