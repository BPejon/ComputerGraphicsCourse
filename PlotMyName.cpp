/*
Name : Breno Pejon Rodrigues
KU Student Id: 2021951241
Assingment 1
Write our names, translate, rotate and scale it.
*/

#include <stdio.h>
#include <iostream>
#include <Windows.h>
#include <glut.h>

//Global various 
int				m_Mouse_Coord[2];	// Mouse Coordinates x,y
unsigned char	m_Mouse_Event[3];	//Mouse Event Handler, x,y,z
float			m_Rotate[2];		//x,y?
float			m_Zoom;				//Zoom


void Initialize(void) {
	m_Zoom = 220;
	//deph test
	glEnable(GL_DEPTH_TEST);
	glClearColor(0.9f, 0.9, 0.9, 1.0f); //Background Color
}


void be() {
	//		ㅂ
	glPushMatrix();
	glTranslatef(0, 9, 0);
	glScalef(0.2, 1.1, 0.2);
	glutWireCube(35);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(15.0, 9.0, 0.0);
	glScalef(1.05, 0.2, 0.2);
	glutWireCube(35);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(15.0, -6.6, 0.0);
	glScalef(1.05, 0.2, 0.2);
	glutWireCube(35);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(30.0, 9.0, 0.0);
	glScalef(0.2, 1.1, 0.2);
	glutWireCube(35);
	glPopMatrix();


	//		ㅡ
	glPushMatrix();
	glTranslatef(15, -25, 0);
	glScalef(1.1, 0.2, 0.2);
	glutWireCube(35);
	glPopMatrix();
}

void re() {
	glColor3d(0, 0.5, 0.5);

	// R
	glPushMatrix();
	glTranslatef(0, 25, 0);
	glScalef(1.0, 0.2, 0.2);
	glutWireCube(35);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(14.0, 12.5, 0.0);
	glScalef(0.2, 0.9, 0.2);
	glutWireCube(35);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0, 0);
	glScalef(1.0, 0.2, 0.2);
	glutWireCube(35);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-14.0, -12.5, 0.0);
	glScalef(0.2, 0.9, 0.2);
	glutWireCube(35);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, -25, 0);
	glScalef(1.0, 0.2, 0.2);
	glutWireCube(35);
	glPopMatrix();

	//E
	glPushMatrix();
	glTranslatef(32, 0, 0);
	glScalef(0.35, 0.2, 0.2);
	glutWireCube(35);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(41.5, 0.0, 0.0);
	glScalef(0.2, 1.65, 0.2);
	glutWireCube(35);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(51.5, 0.0, 0.0);
	glScalef(0.2, 1.65, 0.2);
	glutWireCube(35);
	glPopMatrix();

}

void no() {
	//			ㅣ
	glPushMatrix();
	glTranslatef(0.15, 12, 0);
	glScalef(0.2, 0.93, 0.2);
	glutWireCube(35);
	glPopMatrix();
	//			ㅡ
	glPushMatrix();
	glTranslatef(14.5, -0.5, 0.0);
	glScalef(1.0, 0.2, 0.2);
	glutWireCube(35);
	glPopMatrix();
	//			ㅣ
	glPushMatrix();
	glTranslatef(14.0, -16.6, 0.0);
	glScalef(0.2, 0.4, 0.2);
	glutWireCube(35);
	glPopMatrix();
	//			ㅡ
	glPushMatrix();
	glTranslatef(15.0, -27.0, 0.0);
	glScalef(1, 0.2, 0.2);
	glutWireCube(35);
	glPopMatrix();
}
//What we want to render here
void Display() {
	//scene buffer clear
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();	//Trasnformation matrix initialize

	//according to "translation" and "rotation" adjust the  position and angle
	glTranslatef(0.0, 0.0, -m_Zoom);
	//value m_Rotate changing by mouse (ref: mouse() and motion() function)
	glRotatef(m_Rotate[0], 1.0, 0.0, 0.0);
	glRotatef(m_Rotate[1], 0.0, 1.0, 0.0);

	//show my name
	glPushMatrix();
	glTranslatef(-90, 0, 0);
	be();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-20, 0, 0);
	re();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(50, 0, 0);
	no();
	glPopMatrix();

	glutSwapBuffers();
}

//Test function
void howtoDraw() {
	//Draw circle
	//glutWireTorus(2,5,15,15);
	//glPushMatrix();
	// 	   translate
	// 	   scale
	// 	   wirecube
	//glPopMatrix();
	//do something here!!
	//Drawing your characters


	/* Draw the correct teapot
	glPushMatrix();
	glColor3d(1.0, 0, 0);
	glutWireTeapot(15);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(10.0, 0.0, 0.0);
		glColor3d(0, 1.0, 0);
		glutWireTeapot(15);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-10.0, 0.0, 0.0);
		glColor3d(0, 0, 1.0);
		glutWireTeapot(15);
	glPopMatrix();
	*/
}

void Mouse_Click(int mouse_event, int state, int x, int y) {
	//Mouse coordinates
	m_Mouse_Coord[0] = x;
	m_Mouse_Coord[1] = y;

	switch (mouse_event) {
	case GLUT_LEFT_BUTTON:	//Check if pressing left mouse button
		m_Mouse_Event[0] = ((GLUT_DOWN == state) ? 1 : 0);
		break;
	default:
		break;
	}
	glutPostRedisplay();
}

void Mouse_Motion(int x, int y) {
	//Diference of mouse coordinates
	int diffx = x - m_Mouse_Coord[0];
	int diffy = y - m_Mouse_Coord[1];

	//new coordinates
	m_Mouse_Coord[0] = x;
	m_Mouse_Coord[1] = y;

	//Changing the rotation value
	if (m_Mouse_Event[0]) {
		m_Rotate[0] += (float)0.1 * diffy;
		m_Rotate[1] += (float)0.1 * diffx;
	}
	glutPostRedisplay();
}

void Keyboard(unsigned char key, int x, int y) {

	switch (key) {
	case 'q':
		exit(0);
		break;
		//do Something here
		//According to the keyboard to control the characters
	}
}

//ainda não sei o que faz
void Reshape(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45, (float)w / h, 0.1, 500);
}

int main(int argc, char** argv) {
	//Window generation 
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
	glutInitWindowPosition(300, 0);
	glutInitWindowSize(1024, 576);
	glutCreateWindow("How to OpenGL");
	Initialize();

	//callback functions
	glutDisplayFunc(Display);
	glutReshapeFunc(Reshape);
	glutMouseFunc(Mouse_Click);
	glutMotionFunc(Mouse_Motion);
	glutKeyboardFunc(Keyboard);

	glutMainLoop();
	return 0;
}