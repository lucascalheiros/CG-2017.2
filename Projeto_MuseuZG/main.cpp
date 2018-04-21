
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>

// actual vector representing the camera's direction
float lx = 0.0f, lz = -1.0f;

// XZ position of the camera
//float x = 0.0f, z = 10.0f;
float x = -0.8f, z =-12.0f;

float door_angle = 0.0f;

// angle for rotating triangle
float angle = 0.0f;

void init(void) {
    glClearColor(0.0, 0.0, 0.4, 0.1);
}

void drawGround() {

    // Draw ground
    glColor3f(0.0f, 0.3f, 0.3f);
        glBegin(GL_QUADS);
        glVertex3f(-100.0f, 0.0f, -100.0f);
        glVertex3f(-100.0f, 0.0f, 100.0f);
        glVertex3f( 100.0f, 0.0f, 100.0f);
        glVertex3f( 100.0f, 0.0f, -100.0f);
    glEnd();

}

void drawSky() {

    // Draw sky
    glColor3f(0.5f, 0.8f, 0.9f);
    glBegin(GL_QUADS);
        glVertex3f(-100.0f, 4.0f, -100.0f);
        glVertex3f(-100.0f, 4.0f, 100.0f);
        glVertex3f( 100.0f, 4.0f, 100.0f);
        glVertex3f( 100.0f, 4.0f, -100.0f);
    glEnd();

}

void drawMuseum(){

glColor3f(0.9f, 0.9f, 0.0f);
glScalef(1.8f, 1.8f, 1.8f);

// Front side
glPushMatrix();

        glTranslatef(0.0f, 1.3f, 0.0f);

       glBegin(GL_QUADS);  // Wall
            glVertex3f(0.3, 0, 1);
            glVertex3f(2, 0, 1);
            glVertex3f(2, -1.5, 1);
            glVertex3f(0.3,-1.5, 1);
        glEnd();

        glBegin(GL_QUADS);  // Wall
			glVertex3f(-2, 0, 1);
			glVertex3f(-0.3, 0, 1);
			glVertex3f(-0.3, -1.5, 1);
			glVertex3f(-2,-1.5, 1);
		glEnd();

		glBegin(GL_QUADS);  // Wall
			glVertex3f(0.3, 0, 1);
			glVertex3f(-0.3, 0, 1);
			glVertex3f(-0.3, -0.25, 1);
			glVertex3f(0.3,-0.25, 1);
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
    glPopMatrix();

glColor3f(0.9f, 0.9f, 0.0f);

// Back side
    glPushMatrix();
        glTranslatef(0.0f, 1.3f, 0.0f);
        glBegin(GL_QUADS);  // Wall
            glVertex3f(-2,0.7,-10);
            glVertex3f(2,0.7,-10);
            glVertex3f(2,-1.5,-10);
            glVertex3f(-2,-1.5,-10);
        glEnd();
    glPopMatrix();

glColor3f(0.9f, 0.9f, 0.0f);

// Right side
    glPushMatrix();
        glTranslatef(0.0f, 1.3f, 0.0f);

        glBegin(GL_QUADS);  // Wall
            glVertex3f(2, 0.7, 1);
            glVertex3f(2, 0.7, -10);
            glVertex3f(2, -1.5, -10);
            glVertex3f(2, -1.5, 1);
        glEnd();

        glColor3f(0.9f, 0.9f, 0.9f);
        glBegin(GL_QUADS);  // Window Right
            glVertex3f(2.0001, -0.3, -2.5);
            glVertex3f(2.0001, -0.3, -1.75);
            glVertex3f(2.0001, -0.3 - 0.5, -1.75);
             glVertex3f(2.0001, -0.3 - 0.5, -2.5);
        glEnd();

        glBegin(GL_QUADS);  // Window Middle
           glVertex3f(2.0001, -0.3, -1.25);
            glVertex3f(2.0001, -0.3, -0.5);
            glVertex3f(2.0001, -0.3 - 0.5, -0.5);
             glVertex3f(2.0001, -0.3 - 0.5, -1.25);
        glEnd();

        glBegin(GL_QUADS);  // Window Left
           glVertex3f(2.0001, -0.3, 0.0);
            glVertex3f(2.0001, -0.3, 0.75);
            glVertex3f(2.0001, -0.3 - 0.5, 0.75);
             glVertex3f(2.0001, -0.3 - 0.5, 0.0);
        glEnd();
    glPopMatrix();

    glColor3f(0.9f, 0.9f, 0.0f);

// Left side
    glPushMatrix();
        glTranslatef(0.0f, 1.3f, 0.0f);
        glBegin(GL_QUADS);  // Wall
            glVertex3f(-2,0.7,1);
            glVertex3f(-2,0.7,-10);
            glVertex3f(-2,-1.5,-10);
            glVertex3f(-2,-1.5,1);
        glEnd();
    glPopMatrix();

// Top
    glPushMatrix();
        glColor3f(0.0f, 0.0f, 0.0f);
        glTranslatef(0.0f, 1.3f, 0.0f);
            glBegin(GL_QUADS);
                glVertex3f(-2.0f, 0.7f, -10.0f);
                glVertex3f(-2.0f, 0.7f, 1.0f);
                glVertex3f(2.0f, 0.7f, 1.0f);
                glVertex3f(2.0f, 0.7f, -10.0f);
            glEnd();
    glPopMatrix();
}

