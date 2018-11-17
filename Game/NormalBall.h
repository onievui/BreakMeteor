#pragma once

#include "AbstractBall.h"


//ノーマルボールクラス
class NormalBall : public AbstractBall {
	
private:
	void collisionWall();	//壁と衝突したときの処理
	
public:
	NormalBall();
	~NormalBall();

	void update() override;	                                                                            //更新
	void draw() const override;                                                                         //描画
	void reflect(const float _time, const float _ref_surface, const float _hit_pos_x = -1.f) override;	//反射

private:
	void regulateAngle();	//角度の調整
};