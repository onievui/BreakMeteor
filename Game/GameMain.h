#pragma once

#include "AbstractScene.h"
#include <memory>



// 定数の定義 ==============================================================
// <システム> ----------------------------------------------------------
const char* const GAME_TITLE = "Break Meteor";    // ゲームタイトル


// <画面> --------------------------------------------------------------
const int SCREEN_WIDTH    = 432;    // 画面の幅[pixel]
const int SCREEN_HEIGHT   = 768;    // 画面の高さ[pixel]

const int SCREEN_TOP      = 0;                    // 画面の上端
const int SCREEN_BOTTOM   = SCREEN_HEIGHT;        // 画面の下端
const int SCREEN_LEFT     = 0;                    // 画面の左端
const int SCREEN_RIGHT    = SCREEN_WIDTH;         // 画面の右端

const int SCREEN_CENTER_X = SCREEN_WIDTH  / 2;    // 画面の中央(X座標)
const int SCREEN_CENTER_Y = SCREEN_HEIGHT / 2;    // 画面の中央(Y座標)




/// <summary>
/// ゲームクラス
/// </summary>
class Game : public RequestSceneListener {

private:
	using SceneFactoryMethod = std::unique_ptr<AbstractScene>(*)(RequestSceneListener *_impl);	//シーン生成関数

	std::unique_ptr<AbstractScene> nowScene;	                //現在のシーン
	SceneID nextScene;							                //次に実行するシーン
	SceneFactoryMethod sceneFactoryMethods[SceneID::SCENE_NUM];	//シーン生成関数のポインタ

public:
	Game();
	~Game();

	void changeScene();	//シーン切り替え

public:
	void initialize(void);
	void update(void);
	void render(void);
	void finalize(void);

	void requestScene(const SceneID _id) override; 	//シーン切り替え要求

private:
	void addScene(const SceneID _id, SceneFactoryMethod _scene_factory_method);
};
