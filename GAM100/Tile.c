#include <stdlib.h>

#include "Tile.h"

Tile* Tile_Create(TextureID textureID, int posX, int posY, int walkableLevel) {
	Tile *tile;

	tile = (Tile*)malloc(sizeof(Tile));
	if (tile == NULL) {
		return NULL;
	}

	tile->textureID = textureID;

	tile->posX = posX;
	tile->posY = posY;
	tile->walkableLevel = walkableLevel;

	return tile;
}

unsigned char Tile_GetTexture(Tile *tile, int xCount, int yCount) {
	return Textures_GetChar(tile->textureID, xCount, yCount, 0);
}