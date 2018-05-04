#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>

// actual vector representing the camera's direction
float lx = 0.0f, ly = 0,lz = -1.0f;

// XZ position of the camera
//float x = 0.0f, z = 10.0f;
float x = 0.0f,y = 1, z =10.0f;

float verticalVectorFix;
float door_angle = 0.0f;

// angle for rotating triangle
float angleXZ = 0.0f, angleY = 0;

void init(void) {
    glClearColor(0.0, 0.0, 0.4, 0.1);

     glEnable(GL_COLOR_MATERIAL);
     glEnable(GL_LIGHTING);
     glEnable(GL_LIGHT0);
     glEnable(GL_LIGHT1);
     glEnable(GL_LIGHT2);
     glEnable(GL_DEPTH_TEST);
     glShadeModel(GL_SMOOTH);
}

void ilumination (void) {
        GLfloat luzAmbiente[4]={0.8,0.8,0.8,1.0};
        GLfloat luzDifusa[4]={0.1,0.1,0.1,1.0};          // "cor"
        GLfloat luzEspecular[4]={0.7, 0.7, 0.7, 1.0};// "brilho"
        GLfloat posicaoLuz[4]={0.0, -1.0, 0.0, 1.0};
        GLfloat posicaoLuz1[4]={0.0, 1.0, -3.0, 1.0};
        GLfloat posicaoLuz2[4]={0.0, 1.0, -6.0, 1.0};

        GLfloat especularidade[4]={1,1,1,1};
        GLint especMaterial = 60;

        //glMaterialfv(GL_FRONT,GL_SPECULAR, especularidade);
       // glMateriali(GL_FRONT,GL_SHININESS,especMaterial);

        glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);

        glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular );
        glPushMatrix();
        glTranslatef(0, 0, 0);
        glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa );
        glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz );
        glPopMatrix();

     /*   glLightfv(GL_LIGHT1, GL_DIFFUSE, luzDifusa );
        glLightfv(GL_LIGHT1, GL_POSITION, posicaoLuz1 );
        glLightfv(GL_LIGHT2, GL_DIFFUSE, luzDifusa );
        glLightfv(GL_LIGHT2, GL_POSITION, posicaoLuz2 );*/


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
        glVertex3f(-100.0f, 50.0f, -100.0f);
        glVertex3f(-100.0f, 50.0f, 100.0f);
        glVertex3f( 100.0f, 50.0f, 100.0f);
        glVertex3f( 100.0f, 50.0f, -100.0f);
    glEnd();

}

void drawMuseum(){

glColor3f(1, 1, 0.0);
glScalef(1.89f, 1.89f, 1.89f);

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


        glColor3f(0.8f, 0.8f, 0.8f);
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

        glColor3f(0.8f, 0.8f, 0.8f);
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

        glColor3f(0.8f, 0.8f, 0.8f);
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

// windows covers

    glColor3f(0.85, 0.85, 0.0);

    //upper
    glPushMatrix();
        glTranslatef(-1.1f, 1.05f, 1.2f);
        glScalef(1.0, 0.05, 0.2);
        glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(1.1f, 1.05f, 1.2f);
        glScalef(1.0, 0.05, 0.2);
        glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(2.17f, 1.05f, -0.8f);
        glScalef(0.3, 0.05, 3.5);
        glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(2.17f, 0.45f, -0.8f);
        glScalef(0.3, 0.05, 3.5);
        glutSolidCube(1.0);
    glPopMatrix();

    //down
    glPushMatrix();
        glTranslatef(-1.1f, 0.40f, 1.2f);
        glScalef(1.0, 0.05, 0.2);
        glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(1.1f, 0.40f, 1.2f);
        glScalef(1.0, 0.05, 0.2);
        glutSolidCube(1.0);
    glPopMatrix();

    //sides
    glPushMatrix();
        glTranslatef(-0.62f, 0.73f, 1.15f);
        glScalef(0.05, 0.71, 0.2);
        glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-1.62f, 0.73f, 1.15f);
        glScalef(0.05, 0.71, 0.2);
        glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0.62f, 0.73f, 1.15f);
        glScalef(0.05, 0.71, 0.2);
        glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(1.62f, 0.73f, 1.15f);
        glScalef(0.05, 0.71, 0.2);
        glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(2.1f, 0.74f, 0.98f);
        glScalef(0.3, 0.64, 0.05);
        glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(2.1f, 0.74f, -2.52f);
        glScalef(0.3, 0.64, 0.05);
        glutSolidCube(1.0);
    glPopMatrix();

    // cobertura da porta

    glPushMatrix();
        glTranslatef(-0.5f, -1.2f, 1.2f);
        glColor3f(0.85f, 0.85f, 0.0f);
        glScalef(0.1, 5.0, 0.3);
        glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0.5f, -1.2f, 1.2f);
        glColor3f(0.85f, 0.85f, 0.0f);
        glScalef(0.1, 5.0, 0.3);
        glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0.0f, 1.3f, 1.2f);
        glColor3f(0.85f, 0.85f, 0.0f);
        glScalef(1.1, 0.1, 0.3);
        glutSolidCube(1.0);
    glPopMatrix();

