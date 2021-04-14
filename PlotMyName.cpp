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
float			m_Rotate[2];		//x,y
float			m_Zoom;				//Zoom
int				DeltaX[5];			//Store the values of Deltas in X axis
int				DeltaY[5];			//Store the values of Deltas in Y axis
int				DeltaZ[5];			//Store the values of Deltas in Z axis
int				charac;				//Keep tracking what character is going to rotate		
int				Angle[3];			//Angle of Rotation	0 - X| 1 - Y | 2 - Z
int				Run = 1;
unsigned int	delay = 100;		//Used to delay glTimerFunc
void Initialize(void) {
	m_Zoom = 220;
	//deph testa
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

/* Charac
* 0 - Name
* 1 - 브
* 2 - 레
* 3 - 노
* */
void RotateInX(int charac) {
	glRotatef(DeltaX[charac], 1.0, 0, 0);
}

void RotateInY(int charac) {
	glRotatef(DeltaY[charac], 0, 1.0, 0);
}

void RotateInZ(int charac) {
	glRotatef(DeltaZ[charac], 0, 0, 1);
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
	//for (int j = 0; j < 4; ++j) {
	//	printf("Variavel %d X -	%d	Y - %d		Z -%d \n", j, DeltaX[j], DeltaY[j], DeltaZ[j]);
	//}


	//Rotate my name
	if (Run == 1) {
		glRotatef(DeltaX[0], 1.0, 0, 0);
		glRotatef(DeltaY[0], 0, 1.0, 0);
		glRotatef(DeltaZ[0], 0, 0, 1.0);
	}

	glPushMatrix();
	glTranslatef(-90, 0, 0);
	if (Run == 1) {
		RotateInX(1);
		RotateInY(1);
		RotateInZ(1);
	}
	be();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-20, 0, 0);
	if (Run == 1) {
		RotateInX(2);
		RotateInY(2);
		RotateInZ(2);
	}
	re();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(50, 0, 0);
	if (Run == 1) {
		RotateInX(3);
		RotateInY(3);
		RotateInZ(3);
	}
	no();
	glPopMatrix();

	glutSwapBuffers();
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

void RotateNameX(int value) {
	Angle[0] += 10;
	DeltaX[charac] = Angle[0];

	glutPostRedisplay();
	glutTimerFunc(delay, RotateNameX, 1);
}	

void RotateNameY(int value) {
	Angle[1] += 10;
	DeltaY[charac] = Angle[1];

	glutPostRedisplay();
	glutTimerFunc(delay, RotateNameY, 1);
}

void RotateNameZ(int value) {
	Angle[2] += 10;
	DeltaZ[charac] = Angle[2];

	glutPostRedisplay();
	glutTimerFunc(delay, RotateNameZ, 1);
}

void Keyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 'q':
		exit(0);
		break;
	case'r': //reset everithing and stop animation
		Run = 0;
		delay = 214748367;
		Angle[0] = 0;
		Angle[1] = 0;
		Angle[2] = 0;
		for (int k = 0; k < 5; ++k){
			DeltaX[k] = 0;
			DeltaY[k] = 0;
			DeltaZ[k] = 0;
		}
		break;
	case 'z': // Rotate everything in X axis
		charac = 0;
		Run = 1;
		delay = 100;
		glutTimerFunc(1000, RotateNameX, 1);
		break;
	case 'x': //Rotate everything in Y axis
		charac= 0;
		Run = 1;
		delay = 100;
		glutTimerFunc(1000, RotateNameY, 1);
		break;
	case 'c'://Rotate everithyn in Z axis
		charac= 0;
		Angle[0] = 0;
		Run = 1;
		delay = 100;
		glutTimerFunc(1000, RotateNameZ, 1);
		break;	

	case 'a':	//Rotate first Name
		charac= 1;
		Run = 1;
		delay = 100;
		glutTimerFunc(1000, RotateNameX, 1);
		break;
	case 's':	//Rotate second Name
		charac= 2;
		Run = 1;
		delay = 100;
		glutTimerFunc(1000, RotateNameX, 1);
		break;
	case 'd':	//Rotate third Name
		charac= 3;
		Run = 1;
		delay = 100;
		glutTimerFunc(1000, RotateNameX, 1);
		break;

		//Rotate in Y axis - First through Third Name
	case 'f':
		charac= 1;
		Run = 1;
		delay = 100;
		glutTimerFunc(1000, RotateNameY, 1);
		break;
	case 'g':
		charac= 2;
		Run = 1;
		delay = 100;
		glutTimerFunc(1000, RotateNameY, 1);
		break;
	case 'h':
		charac= 3;
		Run = 1; 
		delay = 100;
		glutTimerFunc(1000, RotateNameY, 1);
		break;

	//Rotate in Z axis - respectively to the names order
	case 'j':
		charac= 1;
		Run = 1; 
		delay = 100;
		glutTimerFunc(1000, RotateNameZ, 1);
		break;
	case 'k':
		charac= 2;
		Run = 1;
		delay = 100;
		glutTimerFunc(1000, RotateNameZ, 1);
		break;
	case 'l':
		charac= 3;
		Run = 1;
		delay = 100;
		glutTimerFunc(1000, RotateNameZ, 1);
		break;
	}
}

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
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(1366, 768);
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