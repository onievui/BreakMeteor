#pragma once

#include "Singleton.h"
#include "SceneID.h"
#include <vector>
#include <array>



enum GraphicID {
	GRAPHIC_LOGO,
	GRAPHIC_LOGO2,
	GRAPHIC_TITLE,
	GRAPHIC_NUM
};



class ResourceManager final : public Singleton<ResourceManager> {

	friend Singleton<ResourceManager>;

private:
	std::vector<std::unique_ptr<HGRP*>> images;
	std::array<int, GRAPHIC_NUM> imagesIndex;


public:
	ResourceManager();
	~ResourceManager() = default;

public:
	void load(const SceneID _id);
	void release();
	HGRP getGraphic(const GraphicID _id, const int _index = 0);

private:
	bool myLoadGraph(const GraphicID _id, const char *_filename);
	bool myLoadDivGraph(const GraphicID _id, const char *_filename, const int _num, const int _xnum, const int _ynum, const int _width, const int _height);


};




