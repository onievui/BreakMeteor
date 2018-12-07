#include "PlayScene.h"
#include "ShareDataManager.h"
#include "ResourceManager.h"
#include "Sound.h"

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
	ResourceManager::getIns()->load(SCENE_PLAY);
	SoundPlayer::getIns()->reset();
	collision = std::make_unique<Collision>();
	paddle = std::make_unique<Paddle>();
	collision->setPaddle(&paddle);
	ballManager = std::make_unique<BallManager>(collision);
	blockManager = std::make_unique<BlockManager>(collision);
	SetFontSize(20);
}

/// <summary>
/// シーンの更新
/// </summary>
void PlayScene::update() {
	paddle->update();
	ballManager->update();
	blockManager->update();
	collision->update();

	if (!paddle->checkIsAlive()) {
		ShareDataManager::getIns()->setScore(paddle->getScore());
		implRequestScene->requestScene(SCENE_RESULT);
	}
}


/// <summary>
/// シーンの描画
/// </summary>
void PlayScene::render() {
	ballManager->render();
	blockManager->render();
	paddle->draw();
}

/// <summary>
/// シーンの終了処理
/// </summary>
void PlayScene::finalize() {
	ResourceManager::getIns()->release();
	SoundPlayer::getIns()->stopAll();
	SoundPlayer::getIns()->reset();
}

/// <summary>
/// シーン生成処理
/// </summary>
/// <param name="_impl">インタフェースへのポインタ</param>
/// <returns>
/// シーンオブジェクト
/// </returns>
std::unique_ptr<AbstractScene> PlayScene::create(RequestSceneListener * _impl) {
	return std::move(std::make_unique<PlayScene>(_impl));
}
