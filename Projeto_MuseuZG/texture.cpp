#include "texture.h"
#include <SFML/Graphics.hpp>
#include <fstream>
#define LEFT 0
#define UP 1
#define RIGHT 2
#define DOWN 3
#define FRONT 4
#define BACK 5

GLuint texture_id[25];

void drawCube(GLdouble size, int *tex) {
  static GLfloat n[6][3] =
  {
    {-1.0, 0.0, 0.0},
    {0.0, 1.0, 0.0},
    {1.0, 0.0, 0.0},
    {0.0, -1.0, 0.0},
    {0.0, 0.0, 1.0},
    {0.0, 0.0, -1.0}
  };
  static GLint faces[6][4] =
  {
    {0, 1, 2, 3},
    {3, 2, 6, 7},
    {7, 6, 5, 4},
    {4, 5, 1, 0},
    {5, 6, 2, 1},
    {7, 4, 0, 3}
  };
  GLfloat v[8][3];
  GLint i;

  v[0][0] = v[1][0] = v[2][0] = v[3][0] = -size / 2;
  v[4][0] = v[5][0] = v[6][0] = v[7][0] = size / 2;
  v[0][1] = v[1][1] = v[4][1] = v[5][1] = -size / 2;
  v[2][1] = v[3][1] = v[6][1] = v[7][1] = size / 2;
  v[0][2] = v[3][2] = v[4][2] = v[7][2] = -size / 2;
  v[1][2] = v[2][2] = v[5][2] = v[6][2] = size / 2;

  for (i = 5; i >= 0; i--) {
    if(tex[i] >= 0) {
      glBindTexture(GL_TEXTURE_2D, texture_id[tex[i]]);
    } else {
    	glBindTexture(GL_TEXTURE_2D, 0);
    }
    glBegin(GL_QUADS);
    glNormal3fv(&n[i][0]);
    if(i==1)
      glTexCoord2f(1.0f, 0.0f);
    else
      glTexCoord2f(0.0f, 0.0f);
    glVertex3fv(&v[faces[i][0]][0]);
    if(i==1)
      glTexCoord2f(0.0f, 0.0f);
    else
      glTexCoord2f(1.0f, 0.0f);
    glVertex3fv(&v[faces[i][1]][0]);
    if(i==1)
      glTexCoord2f(0.0f, 1.0f);
    else
      glTexCoord2f(1.0f, 1.0f);
    glVertex3fv(&v[faces[i][2]][0]);
    if(i==1)
      glTexCoord2f(1.0f, 1.0f);
    else
      glTexCoord2f(0.0f, 1.0f);
    glVertex3fv(&v[faces[i][3]][0]);
    glEnd();
  }
  /*
  double tam = size/2;
  static float vertex[8][3] = {{-tam,-tam,tam}, {tam,-tam,tam}, {-tam,tam,tam}, {tam,tam,tam}, {-tam,-tam,-tam}, {-tam,-tam,-tam}, {-tam,tam,-tam}, {tam,tam,-tam}};

static int link[6][4] = {{0,1,3,2}, {1,5,7,3}, {5,4,6,7}, {4,0,2,6}, {4,5,1,0}, {2,3,7,6}};

glBegin(GL_QUADS);
for (int a=0; a<6; a++){
	glVertex3f(vertex[link[a][0]][0], vertex[link[a][0]][1], vertex[link[a][0]][2]);
	glVertex3f(vertex[link[a][1]][0], vertex[link[a][1]][1], vertex[link[a][1]][2]);
	glVertex3f(vertex[link[a][2]][0], vertex[link[a][2]][1], vertex[link[a][2]][2]);
	glVertex3f(vertex[link[a][3]][0], vertex[link[a][3]][1], vertex[link[a][3]][2]);
}
glEnd();*/
}



