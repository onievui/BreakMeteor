#pragma once

#include "AbstractScene.h"
#include "Paddle.h"
#include "BallManager.h"
#include "BlockManager.h"
#include "Collision.h"
#include <memory>



class PlayScene : public AbstractScene {

private:
	std::unique_ptr<Paddle> paddle;				//パドルオブジェクト
	std::unique_ptr<BallManager> ballManager;	//ボール管理オブジェクト
	std::unique_ptr<BlockManager> blockManager;	//ブロック管理オブジェクト
	std::unique_ptr<Collision> collision;		//当たり判定用オブジェクト

public:
	PlayScene(RequestSceneListener *_impl);
	~PlayScene();


	void initialize() override;	//初期化
	void update() override;	    //更新
	void render() override;	    //描画
	void finalize() override;	//終了処理

	static std::unique_ptr<AbstractScene> create(RequestSceneListener *_impl);	//シーン生成関数
};