void drawPictures(float x, float y) {

glTranslatef(0.0f, 1.3f, 0.0f);

        glColor3f(1.0f, 0.0f, 0.1f);
        glBegin(GL_QUADS);
           glVertex3f(x, y + 0.1, -6.0);
            glVertex3f(x, y + 0.1, -4.5);
            glVertex3f(x, y - 0.6, -4.5);
             glVertex3f(x, y - 0.6, -6.0);
        glEnd();

        glColor3f(9.0f, 0.0f, 0.9f);
        glBegin(GL_QUADS);
           glVertex3f(x, y, -3.5);
            glVertex3f(x, y, -3.0);
            glVertex3f(x, y - 0.5, -3.0);
             glVertex3f(x, y -0.5, -3.5);
        glEnd();

        glColor3f(0.9f, 0.0f, 0.0f);
        glBegin(GL_QUADS);
            glVertex3f(x, y, -2.5);
            glVertex3f(x, y, -1.75);
            glVertex3f(x, y - 0.5, -1.75);
             glVertex3f(x, y - 0.5, -2.5);
        glEnd();

        glColor3f(0.9f, 0.0f, 0.9f);
        glBegin(GL_QUADS);
           glVertex3f(x, y, -1.25);
            glVertex3f(x, y, -0.5);
            glVertex3f(x, y - 0.5, -0.5);
             glVertex3f(x, y - 0.5, -1.25);
        glEnd();

        glColor3f(0.0f, 0.9f, 0.0f);
        glBegin(GL_QUADS);
           glVertex3f(x, y, 0.0);
            glVertex3f(x, y, 0.75);
            glVertex3f(x, y - 0.5, 0.75);
             glVertex3f(x, y - 0.5, 0.0);
        glEnd();
}

void drawDoor() {

    glPushMatrix();
		glTranslatef(-0.3f, 0.5f, 1);
        glRotatef (door_angle, 0,1,0);
    	glTranslatef(0.3f, 0, 0);
        glColor3f(1.0f, 1.0f, 1.0f);
        glScalef(0.6, 1.1, 0.1f);
        glutSolidCube(1.0);
    glPopMatrix();

}

void drawWindows() {

    glPushMatrix();

        glTranslatef(0.0f, 1.3f, 0.0f);
        glColor3f(1.0f, 1.0f, 1.0f);

        // Front side
         glBegin(GL_QUADS);  // Window Left
            glVertex3f(-1.5,-0.3,1.0001);
            glVertex3f(-0.75,-0.3,1.0001);
            glVertex3f(-0.75,-0.3 - 0.5,1.0001);
            glVertex3f(-1.5,-0.3 - 0.5,1.0001);
        glEnd();

        glBegin(GL_QUADS);  // Window Right
            glVertex3f(1.5,-0.3,1.0001);
            glVertex3f(0.75,-0.3,1.0001);
            glVertex3f(0.75,-0.3 - 0.5,1.0001);
            glVertex3f(1.5,-0.3 - 0.5,1.0001);
        glEnd();

        //Right side
        glBegin(GL_QUADS);  // Window Right
            glVertex3f(2.0001, -0.3, -2.5);
            glVertex3f(2.0001, -0.3, -1.75);
            glVertex3f(2.0001, -0.3 - 0.5, -1.75);
             glVertex3f(2.0001, -0.3 - 0.5, -2.5);
        glEnd();

        glBegin(GL_QUADS);  // Window Middle
           glVertex3f(2.0001, -0.3, -1.25);
            glVertex3f(2.0001, -0.3, -0.5);
            glVertex3f(2.0001, -0.3 - 0.5, -0.5);
             glVertex3f(2.0001, -0.3 - 0.5, -1.25);
        glEnd();

        glBegin(GL_QUADS);  // Window Left
           glVertex3f(2.0001, -0.3, 0.0);
            glVertex3f(2.0001, -0.3, 0.75);
            glVertex3f(2.0001, -0.3 - 0.5, 0.75);
             glVertex3f(2.0001, -0.3 - 0.5, 0.0);
        glEnd();

    glPopMatrix();
}

