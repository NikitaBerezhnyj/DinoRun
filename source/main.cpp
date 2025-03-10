#include "../include/game.h"
#include "../include/render.h"
#include "../include/save_system.h"

int main()
{
    Game game;
    initGame(game);
    initRendering();
    initHighScoreFile();

    nodelay(stdscr, TRUE);

    while (true)
    {
        if (game.isGameOver)
        {
            renderGame(game);
            mvprintw(game.height / 2, game.width / 2 - 4, "Game Over!");
            mvprintw((game.height / 2) + 2, game.width / 2 - 9, "Press R for restart");
            mvprintw((game.height / 2) + 3, game.width / 2 - 8, "Press Esc to exit");
            refresh();

            int input = getch();
            if (input != ERR)
            {
                if (input == 'r' || input == 'R')
                {
                    initGame(game);
                    game.isGameOver = false;
                    continue;
                }
                else if (input == 27)
                {
                    break;
                }
            }
        }
        else
        {
            int input = getch();
            if (input != ERR)
            {
                handleInput(game, input);
            }

            updateGame(game);
            renderGame(game);
            napms(50);
        }
    }

    cleanupRendering();
    return 0;
}
