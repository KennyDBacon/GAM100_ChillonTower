#include <Windows.h>
#include <conio.h>
#include <time.h>

#include "GameManager.h"
#include "ScreenManager.h"
#include "TileManager.h"
#include "InputHandler.h"

static clock_t gameTime;
static int isRunning;

void GameManager_Init() {
	ScreenManager_Init();

	gameTime = clock();
	isRunning = 1;
}

void GameManager_Update() {
	clock_t currTime = clock();
	float dt = (float)(currTime - gameTime);
	gameTime = currTime;

	HandleInput();
	ScreenManager_Update(dt);

	if (IsGameExit()) {
		isRunning = 0;
	}
}

int GameManager_IsRunning() {
	return isRunning;
}