#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>
#include <GL/glut.h>
#include <QTimer>
#include <algorithm>


extern float _color[3];
extern int _tam;
extern int _eqRetaOrBresenham;
extern bool _clear;
extern bool _undo;

class GLWidget : public QGLWidget
{
    Q_OBJECT
public:
    explicit GLWidget(QWidget *parent = 0);
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

private:
    QTimer timer;
    int xAtPress, yAtPress;
    std::vector<std::pair<int,int>> firstPoint;
    std::vector<std::pair<int,int>> secondPoint;
    bool firstClick = true;
};

void drawCourt(void (*reta)(int,int,int,int), void (*circ)(int,int,int), void (*semiCirc)(int,int,int,int));
#endif // GLWIDGET_H
