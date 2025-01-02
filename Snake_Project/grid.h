#ifndef GRID_H_INCLUDED
#define GRID_H_INCLUDED

#include "SDL_Plotter.h"
#include "line.h"

const int SIZE = 800;

class grid{
private:
    int row, col;
    double size;
    color _color;

public:
    grid(int r = 20, int c = 20, double s = (SIZE / 20), color cl = color{});

    int getRow() const;
    int getCol() const;
    double getSize() const;
    color getColor() const;

    void setRow(const int r);
    void setCol(const int c);
    void setSize(const int s);
    void setColor(const color c);

    void draw(SDL_Plotter& g);
};

#endif // GRID_H_INCLUDED