// detalhes de cima

    glPushMatrix();
        glTranslatef(0.0f, 1.715f, 1.05f);
        glColor3f(0.9f, 0.9f, 0.9f);
        glScalef(4.0, 0.1, 0.07);
        glutSolidCube(1.0);
    glPopMatrix();

    for(int i = 0; i < 27; i++) {
        glPushMatrix();
            glTranslatef(-1.95f + 0.15f*i, 1.57f, 1.05f);
            glColor3f(0.9f, 0.9f, 0.9f);
            glScalef(0.09, 0.05, 0.05);
            glutSolidCube(1.0);
        glPopMatrix();
    }

    glPushMatrix();
        glTranslatef(0.0f, 1.975f, 1.05f);
        glColor3f(0.9f, 0.9f, 0.9f);
        glScalef(4.0, 0.1, 0.07);
        glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0.0f, 1.375f, 1.05f);
        glColor3f(0.9f, 0.9f, 0.9f);
        glScalef(4.0, 0.1, 0.07);
        glutSolidCube(1.0);
    glPopMatrix();

// cilindros
    GLUquadricObj *quadric;

    glPushMatrix();
        glTranslatef(-0.3f, 1.3f, 1.3f);
        glColor3f(0.9f, 0.9f, 0.9f);
        glRotatef(90, 1,0,0);
        quadric = gluNewQuadric();
        gluCylinder(quadric, 0.05, 0.05, 1.8, 22, 3);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0.3f, 1.3f, 1.3f);
        glColor3f(0.9f, 0.9f, 0.9f);
        glRotatef(90, 1,0,0);
        quadric = gluNewQuadric();
        gluCylinder(quadric, 0.05, 0.05, 1.8, 22, 3);
    glPopMatrix();

}

