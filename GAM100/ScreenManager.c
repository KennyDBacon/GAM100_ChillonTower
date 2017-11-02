#include <stdlib.h>
#include <stdio.h>

#include "ScreenManager.h"
#include "LogoScreen.h"
#include "TitleScreen.h"
#include "GameScreen.h"
#include "MenuScreen.h"

typedef void(*ScreenVoidFunctionPtr)();
typedef void(*ScreenDtVoidFunctionPtr)(float dt);

typedef struct
{
	ScreenVoidFunctionPtr screenInit;
	ScreenDtVoidFunctionPtr screenUpdate;
	ScreenVoidFunctionPtr screenExit;

} ScreenTableEntry;

typedef struct Screen {
	ScreenID current;
	ScreenID next;
} Screen;

static const ScreenTableEntry ScreenTab[4] =
{
	{ LogoScreen_Init, LogoScreen_Update, LogoScreen_Exit },
	{ TitleScreen_Init, TitleScreen_Update, TitleScreen_Exit },
	{ GameScreen_Init, GameScreen_Update, GameScreen_Exit},
	{ MenuScreen_Init, MenuScreen_Update, MenuScreen_Exit }
};

static Screen *screen;

void ScreenManager_Init() {
	screen = (Screen*)malloc(sizeof(Screen));
	if (screen == NULL) {
		return;
	}

	screen->current = Screen_NULL;
	screen->next = Screen_Logo;
}

void ScreenManager_Update(float dt) {
	if (IsScreenChanging()) {
		ScreenManager_ExecuteExit();

		screen->current = screen->next;

		ScreenManager_ExecuteInit();
	}

	ScreenManager_ExecuteUpdate(dt);
}

void ScreenManager_ExecuteInit() {
	if (IsScreenValid()) {
		ScreenTab[screen->current].screenInit();
	}
}

void ScreenManager_ExecuteUpdate(float dt) {
	if (IsScreenValid()) {
		ScreenTab[screen->current].screenUpdate(dt);
	}
}

void ScreenManager_ExecuteExit() {
	if (IsScreenValid()) {
		ScreenTab[screen->current].screenExit();
	}
}

void ScreenManager_SetScreenTo(ScreenID nextScreen) {
	screen->next = nextScreen;
}

void ScreenManager_PrintUI(int x, int y, unsigned char charToPrint, WORD attr) {
	COORD coord;
	HANDLE writeHandle;

	coord.X = (short)x;
	coord.Y = (short)y;
	writeHandle = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleCursorPosition(writeHandle, coord);
	SetConsoleTextAttribute(writeHandle, attr);

	printf("%c", charToPrint);
}

#pragma region Boolean Functions

int IsScreenChanging() {
	if (screen->current != screen->next) {
		return 1;
	}

	return 0;
}

int IsScreenValid() {
	if (screen->current != Screen_NULL) {
		return 1;
	}

	return 0;
}

int IsGameExit() {
	if (screen->next == Screen_Exit) {
		return 1;
	}

	return 0;
}

#pragma endregion