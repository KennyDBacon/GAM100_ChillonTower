#include <conio.h>

#include "InputHandler.h"

static int keypressed;

void HandleInput() {
	keypressed = 0;

	if (_kbhit()) {
		keypressed = _getch();
	}
}

int GetKeypressed() {
	return keypressed;
}