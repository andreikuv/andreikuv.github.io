#include "myFunctions.h"

void getHighscore(){

    inFile.open("highscore.txt");
    getline(inFile, gamemode1);
    getline(inFile, line);

    for(int i = 0; i < highscore.size(); i++){
        getline(inFile, highscore.at(i));
    }

    getline(inFile, gamemode2);
    getline(inFile, line);

    for(int i = 4; i < highscore.size(); i++){
        getline(inFile, highscore.at(i));
    }

    inFile.close();

}

void writeHighscore(int gameMode, string difficulty, vector<string>& highscore){

    cout << "Highscore: " << highscore << endl;

    outFile.open("highscore.txt");

    outFile << gamemode1;
    outFile << line;

    for(int i = 0; i < highscore.size(); i++){
        outFile << highscore.at(i);
    }

    outFile << gamemode2;
    outFile << line);

    for(int i = 4; i < highscore.size(); i++){
        outFile << highscore.at(i);
    }

    outFile.close();
}
