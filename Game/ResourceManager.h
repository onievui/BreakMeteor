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

enum SoundID {
	SOUND_TEST,
	SOUND_NUM
};

enum MusicID {
	MUSIC_TEST,
	MUSIC_NUM
};



class ResourceManager final : public Singleton<ResourceManager> {

	friend Singleton<ResourceManager>;

private:
	std::vector<std::unique_ptr<HGRP*>> images;
	std::array<int, GRAPHIC_NUM> imagesIndex;
	std::vector<std::unique_ptr<HSND>> sounds;
	std::array<int, SOUND_NUM> soundsIndex;
	std::vector<std::unique_ptr<HSND>> musics;
	std::array<int, MUSIC_NUM> musicsIndex;


public:
	ResourceManager();
	~ResourceManager() = default;

public:
	void load(const SceneID _id);
	void release();
	HGRP getGraphic(const GraphicID _id, const int _index = 0);
	HSND getSound(const SoundID _id);
	HSND getMusic(const MusicID _id);

private:
	bool myLoadGraph(const GraphicID _id, const char *_filename);
	bool myLoadDivGraph(const GraphicID _id, const char *_filename, const int _num, const int _xnum, const int _ynum, const int _width, const int _height);

	bool myLoadSoundMem(const SoundID _id, const char *_filename);
	bool myLoadSoundMem(const MusicID _id, const char *_filename);

};




