//Mason Crippen
//Jack Fontenot
//Connor Griffin
//Andrei Kuvshinikov

#ifndef RULES_H_INCLUDED
#define RULES_H_INCLUDED

#include "SDL_Plotter.h"
#include "token.h"
#include "grid.h"

//Turn
/*
 * description: checks which color's turn it is
 * return: bool
 * precondition: a move is needed
 * postcondition: gives which player's turn it is
 *
*/
bool isBlackTurn(int turn);

//Pass
/*
 * description: passes the current player's turn
 * return: void
 * precondition: 'p' is pressed
 * postcondition: the current player's turn is passed
 *
*/
void turnPassed(int turn);

//Checking for captures
/*
 * description: checks if a space is captured
 * return: bool
 * precondition: a turn is made
 * postcondition: returns true if space is captured, false otherwise
 *
*/
bool spaceCaptured(char currBoard[][SIZE], int r, int c, bool blackTurn);

/*
 * description: checks if a white piece is captured
 * return: bool
 * precondition: black is placed adjacent to a white piece
 * postcondition: returns true if a white piece is captured
 *
*/
bool whiteCaptured(char currBoard[][SIZE], int r, int c);

/*
 * description: checks if a black piece is captured
 * return: bool
 * precondition: white is placed adjacent to a black piece
 * postcondition: returns true if a black piece is captured
 *
*/
bool blackCaptured(char currBoard[][SIZE], int r, int c);

/*
 * description: checks surrounding spaces for capture
 * return: bool
 * precondition: a piece is placed
 * postcondition: returns true if a space around the piece is captured
 *
*/
bool surrondingCaptured(char currBoard[][SIZE], int r, int c, bool blackTurn);

/*
 * description: checks if a piece is captured
 * return: void
 * precondition: a piece is captured
 * postcondition: the board space is changed to blank
 *
*/
void checkCapture(char currBoard[][SIZE], bool blackTurn);

//Checking if play is valid
/*
 * description: checks if a play is valid
 * return: bool
 * precondition: a move is made
 * postcondition: allows a move if it is valid
 *
*/
bool validPlay(char next[][SIZE], char past[][SIZE], char curr[][SIZE],
               int xCord, int yCord, int turn);

//Scoring
/*
 * description: checks if black scored
 * return: bool
 * precondition: black made a move
 * postcondition: black's score is updated
 *
*/
bool scoredBlack(char currBoard[][SIZE], int r, int c);

/*
 * description: checks if white scored
 * return: bool
 * precondition: white made a move
 * postcondition: white's score is updated
 *
*/
bool scoredWhite(char currBoard[][SIZE], int r, int c);

/*
 * description: checks and prints the score to screen
 * return:  void
 * precondition: 's' is pressed
 * postcondition: the score is output to the screen
 *
*/
void score(char currBoard[][SIZE]);

/*
 * description: outputs the final score
 * return: void
 * precondition: the game is over
 * postcondition: final score is checked and output to screen
 *
*/
void finalScore(char currBoard[][SIZE]);

#endif // RULES_H_INCLUDED
