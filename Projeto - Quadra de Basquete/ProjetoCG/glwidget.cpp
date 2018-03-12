#include "glwidget.h"
#include <QMouseEvent>
#include <QMessageBox>
#include <vector>
#include <utility>
#include <bresenham.h>
#include "defines.h"
#include "eqretacirc.h"

float _color[3] = {0,0,0};
int _tam = 1;
int _eqRetaOrBresenham = EQRETA;
int _x,_y;
bool _clear=false, _undo=false;

GLWidget::GLWidget(QWidget *parent):
    QGLWidget(parent)
{
    connect(&timer, SIGNAL(timeout()), this, SLOT(updateGL()));
    timer.start(50);
}

void GLWidget::initializeGL() {
    glClearColor(0.5, 0.5, 0.5, 0.0);
    gluOrtho2D(0, WIDTH, 0, HEIGHT);
    glViewport(0, 0, WIDTH, HEIGHT);
}

void GLWidget::paintGL() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(_color[0], _color[1], _color[2]);
    glPointSize(_tam);

    if(_undo){
        _undo = false;
        if(firstPoint.size()>=1){
            if(firstClick){
                firstPoint.pop_back();
                secondPoint.pop_back();
            } else {
                firstClick = true;
                firstPoint.pop_back();
            }
        }
    }
    if(_clear){
        _clear = false;
        if(firstClick){
            firstPoint.clear();
            secondPoint.clear();
        } else {
            firstClick = true;
            firstPoint.clear();
            secondPoint.clear();
        }
    }

    if(!firstClick){
        if(_eqRetaOrBresenham == EQRETA)
            eqReta(firstPoint[firstPoint.size()-1].first,firstPoint[firstPoint.size()-1].second,_x,_y);
        else
            bresenham(firstPoint[firstPoint.size()-1].first,firstPoint[firstPoint.size()-1].second,_x,_y);

    }
    if(_eqRetaOrBresenham == EQRETA){
        for(int i = 0; i < secondPoint.size(); i++ ){
            eqReta(firstPoint[i].first,firstPoint[i].second,secondPoint[i].first,secondPoint[i].second); //mudar pra equação da reta
        }
        drawCourt(eqReta, eqCirc, eqSemiCirc);
    } else if (_eqRetaOrBresenham == BRESENHAM){
        for(int i = 0; i < secondPoint.size(); i++ ){
            bresenham(firstPoint[i].first,firstPoint[i].second,secondPoint[i].first,secondPoint[i].second);
        }
        drawCourt(bresenham, bresenham_circle, bresenham_semi_circle);
    }
    glFlush();
}

void GLWidget::resizeGL(int w, int h){}

void GLWidget::mousePressEvent(QMouseEvent *event)
{
    std::pair<int,int> point;
    point.first = event->x();
    point.second = 399-event->y();
    if(firstClick) {
        firstPoint.push_back(point);
        firstClick = false;
    } else {
        secondPoint.push_back(point);
        firstClick = true;
    }
}

void GLWidget::mouseMoveEvent(QMouseEvent *event){
    _x = event->x();
    _y = 399-event->y();
}


void drawCourt(void (*reta)(int,int,int,int), void (*circ)(int,int,int), void (*semiCirc)(int,int,int,int))
{
    reta(160,25,440,25);
    reta(160,175,440,175);
    reta(160,25,160,175);
    reta(440,25,440,175);

    circ(300,100,18);
    reta(300,25,300,175);

    semiCirc(424,100,67,-1);
    reta(424,167,440,167);
    reta(424,33,440,33);

    semiCirc(176,100,67,1);
    reta(160,167,176,167);
    reta(160,33,176,33);

    circ(220,100,18);
    reta(220,75,220,125);
    reta(160,75,220,75);
    reta(160,125,220,125);

    circ(380,100,18);
    reta(380,75,380,125);
    reta(380,75,440,75);
    reta(380,125,440,125);
}

