#include "LogoScene.h"
#include "Pad.h"

/// <summary>
/// シーン切り替えインタフェースの登録
/// </summary>
/// <param name="_impl">リスナーへのポインタ</param>
LogoScene::LogoScene(RequestSceneListener *_impl) 
	: AbstractScene(_impl) {
	initialize();
}

/// <summary>
/// デストラクタ
/// </summary>
LogoScene::~LogoScene() {

}

/// <summary>
/// シーンの初期化
/// </summary>
void LogoScene::initialize() {

}

/// <summary>
/// シーンの更新
/// </summary>
void LogoScene::update() {
	if (Pad::getIns()->isDown(PadCode::Z)) {
		implRequestScene->requestScene(SCENE_TITLE);
	}
}


/// <summary>
/// シーンの描画
/// </summary>
void LogoScene::render() {
	DrawFormatString(10, 10, COLOR_WHITE, "LOGO press Z");
}

/// <summary>
/// シーンの終了処理
/// </summary>
void LogoScene::finalize() {
	
}

/// <summary>
/// シーン生成処理
/// </summary>
/// <param name="_impl">インタフェースへのポインタ</param>
/// <returns>
/// シーンオブジェクト
/// </returns>
std::unique_ptr<AbstractScene> LogoScene::create(RequestSceneListener * _impl) {
	return std::move(std::make_unique<LogoScene>(_impl));
}
