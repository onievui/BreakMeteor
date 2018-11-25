#include "Sound.h"



SoundPlayer::SoundPlayer() {
	reset();
}

void SoundPlayer::reset() {
	readySounds.fill(-1);
	readyMusics.fill(-1);
	continueMusics.fill(false);
}

void SoundPlayer::setSound(const SoundID _id) {
	if (_id < 0 || _id >= SoundID::SOUND_NUM) {
		MessageBox(NULL, "���ʉ��̃Z�b�g�ŕs���Ȓl���n����܂���", "", MB_OK);
		return;
	}
	readySounds[_id] = 1;
}

void SoundPlayer::setMusic(const MusicID _id) {
	if (_id < 0 || _id >= MusicID::MUSIC_NUM) {
		MessageBox(NULL, "BGM�̃Z�b�g�ŕs���Ȓl���n����܂���", "", MB_OK);
		return;
	}
	readyMusics[_id] = 1;
}

void SoundPlayer::playSound() {
	for (int i = 0; i < SoundID::SOUND_NUM; ++i) {
		if (readySounds[i] > 0) {
			PlaySoundMem(ResourceManager::getIns()->getSound((SoundID)i), DX_PLAYTYPE_BACK);
			readySounds[i] = 0;
		}
	}
}

void SoundPlayer::playMusic() {
	for (int i = 0; i < MusicID::MUSIC_NUM; ++i) {
		if (readyMusics[i] > 0) {
			PlaySoundMem(ResourceManager::getIns()->getMusic((MusicID)i), DX_PLAYTYPE_LOOP, !continueMusics[i]);
			readyMusics[i] = 0;
			continueMusics[i] = false;
		}
	}
}

void SoundPlayer::stopSound(const SoundID _id) {
	if (_id < 0 || _id >= SoundID::SOUND_NUM) {
		MessageBox(NULL, "���ʉ��̒�~�ŕs���Ȓl���n����܂���", "", MB_OK);
		return;
	}
	StopSoundMem(ResourceManager::getIns()->getSound(_id));
}

void SoundPlayer::stopMusic(const MusicID _id) {
	if (_id < 0 || _id >= MusicID::MUSIC_NUM) {
		MessageBox(NULL, "BGM�̒�~�ŕs���Ȓl���n����܂���", "", MB_OK);
		return;
	}
	StopSoundMem(ResourceManager::getIns()->getMusic(_id));
}

void SoundPlayer::continueMusic(const MusicID _id) {
	if (_id < 0 || _id >= MusicID::MUSIC_NUM) {
		MessageBox(NULL, "BGM�̍ĊJ�ŕs���Ȓl���n����܂���", "", MB_OK);
		return;
	}
	readyMusics[_id] = 1;
	continueMusics[_id] = true;
}

void SoundPlayer::stopAll() {
	for (int i = 0; i < SoundID::SOUND_NUM; ++i) {
		if (readySounds[i] != -1) {
			StopSoundMem(ResourceManager::getIns()->getSound((SoundID)i));
		}
	}
	for (int i = 0; i < MusicID::MUSIC_NUM; ++i) {
		if (readyMusics[i] != -1) {
			StopMusicMem(ResourceManager::getIns()->getMusic((MusicID)i));
		}
	}
}
