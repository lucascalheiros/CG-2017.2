
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>

// actual vector representing the camera's direction
float lx=0.0f,lz=-1.0f;
// XZ position of the camera
float x=0.0f,z=6.0f;

// all variables initialized to 1.0, meaning
// the triangle will initially be white
float red=1.0f, blue=1.0f, green=1.0f;

// angle for rotating triangle
float angle = 0.0f;

void init(void) {
    glClearColor(0.0, 0.0, 0.4, 0.1);
}

void drawMuseum()
{

glColor3f(0.9f, 0.9f, 0.0f);

// Front side
glPushMatrix();

        glTranslatef(0.0f, 1.3f, 0.0f);

        glBegin(GL_QUADS);  // Wall
            glVertex3f(-2, 0, 1);
            glVertex3f(2, 0, 1);
            glVertex3f(2, -1.5, 1);
            glVertex3f(-2,-1.5, 1);
        glEnd();

        glColor3f(0.9f, 0.9f, 0.9f);
        glBegin(GL_QUADS);  // Roof
            glVertex3f(-2, 0.1, 1);
            glVertex3f(2, 0.1, 1);
            glVertex3f(2,0, 1);
            glVertex3f(-2,0, 1);
        glEnd();

        glColor3f(0.9f, 0.9f, 0.0f);
        glBegin(GL_QUADS);  // Roof
            glVertex3f(-2, 0.33, 1);
            glVertex3f(2, 0.33, 1);
            glVertex3f(2,0.1, 1);
            glVertex3f(-2,0.1, 1);
        glEnd();

        glColor3f(0.9f, 0.9f, 0.9f);
        glBegin(GL_QUADS);  // Roof
            glVertex3f(-2, 0.4, 1);
            glVertex3f(2, 0.4, 1);
            glVertex3f(2,0.1, 1);
            glVertex3f(-2,0.1, 1);
        glEnd();

        glColor3f(0.9f, 0.9f, 0.0f);
        glBegin(GL_QUADS);  // Roof
            glVertex3f(-2, 0.6, 1);
            glVertex3f(2, 0.6, 1);
            glVertex3f(2,0.1, 1);
            glVertex3f(-2,0.1, 1);
        glEnd();

        glColor3f(0.9f, 0.9f, 0.9f);
        glBegin(GL_QUADS);  // Roof
            glVertex3f(-2, 0.7, 1);
            glVertex3f(2, 0.7, 1);
            glVertex3f(2,0.1, 1);
            glVertex3f(-2,0.1, 1);
        glEnd();


        glColor3f(1.0f, 1.0f, 1.0f);

        glBegin(GL_QUADS);  // Door
            glVertex3f(-0.3,-0.4,1.0001);
            glVertex3f(0.3,-0.4,1.0001);
            glVertex3f(0.3,-1.5,1.0001);
            glVertex3f(-0.3,-1.5,1.0001);
        glEnd();

        glBegin(GL_QUADS);  // Window Left
            glVertex3f(-1.5,-0.3,1.0001);
            glVertex3f(-0.75,-0.3,1.0001);
            glVertex3f(-0.75,-0.8,1.0001);
            glVertex3f(-1.5,-0.8,1.0001);
        glEnd();

        glBegin(GL_QUADS);  // Window Right
            glVertex3f(1.5,-0.3,1.0001);
            glVertex3f(0.75,-0.3,1.0001);
            glVertex3f(0.75,-0.8,1.0001);
            glVertex3f(1.5,-0.8,1.0001);
        glEnd();
    glPopMatrix();

glColor3f(0.9f, 0.9f, 0.0f);

    // Back side
    glPushMatrix();
        glTranslatef(0.0f, 1.3f, 0.0f);
        glBegin(GL_QUADS);  // Wall
            glVertex3f(-2,0.7,-1);
            glVertex3f(2,0.7,-2);
            glVertex3f(2,-1.5,-2);
            glVertex3f(-2,-1.5,-1);
        glEnd();
    glPopMatrix();

glColor3f(0.9f, 0.9f, 0.0f);

    // Right side
    glPushMatrix();

        glTranslatef(0.0f, 1.3f, 0.0f);

        glBegin(GL_QUADS);  // Wall
            glVertex3f(2,0.7,1);
            glVertex3f(2,0.7,-2);
            glVertex3f(2,-1.5,-2);
            glVertex3f(2,-1.5,1);
        glEnd();

        glColor3f(0.9f, 0.9f, 0.9f);
        glBegin(GL_QUADS);  // Window Left
            glVertex3f(1,0.3, 1.0);
            glVertex3f(1,0.3, -1.5);
            glVertex3f(1,-0.8, -1.5);
             glVertex3f(1,-0.8, 1.0);
        glEnd();

        glBegin(GL_QUADS);  // Window Right
           glVertex3f(1.5,-0.3,-1.0001);
            glVertex3f(0.75,-0.3,-1.0001);
            glVertex3f(0.75,-0.8,-1.0001);
            glVertex3f(1.5,-0.8,-1.0001);
        glEnd();

    glPopMatrix();

    glColor3f(0.9f, 0.9f, 0.0f);

    // Left side
    glPushMatrix();

        glTranslatef(0.0f, 1.3f, 0.0f);

        glBegin(GL_QUADS);  // Wall
            glVertex3f(-2,0.7,1);
            glVertex3f(-2,0.7,-1);
            glVertex3f(-2,-1.5,-1);
            glVertex3f(-2,-1.5,1);
        glEnd();

    glPopMatrix();
}

