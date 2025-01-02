#include "line.h"

void drawLine(int x1, int y1, int x2, int y2, int R, int G, int B, SDL_Plotter& g){
    double m = slope(x1, y1, x2, y2);
    double b = y_intercept(x1, y1, x2, y2);
    int y;
    if(hasSlope(x1,y1,x2,y2)){
        for (int x = min(x1,x2); x <= max(x1,x2); x++){
            y = m * x + b;
            g.plotPixel(x, y, R, G, B);
        }
    }
    else {
        for(int y = min(y1,y2); y <= max(y1,y2); y++){
            g.plotPixel(x1, y, R, G, B);
        }
    }
}

double slope(int x1, int y1, int x2, int y2){
    // delta y / delta x
    return static_cast<double>(y1-y2)/(x1-x2);
}
double y_intercept(int x1, int y1, int x2, int y2){
    double m = slope(x1, y1, x2, y2);
    return y1 - m * x1;
}

bool hasSlope(int x1, int y1, int x2, int y2){
    return x1 != x2;
}
