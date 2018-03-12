#ifndef BRESENHAM_H
#define BRESENHAM_H


void setPixel(int x, int y);
void bresenhamX(int x0, int y0, int x1, int y1, int dx, int dy);
void bresenhamY(int x0, int y0, int x1, int y1, int dx, int dy);
void bresenham(int x0, int y0, int x1, int y1);
void plot_pointCirc(int xc, int yc, int x, int y);
void bresenham_circle(int xc, int yc, int r);
void bresenham_semi_circle(int xc, int yc, int r, int dir);



#endif // BRESENHAM_H
