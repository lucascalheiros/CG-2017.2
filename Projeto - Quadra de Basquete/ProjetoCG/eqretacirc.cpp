#include "eqretacirc.h"
#include <algorithm>
#include <GL/glut.h>

using namespace std;

void eqReta(int x0, int y0, int x1, int y1)
{
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    glBegin(GL_POINTS);
    if (dx >= dy)
        eqRetaX(x0, y0, x1, y1);
    else
        eqRetaY(x0, y0, x1, y1);
    glEnd();
}

void eqRetaX(int x0, int y0, int x1, int y1)
{
    if (!(x0 < x1)) {
        swap(x0, x1);
        swap(y0, y1);
    }
    double a = (double)(y1-y0)/(x1-x0);
    int y;
    for(int x=x0; x<=x1; x++) {
        y = (y0 + a*(x-x0));
        glVertex2i(x, y);
    }
}

void eqRetaY(int x0, int y0, int x1, int y1)
{
    if (!(y0 < y1)) {
        swap(x0, x1);
        swap(y0, y1);
    }
    double a = (double)(x1-x0)/(y1-y0);
    int x;
    for(int y=y0; y<=y1; y++) {
        x = (x0 + a*(y-y0));
        glVertex2i(x, y);
    }
}



void eqCirc(int xc, int yc, int r)
{
    int x, y;
    glBegin(GL_POINTS);
    for(x = xc-r; x<=r+xc; x++){
        y = yc + sqrt(r*r-(x-xc)*(x-xc));
        glVertex2i(x, y);
    }
    for(x = xc-r; x<=r+xc; x++){
        y = yc - sqrt(r*r-(x-xc)*(x-xc));
        glVertex2i(x, y);
    }
    glEnd();
    glFlush();
}

void eqSemiCirc(int xc, int yc, int r, int dir)
{
    int x, y;
    glBegin(GL_POINTS);
    if(dir==1){
        for(x = xc; x<=r+xc; x++){
            y = yc + sqrt(r*r-(x-xc)*(x-xc));
            glVertex2i(x, y);
            y = yc - sqrt(r*r-(x-xc)*(x-xc));
            glVertex2i(x, y);
        }
    } else {
        for(x = xc; x>=xc-r; x--){
            y = yc + sqrt(r*r-(x-xc)*(x-xc));
            glVertex2i(x, y);
            y = yc - sqrt(r*r-(x-xc)*(x-xc));
            glVertex2i(x, y);
        }
    }
    glEnd();
    glFlush();
}