void drawPictures(GLfloat x, GLfloat y, GLfloat z) {


glTranslatef(0.0f, 1.3f, 0.0f);

    // corredor

    glPushMatrix();
        glTranslatef(-1.05f+ x, -0.30f + y, -2.0f + z);
        glColor3f(0.1f, 0.1f, 0.1f);
        glScalef(0.05, 0.7, 0.9);
        glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-1.059f+ x, -0.30f + y, -2.02f + z);
        glColor3f(0.9f, 0.0f, 0.0f);
        glScalef(0.04, 0.65, 0.8);
        glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-1.05f+ x, -0.30f + y, -3.5f + z);
        glColor3f(0.1f, 0.1f, 0.1f);
        glScalef(0.05, 0.7, 0.9);
        glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-1.059f+ x, -0.30f + y, -3.52f + z);
        glColor3f(0.0f, 0.0f, 0.9f);
        glScalef(0.04, 0.65, 0.8);
        glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-1.05f+ x, -0.30f + y, -5.0f + z);
        glColor3f(0.1f, 0.1f, 0.1f);
        glScalef(0.05, 0.7, 0.9);
        glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-1.059f+ x, -0.30f + y, -5.02f + z);
        glColor3f(0.0f, 0.7f, 0.0f);
        glScalef(0.04, 0.65, 0.8);
        glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-1.95f+ x, -0.30f + y, -2.0f + z);
        glColor3f(0.1f, 0.1f, 0.1f);
        glScalef(0.05, 0.7, 0.9);
        glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-1.941f+ x, -0.30f + y, -2.02f + z);
        glColor3f(0.0f, 0.7f, 0.0f);
        glScalef(0.04, 0.65, 0.8);
        glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-1.95f+ x, -0.30f + y, -3.5f + z);
        glColor3f(0.1f, 0.1f, 0.1f);
        glScalef(0.05, 0.7, 0.9);
        glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-1.941f+ x, -0.30f + y, -3.52f + z);
        glColor3f(0.9f, 0.f, 0.0f);
        glScalef(0.04, 0.65, 0.8);
        glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-1.95f+ x, -0.30f + y, -5.0f + z);
        glColor3f(0.1f, 0.1f, 0.1f);
        glScalef(0.05, 0.7, 0.9);
        glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-1.941f+ x, -0.30f + y, -5.02f + z);
        glColor3f(0.0f, 0.0f, 0.9f);
        glScalef(0.04, 0.65, 0.8);
        glutSolidCube(1.0);
    glPopMatrix();

    // lado direito
    glPushMatrix();
        glTranslatef(1.95f+ x, -0.20f + y, -0.5f + z);
        glColor3f(0.1f, 0.1f, 0.1f);
        glScalef(0.05, 0.9, 0.9);
        glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(1.941f+ x, -0.20f + y, -0.5f + z);
        glColor3f(0.9f, 0.2f, 0.0f);
        glScalef(0.04, 0.85, 0.8);
        glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(1.95f+ x, -0.20f + y, -2.0f + z);
        glColor3f(0.1f, 0.1f, 0.1f);
        glScalef(0.05, 0.9, 0.9);
        glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(1.941f+ x, -0.20f + y, -2.0f + z);
        glColor3f(0.9f, 0.0f, 0.9f);
        glScalef(0.04, 0.85, 0.8);
        glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(1.95f+ x, -0.20f + y, -3.5f + z);
        glColor3f(0.1f, 0.1f, 0.1f);
        glScalef(0.05, 0.9, 0.9);
        glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(1.941f+ x, -0.20f + y, -3.5f + z);
        glColor3f(0.5f, 0.8f, 0.8f);
        glScalef(0.04, 0.85, 0.8);
        glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(1.95f+ x, -0.20f + y, -5.0f + z);
        glColor3f(0.1f, 0.1f, 0.1f);
        glScalef(0.05, 0.9, 0.9);
        glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(1.941f+ x, -0.20f + y, -5.0f + z);
        glColor3f(0.7f, 0.0f, 0.0f);
        glScalef(0.04, 0.85, 0.8);
        glutSolidCube(1.0);
    glPopMatrix();


    // fim do corredor

    glPushMatrix();
        glTranslatef(-1.50f+ x, -0.40f + y, 2.50f - 1.05 + z);
        glColor3f(0.1f, 0.1f, 0.1f);
        glScalef(0.7, 0.7, 0.05);
        glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-1.50f+ x, -0.40f + y, 2.491f - 1.05 + z);
        glColor3f(0.0f, 0.0f, 0.9f);
        glScalef(0.6, 0.65, 0.04);
        glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-1.50f+ x, -0.40f + y, 2.47f - 1.05 + z);
        glColor3f(0.9f, 0.0f, 0.0f);
        glScalef(0.4, 0.45, 0.02);
        glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-1.50f+ x, -0.40f + y, 2.45f - 1.05 + z);
        glColor3f(0.0f, 0.7f, 0.0f);
        glScalef(0.3, 0.35, 0.01);
        glutSolidCube(1.0);
    glPopMatrix();


    // quadro por trás da parede
    glPushMatrix();
        glTranslatef(1.95f+ x, -0.20f + y, -8.0f + z);
        glColor3f(0.1f, 0.1f, 0.1f);
        glScalef(0.05, 0.9, 1.2);
        glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(1.941f+ x, -0.20f + y, -8.0f + z);
        glColor3f(0.7f, 0.6f, 0.0f);
        glScalef(0.04, 0.85, 1.1);
        glutSolidCube(1.0);
    glPopMatrix();


}

