#include <stdio.h>
#include <conio.h>

#include "ScreenManager.h"
#include "TitleScreen.h"

#include "InputHandler.h"
#include "Utils.h"

void TitleScreen_Init() {
	printf("Title Screen\n");
	printf("(P)lay\n");
	printf("(Q)uit\n");
}

void TitleScreen_Update(float dt) {
	dt = 0; /* Temporary deference */
	int input = GetKeypressed();

	if (input == 80 || input == 112) {
		ScreenManager_SetScreenTo(Screen_GameActual);
	}
	else if (input == 81 || input == 113) {
		ScreenManager_SetScreenTo(Screen_Exit);
	}
}

void TitleScreen_Exit() {
	ClearScreen();
}