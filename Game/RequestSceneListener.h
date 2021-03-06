#pragma once

#include "SceneID.h"


class RequestSceneListener {

public:
	RequestSceneListener() = default;
	virtual ~RequestSceneListener() = default;

	//シーンの切り替え要求
	virtual void requestScene(const SceneID _id) = 0;
};