void drawDoor() {

    glPushMatrix();
		glTranslatef(-0.3f, 0.5f, 1);
        glRotatef (door_angle, 0,1,0);
    	glTranslatef(0.3f, 0, 0);
        glColor3f(0.7f, 0.7f, 0.7f);
        glScalef(0.6, 1.1, 0.1f);
        glutSolidCube(1.0);
    glPopMatrix();

}

void drawWindows() {

    glPushMatrix();

        glTranslatef(0.0f, 1.3f, 0.0f);

        glLineWidth(3);
        glBegin(GL_LINES);
            glColor3f(0.2f, 0.2f, 0.2f);
            glVertex3f(-0.75, -0.4, 1.008);
            glVertex3f(-1.5, -0.4, 1.008);
            glVertex3f(-0.75, -0.5, 1.008);
            glVertex3f(-1.5, -0.5, 1.008);
            glVertex3f(-0.75, -0.6, 1.008);
            glVertex3f(-1.5, -0.6, 1.008);
            glVertex3f(-0.75, -0.7, 1.008);
            glVertex3f(-1.5, -0.7, 1.008);

            glVertex3f(0.75, -0.4, 1.008);
            glVertex3f(1.5, -0.4, 1.008);
            glVertex3f(0.75, -0.5, 1.008);
            glVertex3f(1.5, -0.5, 1.008);
            glVertex3f(0.75, -0.6, 1.008);
            glVertex3f(1.5, -0.6, 1.008);
            glVertex3f(0.75, -0.7, 1.008);
            glVertex3f(1.5, -0.7, 1.008);

            glVertex3f(2.008, -0.4, -2.5);
            glVertex3f(2.008, -0.4, -1.75);
            glVertex3f(2.008, -0.5, -2.5);
            glVertex3f(2.008, -0.5, -1.75);
            glVertex3f(2.008, -0.6, -2.5);
            glVertex3f(2.008, -0.6, -1.75);
            glVertex3f(2.008, -0.7, -2.5);
            glVertex3f(2.008, -0.7, -1.75);

            glVertex3f(2.008, -0.4, -1.25);
            glVertex3f(2.008, -0.4, -0.5);
            glVertex3f(2.008, -0.5, -1.25);
            glVertex3f(2.008, -0.5, -0.5);
            glVertex3f(2.008, -0.6, -1.25);
            glVertex3f(2.008, -0.6, -0.5);
            glVertex3f(2.008, -0.7, -1.25);
            glVertex3f(2.008, -0.7, -0.5);

            glVertex3f(2.008, -0.4, 0.0);
            glVertex3f(2.008, -0.4, 0.75);
            glVertex3f(2.008, -0.5, 0.0);
            glVertex3f(2.008, -0.5, 0.75);
            glVertex3f(2.008, -0.6, 0.0);
            glVertex3f(2.008, -0.6, 0.75);
            glVertex3f(2.008, -0.7, 0.0);
            glVertex3f(2.008, -0.7, 0.75);
        glEnd();

        glColor3f(0.7f, 0.7f, 0.7f);

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
        glColor3f(0.7f, 0.7f, 0.7f);
            glVertex3f(2.0002, -0.3, -2.5);
            glVertex3f(2.0002, -0.3, -1.75);
            glVertex3f(2.0002, -0.3 - 0.5, -1.75);
             glVertex3f(2.0002, -0.3 - 0.5, -2.5);
        glEnd();

        glBegin(GL_QUADS);  // Window Middle
           glVertex3f(2.0002, -0.3, -1.25);
            glVertex3f(2.0002, -0.3, -0.5);
            glVertex3f(2.0002, -0.3 - 0.5, -0.5);
             glVertex3f(2.0002, -0.3 - 0.5, -1.25);
        glEnd();

        glBegin(GL_QUADS);  // Window Left
           glVertex3f(2.0002, -0.3, 0.0);
            glVertex3f(2.0002, -0.3, 0.75);
            glVertex3f(2.0002, -0.3 - 0.5, 0.75);
             glVertex3f(2.0002, -0.3 - 0.5, 0.0);
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
        glTranslatef(-0.4f, -1.3001f, -9.73f);
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
        glTranslatef(-0.4f, -1.3001, -6.7f);
        glColor3f(0.9f, 0.9f, 0.9f);
        glScalef(0.1, 4.0, 0.5);
        glutSolidCube(1.0);
    glPopMatrix();

    // divisory2
    glPushMatrix();
        glTranslatef(-0.7f, -1.3001f, -6.5f);
        glColor3f(0.9f, 0.9f, 0.9f);
        glScalef(0.7, 4.0, 0.1);
        glutSolidCube(1.0);
    glPopMatrix();

    // divisory3
    glPushMatrix();
        glTranslatef(-1.0f, -1.3001f, -3.5f);
        glColor3f(0.9f, 0.9f, 0.9f);
        glScalef(0.1, 4.0, 6.0);
        glutSolidCube(1.0);
    glPopMatrix();

}

