#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>

#include "TileManager.h"
#include "GlobalDefines.h"

static Tile *tiles[SCREEN_HEIGHT][SCREEN_WIDTH];

void TileManager_Init() {
	/* Initialize all the tiles */
	for (int yIndex = 0; yIndex < SCREEN_HEIGHT; ++yIndex) {
		for (int xIndex = 0; xIndex < SCREEN_WIDTH; ++xIndex) {
			if (yIndex == 0 || yIndex == SCREEN_HEIGHT - 1 || xIndex == 0 || xIndex == SCREEN_WIDTH - 1) {
				tiles[yIndex][xIndex] = Tile_Create(Tex_Wall, xIndex, yIndex, 0);
			}
			else {
				tiles[yIndex][xIndex] = Tile_Create(Tex_Floor, xIndex, yIndex, 1);
			}
		}
	}

	TileManager_Refresh();
}

Tile* TileManager_GetTile(int xIndex, int yIndex) {
	return tiles[yIndex][xIndex];
}

void TileManager_Refresh() {
	HANDLE writeHandle;
	COORD coord;
	unsigned char line[TILE_WIDTH];

	writeHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(writeHandle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

	for (int yIndex = 0; yIndex < SCREEN_HEIGHT; ++yIndex) {
		for (int xIndex = 0; xIndex < SCREEN_WIDTH; ++xIndex) {
			for (int yCount = 0; yCount < TILE_HEIGHT; ++yCount) {
				for (int xCount = 0; xCount < TILE_WIDTH; ++xCount) {
					line[xCount] = Tile_GetTexture(tiles[yIndex][xIndex], xCount, yCount);
				}

				coord.X = (short)(1 + (xIndex * TILE_WIDTH));
				coord.Y = (short)(1 + yCount + (yIndex * TILE_HEIGHT));

				SetConsoleCursorPosition(writeHandle, coord);
				printf("%.*s", TILE_WIDTH, line);
			}
		}
	}
}

void TileManager_PaintGameObjectOnTile(Tile *tile) {
	HANDLE writeHandle;
	COORD coord;
	unsigned char line[TILE_WIDTH];

	writeHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(writeHandle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

	for (int yCount = 0; yCount < TILE_HEIGHT; ++yCount) {
		for (int xCount = 0; xCount < TILE_WIDTH; ++xCount) {
			line[xCount] = Tile_GetTexture(tile, xCount, yCount);
		}

		coord.X = (short)(1 + (tile->posX * TILE_WIDTH));
		coord.Y = (short)(1 + yCount + (tile->posY * TILE_HEIGHT));

		SetConsoleCursorPosition(writeHandle, coord);
		printf("%.*s", TILE_WIDTH, line);
	}
}