void faceCubeConstructor(double size, int face, int texture) {
	double position = size/2;
	glBindTexture(GL_TEXTURE_2D, texture);
	glBegin(GL_QUADS);
	if(face == LEFT) {
		glTexCoord2f(0,0);
		glVertex3f(-position, 0, 0);
		glTexCoord2f(1,0);
		glVertex3f(-position, position, 0);
		glTexCoord2f(0,1);
		glVertex3f(-position, 0, position);
		glTexCoord2f(1,1);
		glVertex3f(-position, position, position);
	}
	if(face == UP) {
		glTexCoord2f(0,0);
		glVertex3f(0, position, 0);
		glTexCoord2f(1,0);
		glVertex3f(position, position, 0);
		glTexCoord2f(0,1);
		glVertex3f(0, position, position);
		glTexCoord2f(1,1);
		glVertex3f(position, position, position);
	}
	if(face == RIGHT) {
		glTexCoord2f(0,0);
		glVertex3f(position, 0, 0);
		glTexCoord2f(1,0);
		glVertex3f(position, position, 0);
		glTexCoord2f(0,1);
		glVertex3f(position, 0, position);
		glTexCoord2f(1,1);
		glVertex3f(position, position, position);
	}
	if(face == DOWN) {
		glTexCoord2f(0,0);
		glVertex3f(0, -position, 0);
		glTexCoord2f(1,0);
		glVertex3f(position, -position, 0);
		glTexCoord2f(0,1);
		glVertex3f(0, -position, position);
		glTexCoord2f(1,1);
		glVertex3f(position, -position, position);
	}
	if(face == FRONT) {
		glTexCoord2f(0,0);
		glVertex3f(0, 0, position);
		glTexCoord2f(1,0);
		glVertex3f(position, 0, position);
		glTexCoord2f(0,1);
		glVertex3f(0, position, position);
		glTexCoord2f(1,1);
		glVertex3f(position, position, position);
	}
	if(face == BACK) {
		glTexCoord2f(0,0);
		glVertex3f(0, 0, -position);
		glTexCoord2f(1,0);
		glVertex3f(position, 0, -position);
		glTexCoord2f(0,1);
		glVertex3f(0, position, -position);
		glTexCoord2f(1,1);
		glVertex3f(position, position, -position);
	}
	glEnd();
}



void loadTextureFromFile(char const *filename,int index) {
	int width, height;

	sf::Image image;
	image.loadFromFile(filename);

	glGenTextures(1, &texture_id[index]);
	glBindTexture(GL_TEXTURE_2D, texture_id[index]);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image.getSize().x, image.getSize().y, 0, GL_RGBA, GL_UNSIGNED_BYTE, image.getPixelsPtr());
}

void loadTextures(){
	loadTextureFromFile("texture/quadro1.jpeg", 0);
	loadTextureFromFile("texture/quadro2.jpeg", 1);
	loadTextureFromFile("texture/quadro3.jpeg", 2);
	loadTextureFromFile("texture/quadro4.jpeg", 3);
	loadTextureFromFile("texture/quadro5.jpeg", 4);
	loadTextureFromFile("texture/quadro6.jpeg", 5);
	loadTextureFromFile("texture/quadro7.jpeg", 6);
	loadTextureFromFile("texture/quadro8.jpeg", 7);
	loadTextureFromFile("texture/quadro9.jpeg", 8);
	loadTextureFromFile("texture/quadro10.jpeg", 9);
	loadTextureFromFile("texture/madeira.jpeg", 10);
	loadTextureFromFile("texture/front_wall.png", 11);
	loadTextureFromFile("texture/ar_condicionado.jpeg", 12);
	loadTextureFromFile("texture/parede_interna1.jpeg", 13);
	loadTextureFromFile("texture/chao.jpeg", 14);
	loadTextureFromFile("texture/window.jpeg",15);
	loadTextureFromFile("texture/scultureTable.jpg", 16);
	loadTextureFromFile("texture/quadro11.jpeg", 17);
	loadTextureFromFile("texture/quadro12.jpeg", 18);
	loadTextureFromFile("texture/piso2a.jpeg", 19);
	loadTextureFromFile("texture/door.png", 20);
	loadTextureFromFile("texture/teto.jpeg", 21);
	}