void drawBank(GLfloat x, GLfloat z) {

    //acento
    glPushMatrix();
        glTranslatef(-1.5f+ x, -1.0f, -0.6f + z);
        glColor3f(0.3f, 0.0f, 0.0f);
        glScalef(0.5, 0.1, 1.0);
        glutSolidCube(1.0);
    glPopMatrix();

    //pés
    glPushMatrix();
        glTranslatef(-1.6f+ x, -1.5f, -0.3f+ z);
        glColor3f(0.3f, 0.0f, 0.0f);
        glScalef(0.1, 1.0, 0.1);
        glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-1.4f+ x, -1.5f, -0.3f+ z);
        glColor3f(0.3f, 0.0f, 0.0f);
        glScalef(0.1, 1.0, 0.1);
        glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-1.4f+ x, -1.5f, -0.9f+ z);
        glColor3f(0.3f, 0.0f, 0.0f);
        glScalef(0.1, 1.0, 0.1);
        glutSolidCube(1.0);
    glPopMatrix();

     glPushMatrix();
        glTranslatef(-1.6f+ x, -1.5f, -0.9f+ z);
        glColor3f(0.3f, 0.0f, 0.0f);
        glScalef(0.1, 1.0, 0.1);
        glutSolidCube(1.0);
     glPopMatrix();

}

