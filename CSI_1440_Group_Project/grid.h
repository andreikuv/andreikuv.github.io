//Mason Crippen
//Jack Fontenot
//Connor Griffin
//Andrei Kuvshinikov

#ifndef GRID_H_INCLUDED
#define GRID_H_INCLUDED

#include "config.h"
#include "token.h"

//building boards

/*
* description: copies a board
* return: void
* precondition: copyBoard() is called
* postcondition: newBoard is copied to copiedBoard
*
*/
void copyBoard(char newBoard[][SIZE], char copiedBoard[][SIZE]);

/*
* description: draws the board
* return: void
* precondition: drawBoard() is called
* postcondition: the board is drawn
*
*/
void drawBoard(char board[][SIZE]);

/*
* description: creates a board
* return: void
* precondition: createBoard() is called
* postcondition: a board is created
*
*/
void createBoard(char board[][SIZE]);

/*
* description: draws a board with tokens
* return: void
* precondition: drawBoard() is called
* postcondition: a board is drawn with tokens
*
*/
void drawBoard(SDL_Plotter& g, token tokenBoard[][SIZE]);

/*
* description: draws the grid
* return: void
* precondition: drawGrid() is called
* postcondition: the grid is drawn
*
*/
void drawGrid(SDL_Plotter& g);

/*
* description: A board with tokens is created
* return: void
* precondition: createTokenBoard() is called
* postcondition: A board with tokens is created
*
*/
void createTokenBoard(char currBoard[][SIZE], token tokenBoard[][SIZE]);

/*
* description: updates the token board
* return: void
* precondition: a token is placed
* postcondition: adds and removes tokens based on the arguments
*
*/
void updateTokenBoard(char currBoard[][SIZE], token tokenBoard[][SIZE]);

#endif // GRID_H_INCLUDED
