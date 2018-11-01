#include "PlayScene.h"


/// <summary>
/// シーン切り替えインタフェースの登録
/// </summary>
/// <param name="_impl">リスナーへのポインタ</param>
PlayScene::PlayScene(RequestSceneListener *_impl) 
	: AbstractScene(_impl) {
	initialize();
}

/// <summary>
/// デストラクタ
/// </summary>
PlayScene::~PlayScene() {
}

/// <summary>
/// シーンの初期化
/// </summary>
void PlayScene::initialize() {
	paddle = std::make_unique<Paddle>();
	ballManager = std::make_unique<BallManager>();
	blockManager = std::make_unique<BlockManager>();
}

/// <summary>
/// シーンの更新
/// </summary>
void PlayScene::update() {
	paddle->update();
	ballManager->update();
	blockManager->update();
}


/// <summary>
/// シーンの描画
/// </summary>
void PlayScene::render() {
	paddle->draw();
	ballManager->render();
	blockManager->render();
}

/// <summary>
/// シーンの終了処理
/// </summary>
void PlayScene::finalize() {
	
}
