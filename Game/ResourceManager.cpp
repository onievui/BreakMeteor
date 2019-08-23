#include "ResourceManager.h"
#include "Resource.h"

ResourceManager::ResourceManager() {
	release();
}

void ResourceManager::load(const SceneID _id) {
	switch (_id) {
	case SCENE_LOGO:
		addTexture(TEXTURE_LOGO, std::make_shared<TextureResource>("Protected/Logo.png"));
		addTexture(TEXTURE_LOGO2, std::make_shared<TextureResource>("Protected/Logo2.png"));
		break;
	case SCENE_TITLE:
		addTexture(TEXTURE_TITLE, std::make_shared<TextureResource>("Protected/Title.png"));
		addMusic(MUSIC_BGM, std::make_shared<AudioResource>("Protected/Fight_in_the_outer_space.mp3"));
		break;
	case SCENE_PLAY:
		addSound(SOUND_REFLECT, std::make_shared<AudioResource>("Protected/reflect.ogg"));
		addSound(SOUND_DESTROY, std::make_shared<AudioResource>("Protected/explosion.mp3"));
		addMusic(MUSIC_BGM, std::make_shared<AudioResource>("Protected/Fight_in_the_outer_space.mp3"));
		break;
	case SCENE_RESULT:
		break;
	default:
		MessageBox(NULL, "読み込みデータの選択で不正な値が渡されました", "", MB_OK);
		break;
	}
}

void ResourceManager::release() {
	textures.clear();
	textures.shrink_to_fit();
	texturesIndex.fill(-1);
	sounds.clear();
	sounds.shrink_to_fit();
	soundsIndex.fill(-1);
	musics.clear();
	musics.shrink_to_fit();
	musicsIndex.fill(-1);
	movies.clear();
	movies.shrink_to_fit();
	moviesIndex.fill(-1);
	fonts.clear();
	fonts.shrink_to_fit();
	fontsIndex.fill(-1);
}

std::shared_ptr<TextureResource> ResourceManager::getTexture(const TextureID _id) {
	int index = texturesIndex[_id];
	if (index == -1) {
		MessageBox(NULL, "画像の取得で不正な値が渡されました", "", MB_OK);
		return nullptr;
	}
	return textures[index];
}

std::shared_ptr<AudioResource> ResourceManager::getSound(const SoundID _id) {
	int index = soundsIndex[_id];
	if (index == -1) {
		MessageBox(NULL, "効果音の取得で不正な値が渡されました", "", MB_OK);
		return nullptr;
	}
	return sounds[index];
}

std::shared_ptr<AudioResource> ResourceManager::getMusic(const MusicID _id) {
	int index = musicsIndex[_id];
	if (index == -1) {
		MessageBox(NULL, "BGMの取得で不正な値が渡されました", "", MB_OK);
		return nullptr;
	}
	return musics[index];
}

std::shared_ptr<MovieResource> ResourceManager::getMovie(const MovieID _id) {
	int index = moviesIndex[_id];
	if (index == -1) {
		MessageBox(NULL, "動画の取得で不正な値が渡されました", "", MB_OK);
		return nullptr;
	}
	return movies[index];
}

std::shared_ptr<FontResource> ResourceManager::getFontHandle(const FontID _id) {
	int index = fontsIndex[_id];
	if (index == -1) {
		MessageBox(NULL, "フォントハンドルの取得で不正な値が渡されました", "", MB_OK);
		return nullptr;
	}
	return fonts[index];
}

bool ResourceManager::addTexture(const TextureID _id, const std::shared_ptr<TextureResource> _texture) {
	if (!_texture->isValid()) {
		MessageBox(NULL, "画像の読み込みに失敗しました", "", MB_OK);
		return false;
	}
	texturesIndex[_id] = textures.size();
	textures.emplace_back(_texture);
	return true;
}

bool ResourceManager::addSound(const SoundID _id, const std::shared_ptr<AudioResource>& _sound) {
	if (!_sound->isValid()) {
		MessageBox(NULL, "効果音の読み込みに失敗しました", "", MB_OK);
		return false;
	}
	soundsIndex[_id] = sounds.size();
	sounds.emplace_back(_sound);
	return true;
}

bool ResourceManager::addMusic(const MusicID _id, const std::shared_ptr<AudioResource>& _music) {
	if (!_music->isValid()) {
		MessageBox(NULL, "BGMの読み込みに失敗しました", "", MB_OK);
		return false;
	}
	musicsIndex[_id] = musics.size();
	musics.emplace_back(_music);
	return true;
}

bool ResourceManager::addMovie(const MovieID _id, const std::shared_ptr<MovieResource>& _movie) {
	if (!_movie->isValid()) {
		MessageBox(NULL, "BGMの読み込みに失敗しました", "", MB_OK);
		return false;
	}
	moviesIndex[_id] = movies.size();
	movies.emplace_back(_movie);
	return true;
}

bool ResourceManager::addFont(const FontID _id, const std::shared_ptr<FontResource>& _font) {
	if (!_font->isValid()) {
		MessageBox(NULL, "BGMの読み込みに失敗しました", "", MB_OK);
		return false;
	}
	fontsIndex[_id] = fonts.size();
	fonts.emplace_back(_font);
	return true;
}

