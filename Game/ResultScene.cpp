#include "ResultScene.h"
#include "Pad.h"

/// <summary>
/// シーン切り替えインタフェースの登録
/// </summary>
/// <param name="_impl">リスナーへのポインタ</param>
ResultScene::ResultScene(RequestSceneListener *_impl) 
	: AbstractScene(_impl) {
	initialize();
}

/// <summary>
/// デストラクタ
/// </summary>
ResultScene::~ResultScene() {

}

/// <summary>
/// シーンの初期化
/// </summary>
void ResultScene::initialize() {

}

/// <summary>
/// シーンの更新
/// </summary>
void ResultScene::update() {
	if (Pad::getIns()->isDown(PadCode::SPACE)) {
		implRequestScene->requestScene(SCENE_TITLE);
	}
}


/// <summary>
/// シーンの描画
/// </summary>
void ResultScene::render() {
	DrawFormatString(10, 10, COLOR_WHITE, "RESULT press Space");
}

/// <summary>
/// シーンの終了処理
/// </summary>
void ResultScene::finalize() {
	
}

/// <summary>
/// シーン生成処理
/// </summary>
/// <param name="_impl">インタフェースへのポインタ</param>
/// <returns>
/// シーンオブジェクト
/// </returns>
std::unique_ptr<AbstractScene> ResultScene::create(RequestSceneListener * _impl) {
	return std::move(std::make_unique<ResultScene>(_impl));
}
