//Mason Crippen
//Jack Fontenot
//Connor Griffin
//Andrei Kuvshinikov


#ifndef TOKEN_H_INCLUDED
#define TOKEN_H_INCLUDED

#include "line.h"

class token{
private:
    int radius;
    point center;
    color _color;
    point secPoint(int deg, point c){
        point p;
        double rad = deg * M_PI / 180.0;

        p.x = static_cast<int>(radius * cos(rad)) + c.x;
        p.y = static_cast<int>(radius * sin(rad)) + c.y;

        return p;
    }

public:

    /*
    * description: default constructor
    * return: constructor
    * precondition: a token is created
    * postcondition: a default token is constructed
    *
    */
    token();

    /*
    * description: token constructor
    * return: constructor
    * precondition: a token is created with correct arguments
    * postcondition: token is initialized with parameters
    *
    */
    token(int r, color c, point p);

    /*
    * description: sets the color of a token
    * return: void
    * precondition: setColor() is called
    * postcondition: token's color is set
    *
    */
    void setColor(color c);

    /*
    * description: returns the color
    * return:  color
    * precondition: getColor() is called
    * postcondition: color of the token is returned
    *
    */
    color getColor();

    /*
    * description: location of token is set
    * return: void
    * precondition: a token is placed
    * postcondition: token's center is set
    *
    */
    void setCenter(point p);

    /*
    * description: token's center is returned
    * return: point
    * precondition: getCenter() is called
    * postcondition: token's center is returned
    *
    */
    point getCenter();

    /*
    * description: token's size is set
    * return: void
    * precondition: setRadius() is called
    * postcondition: token's radius is set
    *
    */
    void setRadius(int r);

    /*
    * description: token's size is returned
    * return: int
    * precondition: getRadius() is called
    * postcondition: Radius is returned
    *
    */
    int getRadius();

    /*
    * description: draws a token
    * return:  void
    * precondition: draw() is called
    * postcondition: a token is drawn
    *
    */
    void draw(SDL_Plotter& g);

    /*
    * description: erases the token
    * return: void
    * precondition: erase() is called
    * postcondition: the token is erased from the screen
    *
    */
    void erase(SDL_Plotter& g,color c);
};

#endif // TOKEN_H_INCLUDED
