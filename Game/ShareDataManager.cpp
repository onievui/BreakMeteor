#include "ShareDataManager.h"



/// <summary>
/// ƒf[ƒ^‚Ì‰Šú‰»
/// </summary>
void ShareDataManager::initialize() {
	score = 0;
	highscore = 0;
}

int ShareDataManager::getScore() const {
	return score;
}

void ShareDataManager::setScore(const int _score) {
	score = _score;
}

int ShareDataManager::getHighscore() const {
	return highscore;
}

void ShareDataManager::setHighscore(const int _highscore) {
	highscore = _highscore;
}
