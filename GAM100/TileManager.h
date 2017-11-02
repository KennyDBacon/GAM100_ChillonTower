#pragma once

#include "Tile.h"

void TileManager_Init();

Tile* TileManager_GetTile(int xIndex, int yIndex);

void TileManager_Refresh();

void TileManager_PaintGameObjectOnTile(Tile *tile);