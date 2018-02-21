#include <GL/glut.h>
#define PI 3.14159
#define RAIO 50
#define SPEED 0.03

float speed = SPEED;
float rotate = 0;
int time = 0;
int xCenter = 200, yCenter = 250;
int raio = RAIO;
int size = 1;
int direction = 1;

void directionChange() {
	direction = direction == 1? -1: 1;
}

void sizeChange() {
	size = size == 1 ? 2 : 1;
	raio = RAIO*size;
}

void start() {
	speed = SPEED;
}

void stop() {
	speed = 0;

}

void keyPressed() {
	directionChange();
	sizeChange();
}

void update(int i) { //função que vai ser chamada por glutTimerFunc
	rotate += speed*direction;
	time += 1;
	switch(time) {
		case 1000:
			directionChange();
			break;
		case 2000:
			sizeChange();
			break;
		case 3000:
			sizeChange();
			break;
		case 4000:
			stop();
			break;
		case 5000:
			start();
			break;
		case 6000:
			time = 0;
			break;
	}

	glutPostRedisplay(); //função que atualiza o display
}



void displayCB(void) {

	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0, 0);

	glLineWidth(3);
	glBegin(GL_LINES);
	glVertex2i(200, 250);
	glVertex2i(200, 125);
	glEnd();

	glutTimerFunc(10, update, 1); // chama a função update com o argumento 1, e atualiza a cada 10 milisegundos
	glBegin(GL_TRIANGLES);

	glColor3f(0, 0, 1.0);
	glVertex2f(xCenter + raio * cos(PI / 6 + rotate), //logica matematica aplicada,
			yCenter + raio * sin(PI / 6 + rotate));
	glVertex2f(xCenter + raio * cos(11 * PI / 6 + rotate),
			yCenter + raio * sin(11 * PI / 6 + rotate));
	glVertex2f(xCenter, yCenter);

	glColor3f(1.0, 1.0, 0);
	glVertex2f(xCenter, yCenter);
	glVertex2f(xCenter + raio * cos(PI / 3 + rotate),
			yCenter + raio * sin(PI / 3 + rotate));
	glVertex2f(xCenter + raio * cos(2 * PI / 3 + rotate),
			yCenter + raio * sin(2 * PI / 3 + rotate));

	glColor3f(1.0, 0, 1.0);
	glVertex2f(xCenter + raio * cos(5 * PI / 6 + rotate),
			yCenter + raio * sin(5 * PI / 6 + rotate));
	glVertex2f(xCenter + raio * cos(7 * PI / 6 + rotate),
			yCenter + raio * sin(7 * PI / 6 + rotate));
	glVertex2f(xCenter, yCenter);

	glColor3f(0, 1.0, 1.0);
	glVertex2f(xCenter + raio * cos(4 * PI / 3 + rotate),
			yCenter + raio * sin(4 * PI / 3 + rotate));
	glVertex2f(xCenter + raio * cos(5 * PI / 3 + rotate),
			yCenter + raio * sin(5 * PI / 3 + rotate));
	glVertex2f(xCenter, yCenter);


	glEnd();
	glFlush();
}

void init(void) {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	gluOrtho2D(0, 400, 0, 500);

}

int main(int argc, char **argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(400, 500);
	glutCreateWindow("CG task 01");
	init();
	glutDisplayFunc(displayCB);
	glutMainLoop();
	return 0;
}
