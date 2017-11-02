#pragma once

#include "GlobalDefines.h"

typedef enum {
	Tex_Wall,
	Tex_Floor,
	Tex_Player
} TextureID;

void Textures_Init();

unsigned char Textures_GetChar(TextureID textureID, int xCount, int yCount, int direction);