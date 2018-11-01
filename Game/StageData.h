#pragma once


enum BLOCK_TYPE {
	NONE,
	NORMAL_RED,
	NORMAL_GREEN,
	NORMAL_BLUE,
	TYPE_NUM,
};


namespace StageData {

	static int STAGE_DATA1[3][8] = {
		{ 1,1,1,1,1,1,1,1 },
		{ 2,2,2,0,2,2,2,2 },
		{ 3,3,3,3,3,0,3,3 }
	};



}