void drawChair(GLfloat x, GLfloat z) {

    //acento
    glPushMatrix();
        glTranslatef(-1.2f + x, -1.0f, 0.2f+ z);
        glColor3f(0.3f, 0.0f, 0.0f);
        glScalef(0.4, 0.04, 0.4);
        glutSolidCube(1.0);
    glPopMatrix();

    //pés
    glPushMatrix();
        glTranslatef(-1.35f+ x, -1.5f, 0.35f+ z);
        glColor3f(0.3f, 0.0f, 0.0f);
        glScalef(0.05, 1.0, 0.05);
        glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-1.05f+ x, -1.5f, 0.35f+ z);
        glColor3f(0.3f, 0.0f, 0.0f);
        glScalef(0.05, 1.0, 0.05);
        glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-1.05f+ x, -1.5f, 0.1f+ z);
        glColor3f(0.3f, 0.0f, 0.0f);
        glScalef(0.05, 1.0, 0.05);
        glutSolidCube(1.0);
    glPopMatrix();

     glPushMatrix();
        glTranslatef(-1.35f+ x, -1.5f, 0.1f+ z);
        glColor3f(0.3f, 0.0f, 0.0f);
        glScalef(0.05, 1.0, 0.05);
        glutSolidCube(1.0);
    glPopMatrix();

    // encosto
    glPushMatrix();
        glTranslatef(-1.2f+ x, -1.05f, 0.1f+ z);
        glRotatef(90.0f, 1, 0, 0);
        glTranslatef(0.0f, 0.28f, -0.25f);
        glColor3f(0.3f, 0.0f, 0.0f);
        glScalef(0.4, 0.04, 0.4);
        glutSolidCube(1.0);
    glPopMatrix();

}

void drawTable(GLfloat x, GLfloat z) {

    // tampo
    glPushMatrix();
        glTranslatef(-1.2f+ x, -0.85f, -0.6f + z);
        glColor3f(0.3f, 0.0f, 0.0f);
        glScalef(0.7, 0.05, 0.7);
        glutSolidCube(1.0);
    glPopMatrix();

    //pés
    glPushMatrix();
        glTranslatef(-1.4f+ x, -1.5f, -0.4f+ z);
        glColor3f(0.3f, 0.0f, 0.0f);
        glScalef(0.05, 1.3, 0.05);
        glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-1.0f+ x, -1.5f, -0.4f+ z);
        glColor3f(0.3f, 0.0f, 0.0f);
        glScalef(0.05, 1.3, 0.05);
        glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-1.0f+ x, -1.5f, -0.8f+ z);
        glColor3f(0.3f, 0.0f, 0.0f);
        glScalef(0.05, 1.3, 0.05);
        glutSolidCube(1.0);
    glPopMatrix();

     glPushMatrix();
        glTranslatef(-1.4f+ x, -1.5f, -0.8f+ z);
        glColor3f(0.3f, 0.0f, 0.0f);
        glScalef(0.05, 1.3, 0.05);
        glutSolidCube(1.0);
    glPopMatrix();



}

void drawRack(GLfloat x, GLfloat y, GLfloat z) {

    // partition1
    glPushMatrix();
        glTranslatef(-0.8f + x, -1.0f , -6.7f);
        glColor3f(0.3f, 0.0f, 0.0f);
        glScalef(0.5, 0.04, 0.4);
        glutSolidCube(1.0);
    glPopMatrix();

    // partition2
    glPushMatrix();
        glTranslatef(-0.8f + x, -1.0f + y, -6.7f + z);
        glColor3f(0.3f, 0.0f, 0.0f);
        glScalef(0.5, 0.04, 0.4);
        glutSolidCube(1.0);
    glPopMatrix();

    // partition3
    glPushMatrix();
        glTranslatef(-0.8f + x, -1.2f + y, -6.7f+ z);
        glColor3f(0.3f, 0.0f, 0.0f);
        glScalef(0.5, 0.04, 0.4);
        glutSolidCube(1.0);
    glPopMatrix();

    // partition4
    glPushMatrix();
        glTranslatef(-0.8f + x, -1.4f + y, -6.7f+ z);
        glColor3f(0.3f, 0.0f, 0.0f);
        glScalef(0.5, 0.04, 0.4);
        glutSolidCube(1.0);
    glPopMatrix();

    //planos laterais
    glPushMatrix();
        glTranslatef(-0.55f + x, -1.54f+ y, -6.72f+ z);
        glColor3f(0.5f, 0.f, 0.0f);
        glScalef(0.03, 1.1, 0.4);
        glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-1.04f+ x, -1.54f+ y, -6.72f+ z);
        glColor3f(0.5f, 0.0f, 0.0f);
        glScalef(0.03, 1.1, 0.4);
        glutSolidCube(1.0);
    glPopMatrix();

}

