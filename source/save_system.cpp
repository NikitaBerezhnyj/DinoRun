#include "../include/save_system.h"

void initHighScoreFile()
{
    std::ifstream file(HIGH_SCORE_FILE, std::ios::binary);
    if (!file.good())
    {
        std::ofstream newFile(HIGH_SCORE_FILE, std::ios::binary);
        int highScore = 0;
        newFile.write((char *)&highScore, sizeof(int));
        newFile.close();
    }
    file.close();
}

void saveHighScore(int score)
{
    std::ofstream file(HIGH_SCORE_FILE, std::ios::binary);
    if (file.is_open())
    {
        file.write((char *)&score, sizeof(int));
        file.close();
    }
    else
    {
        std::cerr << "Unable to open file for writing." << std::endl;
    }
}

int loadHighScore()
{
    int highScore = 0;
    std::ifstream file(HIGH_SCORE_FILE, std::ios::binary);
    if (file.is_open())
    {
        file.read((char *)&highScore, sizeof(int));
        file.close();
    }
    else
    {
        std::cerr << "Unable to open file for reading." << std::endl;
    }
    return highScore;
}