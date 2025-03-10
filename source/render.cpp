#include "../include/render.h"

void initRendering()
{
    initscr();
    noecho();
    curs_set(0);
}

void renderFloor(const Game &game)
{
    for (int i = 0; i < game.width; i++)
    {
        mvprintw(game.height - 1, i, "=");
    }
}

void renderGame(const Game &game)
{
    clear();
    mvprintw(0, 0, "Score: %d", game.score);
    mvprintw(1, 0, "High Score: %d", game.highScore);
    mvprintw(game.playerY, game.playerX, "D");

    for (int obstacleX : game.obstaclesX)
    {
        mvprintw(game.obstacleY, obstacleX, "C");
    }

    renderFloor(game);
    refresh();
}

void cleanupRendering()
{
    endwin();
}