void drawObjectsRack(GLfloat x, GLfloat y, GLfloat z) {

    // teaplot
     glPushMatrix();
        glTranslatef(-0.75f+ x, -0.90f + y, -6.8f + z);
        glColor3f(0.0f, 0.0f, 0.9f);
        glScalef(0.08, 0.08, 0.08);
        glutWireTeapot(1.0);
    glPopMatrix();

    // torus
    glPushMatrix();
        glTranslatef(-0.75f+ x, -0.72f + y, -6.8f + z);
        glColor3f(0.0f, 0.0f, 0.9f);
        glScalef(0.2, 0.2, 0.2);
        glRotatef(-50, 1,0,0);
        glutWireTorus(0.1, 0.3, 20,20);
    glPopMatrix();

    // object
    glPushMatrix();
        glTranslatef(-0.75f + x, -0.52f + y, -6.8f+ z);
       glColor3f(0.0f, 0.0f, 0.9f);
        glScalef(0.8, 0.8, 0.8);
        glutWireSphere(0.1, 10, 20);
    glPopMatrix();

}

void drawAirConditioning(GLfloat x, GLfloat z) {

    glPushMatrix();
        glTranslatef(1.8f+ x, 0.40f, -7.5f+ z);
        glColor3f(1.0f, 1.0f, 1.0f);
        glScalef(0.3, 0.15, 0.5);
        glutSolidCube(1.0);
    glPopMatrix();
}

void drawTV (GLfloat x, GLfloat y, GLfloat z) {

    glPushMatrix();
        glTranslatef(-1.05f+ x, -0.60f + y, -1.0f + z);
        glColor3f(0.1f, 0.1f, 0.0f);
        glScalef(0.05, 0.3, 0.5);
        glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-1.059f+ x, -0.60f + y, -1.02f + z);
        glColor3f(0.2f, 0.2f, 0.2f);
        glScalef(0.04, 0.25, 0.4);
        glutSolidCube(1.0);
    glPopMatrix();

}

