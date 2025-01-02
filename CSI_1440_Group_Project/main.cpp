//Mason Crippen
//Jack Fontenot
//Connor Griffin
//Andrei Kuvshinikov


#include <iostream>
#include "SDL_Plotter.h"
#include "token.h"
#include "rules.h"
#include "line.h"
#include "config.h"

using namespace std;

int main(int argc, char** argv){
    SDL_Plotter g(BOARDSIZE, BOARDSIZE);

    char currBoard[SIZE][SIZE];
    char pastBoard[SIZE][SIZE];
    char nextBoard[SIZE][SIZE];
    token tokenBoard[SIZE][SIZE];
    int xCord, yCord;
    int turn = 0;
    int pass = 0;
    bool valid;

    createBoard(currBoard);
    createBoard(pastBoard);
    createBoard(nextBoard);

    createTokenBoard(currBoard, tokenBoard);

    cout << "Press 'p' to pass" << endl;
    cout << "Press 's' to see the current score" << endl;

    while(!g.getQuit() && pass < 2){
        //drawBoard(currBoard);
        drawBoard(g, tokenBoard);
        g.update();

        /*if(isBlackTurn(turn)){
            cout << "Black choose space to play or choose -1 to pass" << endl;
        }
        else{
            cout << "White choose space to play or choose -1 to pass" << endl;
        }*/
        if(g.kbhit()){
            switch(toupper(g.getKey())){
                case 'P':
                    turnPassed(turn);
                    pass++;
                    turn++;
                    break;
                case 'S':
                    score(currBoard);
                    break;
            }
        }

        if (g.mouseClick()) {
            valid = false;

            point p = g.getMouseClick();
            xCord = p.y / SIDE;
            yCord = p.x / SIDE;

            if(isBlackTurn(turn)){
                nextBoard[xCord][yCord] = 'b';
            }
            else{
                nextBoard[xCord][yCord] = 'w';
            }

            valid = validPlay(nextBoard, pastBoard, currBoard, xCord, yCord, turn);

            if(valid){
                copyBoard(pastBoard, currBoard);
                copyBoard(currBoard, nextBoard);
                pass = 0;
                turn++;
            }
            else{
                copyBoard(nextBoard, currBoard);
            }
        }
        updateTokenBoard(currBoard, tokenBoard);
    }
    finalScore(currBoard);

    return 0;
}
