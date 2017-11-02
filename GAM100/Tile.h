#pragma once

#include "Textures.h"

typedef struct {
	TextureID textureID;

	int posX;
	int posY;
	int walkableLevel;
} Tile;

Tile* Tile_Create(TextureID textureID, int posX, int posY, int walkableLevel);

unsigned char Tile_GetTexture(Tile *tile, int xCount, int yCount);