#include "TitleScene.h"
#include "Pad.h"

/// <summary>
/// シーン切り替えインタフェースの登録
/// </summary>
/// <param name="_impl">リスナーへのポインタ</param>
TitleScene::TitleScene(RequestSceneListener *_impl) 
	: AbstractScene(_impl) {
	initialize();
}

/// <summary>
/// デストラクタ
/// </summary>
TitleScene::~TitleScene() {

}

/// <summary>
/// シーンの初期化
/// </summary>
void TitleScene::initialize() {

}

/// <summary>
/// シーンの更新
/// </summary>
void TitleScene::update() {
	if (Pad::getIns()->isDown(PadCode::Z)) {
		implRequestScene->requestScene(SCENE_PLAY);
	}
}


/// <summary>
/// シーンの描画
/// </summary>
void TitleScene::render() {
	DrawFormatString(10, 10, COLOR_WHITE, "TITLE press Z");
}

/// <summary>
/// シーンの終了処理
/// </summary>
void TitleScene::finalize() {
	
}

/// <summary>
/// シーン生成処理
/// </summary>
/// <param name="_impl">インタフェースへのポインタ</param>
/// <returns>
/// シーンオブジェクト
/// </returns>
std::unique_ptr<AbstractScene> TitleScene::create(RequestSceneListener * _impl) {
	return std::move(std::make_unique<TitleScene>(_impl));
}
