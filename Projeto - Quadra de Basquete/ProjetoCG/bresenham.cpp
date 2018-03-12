#include "bresenham.h"
#include <algorithm>
#include <GL/glut.h>

using namespace std;

void setPixel(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x, y); //Set pixel coordinates
    glEnd();
    glFlush();
}

//Draw line if X distance is greater than Y
void bresenhamX(int x0, int y0, int x1, int y1, int dx, int dy)
{
    int i, j, k;

    i = 2 * dy - dx;
    j = 2 * dy;
    k = 2 * (dy - dx);
    if (!(x0 < x1)) {
        swap(x0, x1);
        swap(y0, y1);
    }
    setPixel(x0, y0);
    while (x0 < x1) {
        if (i < 0)
            i += j;
        else {
            if (y0 < y1)
                ++y0;
            else
                --y0;
            i += k;
        }
        ++x0;
        setPixel(x0, y0);
    }
}

//Draw line if X distance is lesser than Y
void bresenhamY(int x0, int y0, int x1, int y1, int dx, int dy)
{
    int i, j, k;

    i = 2 * dx - dy;
    j = 2 * dx;
    k = 2 * (dx - dy);
    if (!(y0 < y1)) {
        swap(x0, x1);
        swap(y0, y1);
    }
    setPixel(x0, y0);
    while (y0 < y1) {
        if (i < 0)
            i += j;
        else {
            if (x0 > x1)
                --x0;
            else
                ++x0;
            i += k;
        }
        ++y0;
        setPixel(x0, y0);
    }
}

void bresenham(int x0, int y0, int x1, int y1)
{
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);

    if (dx >= dy)
        bresenhamX(x0, y0, x1, y1, dx, dy);
    else
        bresenhamY(x0, y0, x1, y1, dx, dy);
}


// Plot eight points using circle's symmetrical property
void plot_pointCirc(int xc, int yc, int x, int y)
{
  glBegin(GL_POINTS);
  glVertex2i(xc+x, yc+y);//1 quadrante
  glVertex2i(xc+y, yc+x);
  glVertex2i(xc-x, yc+y);//2 quadrante
  glVertex2i(xc-y, yc+x);
  glVertex2i(xc-x, yc-y);//3 quadrante
  glVertex2i(xc-y, yc-x);
  glVertex2i(xc+x, yc-y);//4 quadrante
  glVertex2i(xc+y, yc-x);
  glEnd();
}

// Function to draw a circle using bresenham's
// circle drawing algorithm
void bresenham_circle(int xc, int yc, int r)
{
  int x=0,y=r;
  float pk=(5.0/4.0)-r;

  /* Plot the points */
  /* Plot the first point */
  plot_pointCirc(xc, yc, x, y);
  /* Find all vertices till x=y */
  while(x < y)
  {
    x = x + 1;
    if(pk < 0)
      pk = pk + 2*x+1;
    else
    {
      y = y - 1;
      pk = pk + 2*(x - y) + 1;
    }
    plot_pointCirc(xc, yc, x, y);
  }
  glFlush();
}


void bresenham_semi_circle(int xc, int yc, int r, int dir)
{
    int x=0,y=r;
    float pk=(5.0/4.0)-r;
    glBegin(GL_POINTS);
    /* Plot the points */
    /* Plot the first point */
    if(dir == 1) {
        glVertex2i(xc+x, yc+y);//1 quadrante
        glVertex2i(xc+y, yc+x);
        glVertex2i(xc+x, yc-y);//4 quadrante
        glVertex2i(xc+y, yc-x);
    } else {
        glVertex2i(xc-x, yc+y);//2 quadrante
        glVertex2i(xc-y, yc+x);
        glVertex2i(xc-x, yc-y);//3 quadrante
        glVertex2i(xc-y, yc-x);
    }
    /* Find all vertices till x=y */

    while(x < y)
    {
      x = x + 1;
      if(pk < 0)
        pk = pk + 2*x+1;
      else
      {
        y = y - 1;
        pk = pk + 2*(x - y) + 1;
      }
      if(dir == 1) {
          glVertex2i(xc+x, yc+y);//1 quadrante
          glVertex2i(xc+y, yc+x);
          glVertex2i(xc+x, yc-y);//4 quadrante
          glVertex2i(xc+y, yc-x);
      } else {
          glVertex2i(xc-x, yc+y);//2 quadrante
          glVertex2i(xc-y, yc+x);
          glVertex2i(xc-x, yc-y);//3 quadrante
          glVertex2i(xc-y, yc-x);
      }

    }
    glEnd();
    glFlush();
}
