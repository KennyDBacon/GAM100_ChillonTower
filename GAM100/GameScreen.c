#include <stdio.h>
#include <Windows.h>

#include "GlobalDefines.h"
#include "ScreenManager.h"
#include "TileManager.h"
#include "GameScreen.h"

#define MAX_TILE_X 137
#define MAX_TILE_Y 52

int const UILayouts[17][5] = {
	/* Long vertical bars */
	{ 205, 0, 0, MAX_TILE_X, 1 },
	{ 205, 0, MAX_TILE_Y - 13, MAX_TILE_X, 1 },
	{ 205, 0, MAX_TILE_Y - 1, MAX_TILE_X, 1 },
	/* Long horizontal bars */
	{ 186, 0, 0, 1, MAX_TILE_Y },
	{ 186, MAX_TILE_X - 1, 0, 1, MAX_TILE_Y },
	/* Far corners */
	{ 201, 0, 0, 1, 1 },
	{ 204, 0, MAX_TILE_Y - 13, 1, 1 },
	{ 200, 0, MAX_TILE_Y - 1, 1, 1 },
	{ 187, MAX_TILE_X - 1, 0, 1, 1 },
	/* Middle sides */
	{ 185, MAX_TILE_X - 1, MAX_TILE_Y - 13, 1, 1 },
	{ 188, MAX_TILE_X - 1, MAX_TILE_Y - 1, 1, 1 },
	/* Middle vertical with corners */
	{ 186, 52, MAX_TILE_Y - 13, 1, 12 },
	{ 203, 52, MAX_TILE_Y - 13, 1, 1 },
	{ 202, 52, MAX_TILE_Y - 1, 1, 1 },
	/* Middle vertical with corners */
	{ 186, 83, MAX_TILE_Y - 13, 1, 12 },
	{ 203, 83, MAX_TILE_Y - 13, 1, 1 },
	{ 202, 83, MAX_TILE_Y - 1, 1, 1 }
};

/* StartX, StartY, Width, Height */
int const healthBarInfo[4] = { 2, 41, PLAYER_HEALTH_MAX, 1 };
int const manaBarInfo[4] = { 2, 43, PLAYER_HEALTH_MAX, 1 };

int const barIndent = 8;

char const healthText[] = { "Health" };
char const manaText[] = { "Mana" };

void GameScreen_Init() {
	int yIndex;
	int xCount;

	for (yIndex = 0; yIndex < _countof(UILayouts); ++yIndex) {
		unsigned char block = (unsigned char)UILayouts[yIndex][0];
		int startX = UILayouts[yIndex][1];
		int startY = UILayouts[yIndex][2];
		int lengthX = UILayouts[yIndex][3];
		int lengthY = UILayouts[yIndex][4];

		for (int y = 0; y < lengthY; ++y) {
			for (int x = 0; x < lengthX; ++x) {
				ScreenManager_PrintUI(startX + x, startY + y, block, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			}
		}
	}

	xCount = _countof(healthText);
	for (int i = 0; i < xCount; ++i) {
		ScreenManager_PrintUI(healthBarInfo[0] + i, healthBarInfo[1], healthText[i], FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		ScreenManager_PrintUI(manaBarInfo[0] + i, manaBarInfo[1], manaText[i], FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	}

	for (int y = 0; y < healthBarInfo[3]; ++y) {
		for (int x = 0; x < healthBarInfo[2]; ++x) {
			ScreenManager_PrintUI(healthBarInfo[0] + barIndent + x, healthBarInfo[1] + y, 219, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			ScreenManager_PrintUI(manaBarInfo[0] + barIndent + x, manaBarInfo[1] + y, 219, 0x0003 | FOREGROUND_INTENSITY);
		}
	}

	TileManager_Init();
}

void GameScreen_Update(float dt) {
	dt = 0; /* Temporary deference */
}

void GameScreen_Exit() {

}