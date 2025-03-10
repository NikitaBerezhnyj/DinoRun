#ifndef GAME_H
#define GAME_H

#include <stdlib.h>
#include <ncurses.h>
#include <vector>
#include "../include/save_system.h"

struct Game
{
    int width, height;
    int playerX, playerY;
    std::vector<int> obstaclesX;
    int obstacleY;
    int obstacleSpeed;
    int score;
    int highScore;
    bool isJumping;
    bool isGameOver;
    int velocity;
};

void initGame(Game &game);
void updateGame(Game &game);
void handleInput(Game &game, int input);

#endif // GAME_H