void drawInternWalls() {

    // divisory
     glPushMatrix();
        glTranslatef(1.189f, -1.2f, -6.5f);
        glColor3f(0.9f, 0.9f, 0.9f);
        glScalef(1.6, 2.5, 0.1);
        glutSolidCube(1.0);
    glPopMatrix();

    // small
    glPushMatrix();
        glTranslatef(-0.4f, -1.2f, -9.73f);
        glColor3f(0.9f, 0.9f, 0.9f);
        glScalef(0.1, 4.0, 0.5);
        glutSolidCube(1.0);
    glPopMatrix();

    // small2
    glPushMatrix();
        glTranslatef(0.4f, -1.2f, -6.7f);
        glColor3f(0.9f, 0.9f, 0.9f);
        glScalef(0.1, 2.5, 0.5);
        glutSolidCube(1.0);
    glPopMatrix();

    // small3
    glPushMatrix();
        glTranslatef(-0.4f, -1.2f, -6.7f);
        glColor3f(0.9f, 0.9f, 0.9f);
        glScalef(0.1, 4.0, 0.5);
        glutSolidCube(1.0);
    glPopMatrix();

    // divisory2
    glPushMatrix();
        glTranslatef(-0.7f, -1.2f, -6.5f);
        glColor3f(0.9f, 0.9f, 0.9f);
        glScalef(0.7, 4.0, 0.1);
        glutSolidCube(1.0);
    glPopMatrix();

    // divisory3
    glPushMatrix();
        glTranslatef(-1.0f, -1.2f, -4.0f);
        glColor3f(0.9f, 0.9f, 0.9f);
        glScalef(0.1, 4.0, 5.0);
        glutSolidCube(1.0);
    glPopMatrix();

}

void drawBank(GLfloat z) {

    //acento
    glPushMatrix();
        glTranslatef(-1.5f, -1.0f, -0.6f + z);
        glColor3f(0.3f, 0.0f, 0.0f);
        glScalef(0.5, 0.1, 1.0);
        glutSolidCube(1.0);
    glPopMatrix();

    //pés
    glPushMatrix();
        glTranslatef(-1.6f, -1.5f, -0.3f+ z);
        glColor3f(0.3f, 0.0f, 0.0f);
        glScalef(0.1, 1.0, 0.1);
        glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-1.4f, -1.5f, -0.3f+ z);
        glColor3f(0.3f, 0.0f, 0.0f);
        glScalef(0.1, 1.0, 0.1);
        glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-1.4f, -1.5f, -0.9f+ z);
        glColor3f(0.3f, 0.0f, 0.0f);
        glScalef(0.1, 1.0, 0.1);
        glutSolidCube(1.0);
    glPopMatrix();

     glPushMatrix();
        glTranslatef(-1.6f, -1.5f, -0.9f+ z);
        glColor3f(0.3f, 0.0f, 0.0f);
        glScalef(0.1, 1.0, 0.1);
        glutSolidCube(1.0);
     glPopMatrix();

}

