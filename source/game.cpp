#include "../include/game.h"
#include <cstdlib>
#include <ctime>

void initGame(Game &game)
{
    game.width = 80;
    game.height = 24;
    game.playerX = 10;
    game.playerY = game.height - 2;
    game.obstaclesX = {game.width - 10};
    game.obstacleY = game.height - 2;
    game.score = 0;
    game.highScore = 0;
    game.isJumping = false;
    game.isGameOver = false;
    game.velocity = 0;
    game.obstacleSpeed = 2;

    game.highScore = loadHighScore();

    std::srand(std::time(nullptr));
}

void spawnObstacles(Game &game)
{
    game.obstaclesX.clear();

    int count = 1 + (std::rand() % 3);
    int position = game.width - 10;
    int gap = 3;

    for (int i = 0; i < count; i++)
    {
        game.obstaclesX.push_back(position);
        position += gap;
    }
}

void updateGame(Game &game)
{
    if (game.isJumping)
    {
        game.velocity += 1;
        game.playerY += game.velocity;
        if (game.playerY > game.height - 2)
        {
            game.playerY = game.height - 2;
            game.isJumping = false;
            game.velocity = 0;
        }
    }
    else
    {
        game.playerY += 2;
        if (game.playerY > game.height - 2)
        {
            game.playerY = game.height - 2;
        }
    }

    for (size_t i = 0; i < game.obstaclesX.size(); i++)
    {
        game.obstaclesX[i] -= game.obstacleSpeed;
    }

    if (game.obstaclesX[0] < 0)
    {
        spawnObstacles(game);
    }

    for (int obstacleX : game.obstaclesX)
    {
        if (game.playerX + 2 > obstacleX &&
            game.playerX < obstacleX + 2 &&
            game.playerY + 2 > game.obstacleY &&
            game.playerY < game.obstacleY + 2)
        {
            game.isGameOver = true;
        }
    }

    if (game.score % 500 == 0 && game.score != 0)
    {
        game.obstacleSpeed = std::min(game.obstacleSpeed + 1, 5);
    }

    game.score++;

    if (game.highScore < game.score)
    {
        game.highScore = game.score;
        saveHighScore(game.highScore);
    }
}

void handleInput(Game &game, int input)
{
    if (input == ' ')
    {
        if (!game.isJumping)
        {
            game.isJumping = true;
            game.velocity = -5;
        }
    }
    else if (input == 27)
    {
        game.isGameOver = true;
    }
}
