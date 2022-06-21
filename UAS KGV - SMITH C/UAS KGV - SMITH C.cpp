#include <glut.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <math.h>

using namespace std;

float xp, yp, r = 2, n = 1000, phi = 3.14, x, y, p = 0;

void lingkaran()
{
	glBegin(GL_POLYGON);
	xp = 0;
	yp = 0;
	for (int i = 0; i < n; i++) {
		x = xp + r * cos(2 * phi * i / n);
		y = yp + r * sin(2 * phi * i / n);
		glVertex2f(x, y);
	}
	glEnd();
}

void langit()
{
	glColor3ub(135, 206, 250);
	glColor3ub(135, 206, 235);
	glRectf(-30, 0, 30, 40);
}

void HotelOrange()
{
	glBegin(GL_QUADS);
	glColor3ub(255, 140, 0);
	glVertex2f(-5, 25);
	glVertex2f(5, 25);
	glVertex2f(5, 0);
	glVertex2f(-5, 0);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3ub(255, 165, 0);
	glVertex2f(-5, 25);
	glVertex2f(5, 25);
	glVertex2f(0, 30);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(255, 165, 0);
	glVertex2f(0, 31);
	glVertex2f(0, 30);
	glVertex2f(5, 25);
	glVertex2f(6, 25);
	glEnd();
	glBegin(GL_QUADS);
	glColor3ub(132, 15, 26);
	glVertex2f(0, 31);
	glVertex2f(0, 30);
	glVertex2f(-5, 25);
	glVertex2f(-6, 25);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glColor3ub(232, 231, 254);
	glVertex2f(-2, 23);
	glVertex2f(2, 23);
	glVertex2f(2, 18);
	glVertex2f(-2, 18);
	glEnd();


	glColor3ub(255, 255, 255);
	glColor3ub(232, 231, 254);
	glRectf(-2, 10, 2, 15);


	glColor3ub(144, 28, 38);
	glRectf(-3, 0, 3, 6);

	glLineWidth(2);
	glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
	glVertex2f(0, 0);
	glVertex2f(0, 6);
	glEnd();


}


void rumput()
{
	glColor3ub(69, 139, 0);
	glRectf(-30, -4, 30, 0);
}

void aspal()
{
	glColor3ub(190, 190, 190);
	glRectf(-30, -20, 30, -4);
}

void mobil()
{
	glBegin(GL_QUADS);
	glColor3ub(67, 110, 238);
	glColor3ub(193, 205, 193);
	glVertex2f(-25 + p, -13);
	glVertex2f(2 + p, -13);
	glVertex2f(2 + p, -16);
	glVertex2f(-25 + p, -16);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(255, 255, 255);
	glVertex2f(-25 + p, -13);
	glVertex2f(-20 + p, -8);
	glVertex2f(-6 + p, -8);
	glVertex2f(-2 + p, -12);
	glVertex2f(2 + p, -13);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(67, 110, 238);
	glVertex2f(-23 + p, -12);
	glVertex2f(-20 + p, -9);
	glVertex2f(-16 + p, -9);
	glVertex2f(-16 + p, -12);
	glEnd();
	glColor3ub(67, 110, 238);
	glBegin(GL_QUADS);
	glVertex2f(-15 + p, -9);
	glVertex2f(-11 + p, -9);
	glVertex2f(-11 + p, -12);
	glVertex2f(-15 + p, -12);
	glEnd();
	glBegin(GL_QUADS);
	glColor3ub(67, 110, 238);
	glVertex2f(-10 + p, -9);
	glVertex2f(-10 + p, -12);
	glVertex2f(-3 + p, -12);
	glVertex2f(-6 + p, -9);
	glEnd();

	// RODA
	glColor3ub(67, 110, 238);
	glPushMatrix();
	glTranslatef(-4 + p, -16, 0);
	lingkaran();
	glPopMatrix();

	glColor3ub(67, 110, 238);
	glPushMatrix();
	glTranslatef(-20 + p, -16, 0);
	lingkaran();
	glPopMatrix();

}

void userdraw()
{
	langit();
	HotelOrange();
	rumput();
	aspal();
	mobil();
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 13: //tombol escape exit(0);
		exit(0);
		break;
	case 'r':
	case 'R':
		p += 1;  // untuk translasi agar dia berjalan ke kanan
		std::cout << "r or R was pressed\n";
		break;
	case 'l':
	case 'L':
		p -= 1;	  // untuk translasi agar dia berjalan ke kiri
		std::cout << "l or L was pressed\n";
		break;
	}
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	userdraw();
	glutSwapBuffers();
}

int main(int argc, char** argv)
{
	glutInit(&__argc, __argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(640, 640);
	glutCreateWindow("Project UAS KGV Smith C");
	glClearColor(1.0, 1.0, 1.0, 1.0);
	gluOrtho2D(-30, 30, -20, 40);
	glutIdleFunc(display);
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
}