void drawChair(GLfloat z) {

    //acento
    glPushMatrix();
        glTranslatef(-1.2f, -1.0f, 0.2f);
        glColor3f(0.3f, 0.0f, 0.0f);
        glScalef(0.5, 0.1, 0.46);
        glutSolidCube(1.0);
    glPopMatrix();

    //pés
    glPushMatrix();
        glTranslatef(-1.35f, -1.5f, 0.38f+ z);
        glColor3f(0.3f, 0.0f, 0.0f);
        glScalef(0.1, 1.0, 0.1);
        glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-1.05f, -1.5f, 0.38f+ z);
        glColor3f(0.3f, 0.0f, 0.0f);
        glScalef(0.1, 1.0, 0.1);
        glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-1.05f, -1.5f, 0.1f+ z);
        glColor3f(0.3f, 0.0f, 0.0f);
        glScalef(0.1, 1.0, 0.1);
        glutSolidCube(1.0);
    glPopMatrix();

     glPushMatrix();
        glTranslatef(-1.35f, -1.5f, 0.1f+ z);
        glColor3f(0.3f, 0.0f, 0.0f);
        glScalef(0.1, 1.0, 0.1);
        glutSolidCube(1.0);
    glPopMatrix();

    // encosto
    glPushMatrix();
        glTranslatef(-1.2f, -1.0f, 0.15f);
        glRotatef(90.0f, 1, 0, 0);
        glTranslatef(0.0f, 0.28f, -0.25f);
        glColor3f(0.3f, 0.0f, 0.0f);
        glScalef(0.5, 0.05, 0.6);
        glutSolidCube(1.0);
    glPopMatrix();

}

void drawTable(GLfloat z) {

    // tampo
    glPushMatrix();
        glTranslatef(-1.2f, -0.75f, -0.6f + z);
        glColor3f(0.3f, 0.0f, 0.0f);
        glScalef(0.7, 0.05, 0.7);
        glutSolidCube(1.0);
    glPopMatrix();

    //pés
    glPushMatrix();
        glTranslatef(-1.4f, -1.5f, -0.4f+ z);
        glColor3f(0.3f, 0.0f, 0.0f);
        glScalef(0.05, 1.5, 0.05);
        glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-1.0f, -1.5f, -0.4f+ z);
        glColor3f(0.3f, 0.0f, 0.0f);
        glScalef(0.05, 1.5, 0.05);
        glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-1.0f, -1.5f, -0.8f+ z);
        glColor3f(0.3f, 0.0f, 0.0f);
        glScalef(0.05, 1.5, 0.05);
        glutSolidCube(1.0);
    glPopMatrix();

     glPushMatrix();
        glTranslatef(-1.4f, -1.5f, -0.8f+ z);
        glColor3f(0.3f, 0.0f, 0.0f);
        glScalef(0.05, 1.5, 0.05);
        glutSolidCube(1.0);
    glPopMatrix();



}

void drawAirConditioning() {



}

void reshape(int w, int h)
{

// Prevent a divide by zero, when window is too short
// (you cant make a window of zero width).
if (h == 0) h = 1;

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

    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

// Clear Color and Depth Buffers
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

// Reset transformations
glLoadIdentity();
// Set the camera
gluLookAt(x, 1.0f, z, x+lx, 1.0f, z+lz, 0.0f, 1.0f, 0.0f);


drawGround();
drawSky();

drawMuseum();

drawDoor();
drawWindows();
drawPictures(1.998, -0.3);
drawBank(-2.0f);
drawChair(0.0f);
drawTable(0.0f);
drawInternWalls();

glFlush();
glutSwapBuffers();
}

void processNormalKeys(unsigned char key, int x, int y) {
    switch(key){
        case 'o':
            if(door_angle <= 118.0f) door_angle += 2.0f;
            glutPostRedisplay();
        break;

        case 'c':
            if(door_angle >= 2.0f) door_angle -= 2.0f;
            glutPostRedisplay();
        break;

        case 27:
            exit(0);
        break;
    }
}

void processSpecialKeys(int key, int xx, int yy) {

    float fraction = 0.9f;

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
glutInitWindowPosition(100,100);
glutInitWindowSize(800,600);
glutCreateWindow("Museum ZG");

init();

// register callbacks
glutDisplayFunc(renderScene);
glutReshapeFunc(reshape);
glutIdleFunc(renderScene);
glutKeyboardFunc(processNormalKeys);
glutSpecialFunc(processSpecialKeys);

// OpenGL init
glEnable(GL_DEPTH_TEST);

// enter GLUT event processing cycle
glutMainLoop();

return 1;
}