void changeSize(int w, int h)
{

// Prevent a divide by zero, when window is too short
// (you cant make a window of zero width).
if (h == 0)
h = 1;
float ratio = w * 1.0 / h;

// Use the Projection Matrix
glMatrixMode(GL_PROJECTION);

// Reset Matrix
glLoadIdentity();

// Set the viewport to be the entire window
glViewport(0, 0, w, h);

// Set the correct perspective.
gluPerspective(45.0f, ratio, 0.1f, 100.0f);

// Get Back to the Modelview
glMatrixMode(GL_MODELVIEW);
}

void renderScene(void)
{

// Clear Color and Depth Buffers

glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

// Reset transformations
glLoadIdentity();
// Set the camera
gluLookAt(x, 1.0f, z, x+lx, 1.0f, z+lz, 0.0f, 1.0f, 0.0f);

// Draw ground
glColor3f(0.0f, 0.3f, 0.3f);
    glBegin(GL_QUADS);
    glVertex3f(-100.0f, 0.0f, -100.0f);
    glVertex3f(-100.0f, 0.0f, 100.0f);
    glVertex3f( 100.0f, 0.0f, 100.0f);
    glVertex3f( 100.0f, 0.0f, -100.0f);
glEnd();


// Draw 36 SnowMen
//for(int i = -3; i < 3; i++)
//for(int j=-3; j < 3; j++) {
//glPushMatrix();
//glTranslatef(i*10.0,0,j * 10.0);
drawMuseum();
//glPopMatrix();
//}

glutSwapBuffers();
}

void processNormalKeys(unsigned char key, int x, int y)
{
    if (key == 27)
    exit(0);
}

void processSpecialKeys(int key, int xx, int yy)
{

float fraction = 0.5f;

switch (key) {
case GLUT_KEY_LEFT :
angle -= 0.05f;
lx = sin(angle);
lz = -cos(angle);
break;
case GLUT_KEY_RIGHT :
angle += 0.05f;
lx = sin(angle);
lz = -cos(angle);
break;
case GLUT_KEY_UP :
x += lx * fraction;
z += lz * fraction;
break;
case GLUT_KEY_DOWN :
x -= lx * fraction;
z -= lz * fraction;
break;
}
}

int main(int argc, char **argv)
{

// init GLUT and create window

glutInit(&argc, argv);
glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
glutInitWindowPosition(50,50);
glutInitWindowSize(800,600);
glutCreateWindow("House 3D");

init();

// register callbacks
glutDisplayFunc(renderScene);
glutReshapeFunc(changeSize);
glutIdleFunc(renderScene);
glutKeyboardFunc(processNormalKeys);
glutSpecialFunc(processSpecialKeys);

// OpenGL init
glEnable(GL_DEPTH_TEST);

// enter GLUT event processing cycle
glutMainLoop();

return 1;
}
