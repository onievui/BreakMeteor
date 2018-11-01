//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   GameLib.h
//!
//! @brief  ゲーム制作用ライブラリのヘッダファイル
//!
//! @date   2018/10/20
//!
//! @author S.Takaki
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// 多重インクルードの防止 ==================================================
#pragma once




// ヘッダファイルの読み込み ================================================
#include <DxLib.h>

#include "GameLibAudio.h"
#include "GameLibCollision.h"
#include "GameLibGraphics.h"
#include "GameLibInput.h"
#include "GameLibMath.h"
#include "GameLibScreen.h"
#include "GameLibSystem.h"
#include "GameLibTime.h"




// 型の定義 ================================================================
typedef int HGRP;    // グラフィックハンドル     
typedef int HSND;    // サウンドハンドル
typedef int HFNT;    // フォントハンドル
typedef int HNET;    // ネットワークハンドル 
