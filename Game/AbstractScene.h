#pragma once

#include "RequestSceneListener.h"
#include <memory>




/// <summary>
/// シーンの抽象クラス
/// </summary>
class AbstractScene {

protected:
	//シーン切り替えインタフェース
	RequestSceneListener *implRequestScene;

public:
	AbstractScene() = default;
	//シーン切り替えインタフェースの登録
	AbstractScene(RequestSceneListener *_impl);
	virtual ~AbstractScene() = default;

	//シーンの初期化
	virtual void initialize() = 0;

	//シーンの更新
	virtual void update() = 0;

	//シーンの描画
	virtual void render() = 0;

	//シーンの終了処理
	virtual void finalize() = 0;
};