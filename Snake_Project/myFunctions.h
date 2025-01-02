#ifndef MYFUNCTIONS_H_INCLUDED
#define MYFUNCTIONS_H_INCLUDED

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

string gamemode1, gamemode2, line;
vector<string> highscore(8);
ifstream inFile;
ofstream outFile;

void getHighscore();
void writeHighscore(int gameMode, string difficulty, vector<string>& highscore);

#endif // MYFUNCTIONS_H_INCLUDED
