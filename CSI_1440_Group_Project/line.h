//Mason Crippen
//Jack Fontenot
//Connor Griffin
//Andrei Kuvshinikov


#ifndef LINE_H_INCLUDED
#define LINE_H_INCLUDED

#include <cmath>
#include "SDL_Plotter.h"
using namespace std;

void drawLine(int x1, int y1, int x2, int y2, int R, int G, int B, SDL_Plotter& g);
double slope(int x1, int y1, int x2, int y2);
double y_intercept(int x1, int y1, int x2, int y2);
bool hasSlope(int x1, int y1, int x2, int y2);

#endif // LINE_H_INCLUDED
