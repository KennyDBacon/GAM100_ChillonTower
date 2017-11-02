#include <Windows.h>

#include "GameManager.h"

void SetupConsole() {
	HWND windowHandle;
	HANDLE writeHandle;
	HANDLE readHandle;
	CONSOLE_CURSOR_INFO info;

	windowHandle = GetConsoleWindow();
	writeHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	readHandle = GetStdHandle(STD_INPUT_HANDLE);

	SetConsoleTitle("GAM100 - Chillon Tower");

	SMALL_RECT windowSize = { 100, 100, 1280, 720 };
	SetConsoleWindowInfo(writeHandle, 1, &windowSize);

	COORD bufferSize = { 137, 53 };
	SetConsoleScreenBufferSize(writeHandle, bufferSize);

	SetWindowPos(windowHandle, HWND_TOP, windowSize.Left, windowSize.Top, windowSize.Right, windowSize.Bottom, 0);

	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(writeHandle, &info);
}

int main() {
	SetupConsole();

	GameManager_Init();

	while (GameManager_IsRunning()) {
		GameManager_Update();
	}

	return 0;
}