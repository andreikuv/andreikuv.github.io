//Mason Crippen
//Jack Fontenot
//Connor Griffin
//Andrei Kuvshinikov


#include "token.h"

token::token(){
    _color = color(0, 0, 0);
    center.x = center.y = 0;
    radius = 1;
}

token::token(int r, color c, point p){
    radius = r;
    _color = c;
    center.x = p.x;
    center.y = p.y;
}

void token::setColor(color c){
    _color = c;
}

color token::getColor(){
    return _color;
}

void token::setCenter(point p){
    center.x = p.x;
    center.y = p.y;
}

point token::getCenter(){
    return center;
}

void token::setRadius(int r){
    radius = r;
}

int token::getRadius(){
    return radius;
}

void token::draw(SDL_Plotter& g){
    for(int i = 0; i < 360; i++){
        drawLine(secPoint(i,center).x, center.y, secPoint(i,center).x, secPoint(i,center).y, _color.R, _color.G, _color.B, g);
    }
}

void token::erase(SDL_Plotter& g,color c){
    for(int i = 0; i < 360; i++){
        drawLine(secPoint(i,center).x, center.y, secPoint(i,center).x, secPoint(i,center).y, c.R, c.G, c.B, g);
    }
}
