#pragma once

#include <Windows.h>

typedef enum {
	Screen_Exit = -2,
	Screen_NULL = -1,

	Screen_Logo = 0,
	Screen_Title = 1,
	Screen_GameActual = 2,
	Screen_GameMenu = 3
} ScreenID;

typedef struct Screen Screen;

void ScreenManager_Init();

void ScreenManager_Update(float dt);

void ScreenManager_ExecuteInit();

void ScreenManager_ExecuteUpdate(float dt);

void ScreenManager_ExecuteExit();

void ScreenManager_SetScreenTo(ScreenID nextScreen);

void ScreenManager_PrintUI(int x, int y, unsigned char charToPrint, WORD attr);

int IsScreenChanging();

int IsScreenValid();

int IsGameExit();