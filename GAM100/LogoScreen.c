#include <stdio.h>

#include "ScreenManager.h"
#include "LogoScreen.h"

#include "Utils.h"

float timer;

void LogoScreen_Init() {
	printf("Logo Screen Initiated\n");
	timer = 0.0;
}

void LogoScreen_Update(float dt) {
	timer += dt;
	printf("Logo Screen Updating (%f)\n", timer);

	if (timer >= 2000.0f) {
		ScreenManager_SetScreenTo(Screen_Title);
	}
}

void LogoScreen_Exit() {
	timer = 0.0f;
	ClearScreen();
}