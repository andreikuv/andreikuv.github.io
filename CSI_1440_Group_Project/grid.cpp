//Mason Crippen
//Jack Fontenot
//Connor Griffin
//Andrei Kuvshinikov

#include "grid.h"

//building boards
void copyBoard(char newBoard[][SIZE], char copiedBoard[][SIZE]){
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            newBoard[i][j] = copiedBoard[i][j];
        }
    }
}
void drawBoard(char board[][SIZE]){
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}
void createBoard(char board[][SIZE]){
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            board[i][j] = '.';
        }
    }
}
void drawBoard(SDL_Plotter& g, token tokenBoard[][SIZE]){
    for(int i = 0; i < BOARDSIZE; i++){
        for(int j = 0; j < BOARDSIZE; j++){
            g.plotPixel(i, j, boardColor);
        }
    }

    drawGrid(g);

    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            if(tokenBoard[i][j].getColor().R != emptyColor.R){
                tokenBoard[i][j].draw(g);
            }
        }
    }
}
void drawGrid(SDL_Plotter& g){
    int x1, y1, x2, y2, R=0, G=0, B=0;

    //draw vertical lines
    y1 = SIDE/2;
    y2 = BOARDSIZE-SIDE/2;
    int numVLines = SIZE;

    for(int i = 0; i < numVLines; i++){
        x1 = x2 = SIDE*i+SIDE/2;
        drawLine(x1, y1, x2, y2, R, G, B, g);
    }

    //draw horizontal line
    int numHLines = SIZE;
    x1 = SIDE/2;
    x2 = BOARDSIZE-SIDE/2;

    for(int i = 0; i < numHLines; i++){
        y1 = y2 = SIDE*i+SIDE/2;
        drawLine(x1, y1, x2, y2, R, G, B, g);
    }
}
void createTokenBoard(char currBoard[][SIZE], token tokenBoard[][SIZE]){
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            point center(SIDE*j+SIDE/2, SIDE*i+SIDE/2);
            tokenBoard[i][j].setColor(emptyColor);
            tokenBoard[i][j].setRadius((SIDE/2)-5);
            tokenBoard[i][j].setCenter(center);
        }
    }
}
void updateTokenBoard(char currBoard[][SIZE], token tokenBoard[][SIZE]){
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            if(currBoard[i][j] == 'b'){
                tokenBoard[i][j].setColor(blackColor);
            }
            else if(currBoard[i][j] == 'w'){
                tokenBoard[i][j].setColor(whiteColor);
            }
            else{
                tokenBoard[i][j].setColor(emptyColor);
            }
        }
    }
}
