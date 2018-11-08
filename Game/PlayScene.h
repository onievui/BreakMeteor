#pragma once

#include "AbstractScene.h"
#include "Paddle.h"
#include "BallManager.h"
#include "BlockManager.h"
#include "Collision.h"
#include <memory>



class PlayScene : public AbstractScene {

private:
	std::unique_ptr<Paddle> paddle;
	std::unique_ptr<BallManager> ballManager;
	std::unique_ptr<BlockManager> blockManager;
	std::unique_ptr<Collision> collision;

public:
	//シーン切り替えインタフェースの登録
	PlayScene(RequestSceneListener *_impl);
	~PlayScene();

	//初期化
	void initialize() override;

	//更新
	void update() override;

	//描画
	void render() override;

	//終了処理
	void finalize() override;
};