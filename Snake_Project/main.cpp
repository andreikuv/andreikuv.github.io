#include <iostream>
#include <ctime>
#include <vector>
#include <string>
#include <fstream>
#include "grid.h"
#include "square.h"
#include "SDL_Plotter.h"

using namespace std;

enum DIR {RIGHT, UP, LEFT, DOWN};

int main(int argc, char ** argv)
{
    //Data Abstraction
    SDL_Plotter g(SIZE,SIZE);
    clock_t currTime, prevTime;
    time_t start, stop;
    char key;
    grid myGrid;
    vector<square> snake(1);
    vector<square> fruit(4);
    square fillIn, body;
    point snakePos, fruitPos;
    vector<point> snakePosPrev(1);
    DIR dir = RIGHT;
    double dirX = myGrid.getSize(), dirY = 0;
    double updateTime = 0.125;
    bool gameRunning = false, valid = false, updateDir = false;
    string difficulty;
    vector<int> highscores(8);
    ifstream inFile;
    ofstream outFile;
    int highscore, gameMode, num = 0;

    //Input
    myGrid.setCol(20);
    myGrid.setRow(20);

    snakePos.x = snakePos.y = (myGrid.getSize() * 5) + 1;
    snake.at(0).setLoc(snakePos);
    snake.at(0).setPrevLoc(snakePos);
    snake.at(0).setSize(myGrid.getSize() - 1);

    fruitPos.x = ((myGrid.getSize() * 10) + 1);
    fruitPos.y = (myGrid.getSize() * 5) + 1;
    fruit.at(0).setLoc(fruitPos);
    fruit.at(0).setColor(color(255, 0, 0));
    fruit.at(1).setColor(color(255, 255, 0));
    fruit.at(2).setColor(color(255, 0, 255));
    fruit.at(3).setColor(color(0, 0, 255));

    for(int i = 0; i < fruit.size(); i++){
        fruit.at(i).setSize(myGrid.getSize() - 1);
    }

    fillIn.setColor(color(255, 255, 255));
    fillIn.setSize(myGrid.getSize() - 1);

    currTime = clock();
    prevTime = currTime;

    srand(time(0));

    do{
        cout << "(Easy, Normal, Hard, Extreme)" << endl;
        cout << "Enter difficulty: ";
        cin >> difficulty;

        if(difficulty == "Easy"){
            updateTime = 0.25;
            valid = true;
        }
        else if(difficulty == "Normal"){
            updateTime = 0.125;
            valid = true;
        }
        else if(difficulty == "Hard"){
            updateTime = 0.0833;
            valid = true;
        }
        else if(difficulty == "Extreme"){
            updateTime = 0.0625;
            valid = true;
        }

    }while(!valid);

    valid = false;

    do{
        cout << "(1 or 2)" << endl;
        cout << "Enter gamemode: ";
        cin >> gameMode;

        if(gameMode == 1 || gameMode == 2){
            valid = true;
        }

    }while(!valid);

    inFile.open("highscore.txt");

    for(int i = 0; i < highscores.size(); i++){
        inFile >> highscores.at(i);
    }

    inFile.close();

    //Process
    start = time(0);

    while(!gameRunning){
        stop = time(0);

        if(stop - start == 3){
            gameRunning = true;
        }

    }

    while(!g.getQuit() && gameRunning)
    {
        currTime = clock();

        //Draws squares
        myGrid.draw(g);

        if(gameMode == 1){
            fruit.at(0).draw(g);
        }
        else{
            fruit.at(num).draw(g);
        }

        for(int i = 0; i < snake.size(); i++){
            snake.at(i).setColor(color(0, 255, 0));
            snake.at(i).setSize(myGrid.getSize() - 1);
            snake.at(i).draw(g);
        }

        fillIn.draw(g);

        //Gets input keys
        if(updateDir){
            key = toupper(g.getKey());
        }

        if(dir == RIGHT){
            switch(key){
            case 'W':
                dirX = 0;
                dirY = myGrid.getSize() * -1;
                dir = UP;
                break;
            case 'S':
                dirX = 0;
                dirY = myGrid.getSize();
                dir = DOWN;
                break;
            }

            updateDir = false;
        }
        else if(dir == LEFT){
            switch(key){
            case 'W':
                dirX = 0;
                dirY = myGrid.getSize() * -1;
                dir = UP;
                break;
            case 'S':
                dirX = 0;
                dirY = myGrid.getSize();
                dir = DOWN;
                break;
            }

            updateDir = false;
        }
        else if(dir == DOWN){
            switch(key){
            case 'A':
                dirX = myGrid.getSize() * -1;
                dirY = 0;
                dir = LEFT;
                break;
            case 'D':
                dirX = myGrid.getSize();
                dirY = 0;
                dir = RIGHT;
                break;
            }

            updateDir = false;
        }
        else if(dir == UP){
            switch(key){
            case 'A':
                dirX = myGrid.getSize() * -1;
                dirY = 0;
                dir = LEFT;
                break;
            case 'D':
                dirX = myGrid.getSize();
                dirY = 0;
                dir = RIGHT;
                break;
            }

            updateDir = false;
        }

        //Sets fruit location
        //Gamemode 1
        if(gameMode == 1){
            if(snake.at(0).getLoc().x == fruit.at(0).getLoc().x &&
               snake.at(0).getLoc().y == fruit.at(0).getLoc().y){
                snake.push_back(body);
                snake.at(snake.size() - 1).setLoc(snakePosPrev.at(snakePosPrev.size() - 1));
                snakePosPrev.resize(snake.size());

                fruitPos.x = (rand() % 20) * myGrid.getSize() + 1;
                fruitPos.y = (rand() % 20) * myGrid.getSize() + 1;
                fruit.at(0).setLoc(fruitPos);

                for(int i = 1; i < snake.size(); i++){
                    while(fruit.at(0).getLoc().x == snake.at(i).getLoc().x &&
                          fruit.at(0).getLoc().y == snake.at(i).getLoc().y){
                        fruitPos.x = (rand() % 20) * myGrid.getSize() + 1;
                        fruitPos.y = (rand() % 20) * myGrid.getSize() + 1;
                        fruit.at(0).setLoc(fruitPos);

                        i = 1;
                    }
                }
            }
        }

        //Gamemode 2
        else{
            if(snake.at(0).getLoc().x == fruit.at(num).getLoc().x &&
               snake.at(0).getLoc().y == fruit.at(num).getLoc().y){
                if(num == 0){
                    snake.push_back(body);
                    snake.at(snake.size() - 1).setLoc(snakePosPrev.at(snakePosPrev.size() - 1));
                }
                else if(num == 1){
                    snake.push_back(body);
                    snake.at(snake.size() - 1).setLoc(snakePosPrev.at(snakePosPrev.size() - 1));
                    snake.push_back(body);
                    snake.at(snake.size() - 1).setLoc(snakePosPrev.at(snakePosPrev.size() - 1));
                }
                else if(num == 2){
                    snake.push_back(body);
                    snake.at(snake.size() - 1).setLoc(snakePosPrev.at(snakePosPrev.size() - 1));
                    snake.push_back(body);
                    snake.at(snake.size() - 1).setLoc(snakePosPrev.at(snakePosPrev.size() - 1));
                    snake.push_back(body);
                    snake.at(snake.size() - 1).setLoc(snakePosPrev.at(snakePosPrev.size() - 1));
                }
                else{
                    snake.push_back(body);
                    snake.at(snake.size() - 1).setLoc(snakePosPrev.at(snakePosPrev.size() - 1));
                    snake.push_back(body);
                    snake.at(snake.size() - 1).setLoc(snakePosPrev.at(snakePosPrev.size() - 1));
                    snake.push_back(body);
                    snake.at(snake.size() - 1).setLoc(snakePosPrev.at(snakePosPrev.size() - 1));
                    snake.push_back(body);
                    snake.at(snake.size() - 1).setLoc(snakePosPrev.at(snakePosPrev.size() - 1));
                }

                num = rand() % 4;
                snakePosPrev.resize(snake.size());

                fruitPos.x = (rand() % 20) * myGrid.getSize() + 1;
                fruitPos.y = (rand() % 20) * myGrid.getSize() + 1;
                fruit.at(num).setLoc(fruitPos);

                for(int i = 1; i < snake.size(); i++){
                    while(fruit.at(num).getLoc().x == snake.at(i).getLoc().x &&
                          fruit.at(num).getLoc().y == snake.at(i).getLoc().y){
                        fruitPos.x = (rand() % 20) * myGrid.getSize() + 1;
                        fruitPos.y = (rand() % 20) * myGrid.getSize() + 1;
                        fruit.at(num).setLoc(fruitPos);

                        i = 1;
                    }
                }
            }
        }

        //Sets position of snake body
        if(static_cast<double>(currTime - prevTime)/CLOCKS_PER_SEC > updateTime){
            for(int i = 0; i < snake.size(); i++){
                snakePosPrev.at(i) = snake.at(i).getLoc();
            }

            snakePos.x += dirX;
            snakePos.y += dirY;
            snake.at(0).setLoc(snakePos);

            for(int i = 1; i < snake.size(); i++){
                snake.at(i).setLoc(snakePosPrev.at(i - 1));
            }

            for(int i = 0; i < snake.size(); i++){
                snake.at(i).setPrevLoc(snakePosPrev.at(i));
            }

            fillIn.setLoc(snake.at(snake.size() - 1).getPrevLoc());

            prevTime = currTime;

            updateDir = true;
        }

		if(g.kbhit()){
		}

		if(g.mouseClick()){
		}

		//Checks if game is still being played
		for(int i = 1; i < snake.size(); i++){
            if(snake.at(0).getLoc().x == snake.at(i).getLoc().x &&
               snake.at(0).getLoc().y == snake.at(i).getLoc().y){
                start = time(0);

                while(gameRunning){
                    stop = time(0);

                    if(stop - start == 3){
                        gameRunning = false;
                    }
                }
            }
        }

        if(snake.at(0).getLoc().x > (myGrid.getSize() * myGrid.getCol()) ||
           snake.at(0).getLoc().y > (myGrid.getSize() * myGrid.getRow()) ||
           snake.at(0).getLoc().x < 0 ||
           snake.at(0).getLoc().y < 0){
            start = time(0);

            while(gameRunning){
                stop = time(0);

                if(stop - start == 3){
                    gameRunning = false;
                }
            }
        }

		g.update();
    }

    //Output
    cout << "Your score is: " << snake.size() << endl;

    if(gameMode == 1){
        cout << "Gamemode 1 ";

        if(difficulty == "Easy"){
            cout << "Easy ";
            highscore = 0;
        }
        else if(difficulty == "Normal"){
            cout << "Normal ";
            highscore = 1;
        }
        else if(difficulty == "Hard"){
            cout << "Hard ";
            highscore = 2;
        }
        else if(difficulty == "Extreme"){
            cout << "Extreme ";
            highscore = 3;
        }
    }
    else{
        cout << "Gamemode 2 ";

        if(difficulty == "Easy"){
            cout << "Easy ";
            highscore = 4;
        }
        else if(difficulty == "Normal"){
            cout << "Normal ";
            highscore = 5;
        }
        else if(difficulty == "Hard"){
            cout << "Hard ";
            highscore = 6;
        }
        else if(difficulty == "Extreme"){
            cout << "Extreme ";
            highscore = 7;
        }
    }

    if(snake.size() > highscores.at(highscore)){
        highscores.at(highscore) = snake.size();
    }

    cout << "Highscore: " << highscores.at(highscore);

    outFile.open("highscore.txt");

    for(int i = 0; i < highscores.size(); i++){
        outFile << highscores.at(i);
        outFile << endl;
    }

    outFile.close();

}
