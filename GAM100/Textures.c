#include <stdio.h>

#include "Textures.h"

unsigned char WallTextures[TILE_HEIGHT][TILE_WIDTH] = {
	{ 177, 177, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 177, 177 },
	{ 177, 177, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 177, 177 },
	{ 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178 },
	{ 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178 },
	{ 177, 177, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 177, 177 },
	{ 177, 177, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 177, 177 }
};

unsigned char FloorTextures[TILE_HEIGHT][TILE_WIDTH] = {
	{ 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32 },
	{ 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32 },
	{ 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32 },
	{ 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32 },
	{ 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32 },
	{ 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32 }
};

unsigned char PlayerTextures[2][TILE_HEIGHT][TILE_WIDTH] = {
	{
		{  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32 },
		{  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32 },
		{  32,  32,  32,  32,  32,  32,  32, 233,  32,  32,  32,  32,  32,  32,  32 },
		{  32,  32,  32,  32,  32,  32,  60, 240,  62,  32,  32,  32,  32,  32,  32 },
		{  32,  32,  32,  32,  32,  32,  32, 241,  32,  32,  32,  32,  32,  32,  32 },
		{  32,  32,  32,  32,  32,  32, 189,  32, 211,  32,  32,  32,  32,  32,  32 }
	},
	{
		{ 32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32 },
		{ 32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32 },
		{ 32,  32,  32,  32,  32,  32,  32, 233,  32,  32,  32,  32,  32,  32,  32 },
		{ 32,  32,  32,  32,  32,  32,  32, 240,  32,  32,  32,  32,  32,  32,  32 },
		{ 32,  32,  32,  32,  32,  32,  32, 241,  32,  32,  32,  32,  32,  32,  32 },
		{ 32,  32,  32,  32,  32,  32,  32, 208,  32,  32,  32,  32,  32,  32,  32 }
	}
};

unsigned char EnemyTestTextures[TILE_HEIGHT][TILE_WIDTH];

void Textures_Init() {
	FILE *file;
	errno_t err;

	err = fopen_s(&file, "Data\\EnemyTest.txt", "r");
	if (err) {
		printf("Error loading file\n");
		getchar();
	}
	else {
		int matchCount;
		int asciiValue;
		int xIndex, yIndex;

		xIndex = 0;
		yIndex = 0;
		while ((matchCount = fscanf_s(file, " [%d]", &asciiValue)) != EOF) {
			if (asciiValue != 10) {
				EnemyTestTextures[yIndex][xIndex] = asciiValue;
				++xIndex;
			}
			else {
				xIndex = 0;
				++yIndex;
			}
		}
	}
}

unsigned char Textures_GetChar(TextureID textureID, int xCount, int yCount, int direction) {
	direction = 0;

	switch (textureID) {
	case Tex_Wall:
		return WallTextures[yCount][xCount];
		break;
	case Tex_Floor:
		return FloorTextures[yCount][xCount];
		break;
	case Tex_Player:
		return PlayerTextures[direction][yCount][xCount];
		break;
	}

	return '\0';
}