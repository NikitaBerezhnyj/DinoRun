#ifndef RENDER_H
#define RENDER_H

#include "game.h"
#include <ncurses.h>

void initRendering();
void renderFloor(const Game &game);
void renderGame(const Game &game);
void cleanupRendering();

#endif // RENDER_H