void drawSculture(){
	GLfloat x, y,z;
	int i;
	x=1;
	y=0.5;
	z=-3;

	glTranslatef(0.0f, -1.3f, 0.0f);

	glPushMatrix();
		glTranslatef(1,0.25,-1.5);
		glColor3f(0.1f, 0.1f, 0.0f);
		glScalef(0.2, 0.5, 0.2);
		glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(1,0.25,-3);
		glColor3f(1, 1, 1);
		glScalef(0.2, 0.5, 0.2);
		glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(1,0.25,-4.5);
		glColor3f(0.1f, 0.1f, 0.0f);
		glScalef(0.2, 0.5, 0.2);
		glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(1,0.25,-8.5);
		glColor3f(0.1f, 0.1f, 0.0f);
		glScalef(0.2, 0.5, 0.2);
		glutSolidCube(1.0);
	glPopMatrix();

	//ecultura 1
	glPushMatrix();
		glColor3f(0.1f, 0.1f, 0.0f);
		glTranslatef(x, y, z);
		glBegin(GL_POLYGON);
			for(i=0; i<1000; i++){
				glVertex3f(cosf(M_PI*i/100)*0.1, 0.0001*i, sinf(M_PI*i/100)*0.1);
			}
		glEnd();
	glPopMatrix();

	//ecultura 2
	glPushMatrix();
		glColor3f(0.5, 0.5, 0.5);
		glTranslatef(x, y, -1.5);
		glBegin(GL_POLYGON);
			double c;
			float x1,z1;
			for(i=0; i<1000; i++){
				c = i/100;
				x1 = cosf(M_PI*i/100)*(1/c)*0.1;
				z1 = sinf(M_PI*i/100)*(1/c)*0.1;
				x1 = x1>1||x1<-1?0:x1;
				z1 = z1>1||z1<-1?0:z1;
				glVertex3d(x1, 0.0002*i, z1);
			}

		glEnd();
	glPopMatrix();

	//ecultura 3
	glPushMatrix();
		glTranslatef(1,0.5,-4.5);
		glColor3f(0, 0, 0);
		glScalef(0.03, 0.2, 0.06);
		glutSolidCube(1.0);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(1,0.5,-4.5);
		glColor3f(0.3, 0.3, 0.3);
		glScalef(0.015, 0.25, 0.03);
		glutSolidCube(1.0);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(1,0.55,-4.5);
		glColor3f(0.3, 0.3, 0.3);
		glScalef(0.015, 0.1, 0.08);
		glutSolidCube(1.0);
	glPopMatrix();

	//ecultura 4
	glPushMatrix();
		glTranslatef(1,0.5,-8.5);
		glColor3f(0, 0, 0);
		glBegin(GL_POLYGON);
			float y1;
			for(i=0; i<1000; i++){
				c = i/100;
				x1 = cosf(M_PI*i/100)*(1/c)*0.1;
				z1 = sinf(M_PI*i/100)*(1/c)*0.1;
				y1 = cosf(M_PI*i/100)*(1/c)*0.1;
				x1 = x1>1||x1<-1?0:x1;
				z1 = z1>1||z1<-1?0:z1;
				y1 = y1>1||y1<-1?0:y1;
				glVertex3d(x1, 0.0002*i, z1);
				glVertex3d(x1, y1, z1);

			}

		glEnd();
	glPopMatrix();
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
ilumination();
// Set the camera
gluLookAt(x, y, z, x+lx, y+ly, z+lz, 0.0f, 1.0f, 0.0f);


drawGround();
drawSky();

drawMuseum();

drawDoor();
drawWindows();
drawPictures(0.0f, -0.1f, -0.5f);
drawBank(0.8f, -2.0f);
drawBank(0.8f, -4.0f);
drawChair(2.5f, 0.5f);
drawTable(2.5f, 0.8f);
drawRack(0.05f, 0.6f, 0.0f);

drawObjectsRack(0.0f, 0.0f, 0.0f);

drawAirConditioning(0.0f, 0.0f);
drawAirConditioning(0.0f, 4.0f);
drawAirConditioning(-3.6f, 4.0f);

drawTV(0.0f, 0.0f, 0.0f);
drawInternWalls();
drawSculture();


glFlush();
glutSwapBuffers();
}

void processNormalKeys(unsigned char key, int x2, int y2) {

	switch(key){
        case 'o':
            if(door_angle <= 118.0f) door_angle += 2.0f;
            glutPostRedisplay();
        break;

        case 'c':
            if(door_angle >= 2.0f) door_angle -= 2.0f;
            glutPostRedisplay();
        break;

        case 'w':
        	angleY += 0.05f;
        	ly = sin(angleY);
        	break;
        case 's':
        	angleY -= 0.05f;
        	ly = sin(angleY);
        	break;
        case 'a':
        	angleXZ -= 0.05f;
        	lx = sin(angleXZ);
        	lz = -cos(angleXZ);
        	break;
        case 'd':
        	angleXZ += 0.05f;
        	lx = sin(angleXZ);
        	lz = -cos(angleXZ);
        	break;
        case 'r':
        	y += 0.4;
        	break;
        case 'f':
        	y -= 0.4;
        	if(y<0)
        		y=0.1;
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
        	x += lz * fraction;
        	z -= lx * fraction;

        break;

        case GLUT_KEY_RIGHT :
        	x -= lz * fraction;
        	z += lx * fraction;
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

