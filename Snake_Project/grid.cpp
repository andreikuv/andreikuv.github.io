#include "grid.h"

grid::grid(int r, int c, double s, color cl){
        row = r;
        col = c;
        size = s;
        _color = cl;
}

int grid::getRow() const{
    return row;
}
int grid::getCol() const{
    return col;
}
double grid::getSize() const{
    return size;
}
color grid::getColor() const{
    return _color;
}

void grid::setRow(const int r){
    row = r;
}
void grid::setCol(const int c){
    col = c;
}
void grid::setSize(const int s){
    size = s;
}
void grid::setColor(const color c){
    _color = c;
}

void grid::draw(SDL_Plotter& g){
    int maxRow = g.getRow();
    int maxCol = g.getCol();

    for(int c = 0; c < col; c++){
        drawLine(c*size, 0, c*size, maxRow-1, _color.R, _color.G, _color.B, g);
    }
    for(int r = 0; r < row; r++){
        drawLine(0, r*size, maxCol-1, r*size, _color.R, _color.G, _color.B, g);
    }
}
