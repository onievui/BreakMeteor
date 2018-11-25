#include "ResourceManager.h"

ResourceManager::ResourceManager() {
	release();
}

void ResourceManager::load(const SceneID _id) {
	switch (_id) {
	case SCENE_LOGO:
		myLoadGraph(GRAPHIC_LOGO, "Resources/Textures/Protected/Logo.png");
		myLoadGraph(GRAPHIC_LOGO2, "Resources/Textures/Protected/Logo2.png");
		break;
	case SCENE_TITLE:
		myLoadGraph(GRAPHIC_TITLE, "Resources/Textures/Protected/Title.png");
		break;
	default:
		MessageBox(NULL, "“Ç‚İ‚İ‰æ‘œ‚Ì‘I‘ğ‚Å•s³‚È’l‚ª“n‚³‚ê‚Ü‚µ‚½", "", MB_OK);
		break;
	}
}

void ResourceManager::release() {
	images.clear();
	imagesIndex.fill(-1);
	sounds.clear();
	soundsIndex.fill(-1);
	musics.clear();
	musicsIndex.fill(-1);
}

HGRP ResourceManager::getGraphic(const GraphicID _id, const int _index) {
	int index = imagesIndex[_id];
	if (index == -1) {
		MessageBox(NULL, "‰æ‘œ‚Ìæ“¾‚Å•s³‚È’l‚ª“n‚³‚ê‚Ü‚µ‚½", "", MB_OK);
		return -1;
	}
	return *images[index].get()[_index];
}

HSND ResourceManager::getSound(const SoundID _id) {
	int index = soundsIndex[_id];
	if (index == -1) {
		MessageBox(NULL, "Œø‰Ê‰¹‚Ìæ“¾‚Å•s³‚È’l‚ª“n‚³‚ê‚Ü‚µ‚½", "", MB_OK);
		return -1;
	}
	return *sounds[index].get();
}

HSND ResourceManager::getMusic(const MusicID _id) {
	int index = musicsIndex[_id];
	if (index == -1) {
		MessageBox(NULL, "BGM‚Ìæ“¾‚Å•s³‚È’l‚ª“n‚³‚ê‚Ü‚µ‚½", "", MB_OK);
		return -1;
	}
	return *musics[index].get();
}

bool ResourceManager::myLoadGraph(const GraphicID _id, const char *_filename) {
	HGRP *image = new HGRP(LoadGraph(_filename));
	if (*image == -1) {
		MessageBox(NULL, "‰æ‘œ‚Ì“Ç‚İ‚İ‚É¸”s‚µ‚Ü‚µ‚½", "", MB_OK);
		return false;
	}
	imagesIndex[_id] = images.size();
	images.push_back(std::make_unique<HGRP*>(image));
	return true;
}

bool ResourceManager::myLoadDivGraph(const GraphicID _id, const char *_filename, const int _num, const int _xnum, const int _ynum, const int _width, const int _height) {
	std::unique_ptr<HGRP*> image;
	int success = LoadDivGraph(_filename, _num, _xnum, _ynum, _width, _height, *image.get());
	if (success == -1) {
		MessageBox(NULL, "‰æ‘œ‚Ì“Ç‚İ‚İ‚É¸”s‚µ‚Ü‚µ‚½", "", MB_OK);
		return false;
	}
	imagesIndex[_id] = images.size();
	images.push_back(std::move(image));
	return true;
}

bool ResourceManager::myLoadSoundMem(const SoundID _id, const char *_filename) {
	auto sound = std::make_unique<HSND>(LoadSoundMem(_filename));
	if (*sound.get() == -1) {
		MessageBox(NULL, "Œø‰Ê‰¹‚Ì“Ç‚İ‚İ‚É¸”s‚µ‚Ü‚µ‚½", "", MB_OK);
		return false;
	}
	soundsIndex[_id] = sounds.size();
	sounds.push_back(std::move(sound));
	return true;
}

bool ResourceManager::myLoadSoundMem(const MusicID _id, const char *_filename) {
	auto music = std::make_unique<HSND>(LoadSoundMem(_filename));
	if (*music.get() == -1) {
		MessageBox(NULL, "BGM‚Ì“Ç‚İ‚İ‚É¸”s‚µ‚Ü‚µ‚½", "", MB_OK);
		return false;
	}
	musicsIndex[_id] = musics.size();
	musics.push_back(std::move(music));
	return true;
}

