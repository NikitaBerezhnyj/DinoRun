#ifndef SAVE_SYSTEM_H
#define SAVE_SYSTEM_H

#include <iostream>
#include <fstream>
#include <string>

const std::string HIGH_SCORE_FILE = "high_score.dat";

void initHighScoreFile();
int loadHighScore();
void saveHighScore(int score);

#endif // SAVE_SYSTEM_H