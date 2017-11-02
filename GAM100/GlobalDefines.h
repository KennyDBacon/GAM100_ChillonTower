#pragma once

#define GAMESCREEN_UI_HEIGHT 12

#define TILE_COUNT_X 9
#define TILE_COUNT_Y 5

#define TILE_WIDTH 15
#define TILE_HEIGHT 6

#define SCREEN_CHAR_X (TILE_COUNT_X * TILE_WIDTH) + 2
/* One extra line at the bottom of the screen as buffer */
#define SCREEN_CHAR_Y (TILE_COUNT_Y * TILE_HEIGHT) + GAMESCREEN_UI_HEIGHT + 3

#define PLAYER_HEALTH_MAX 40