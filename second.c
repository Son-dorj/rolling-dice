#include <stdlib.h>
#include <GL/glut.h>

void cube(GLfloat s)
{
	GLfloat a=s/2;
	GLfloat b=s/10;
	glBegin(GL_QUADS);
		glColor3f(1,0.9,0.71);
		//back
		glVertex3f( a, a,-a);	glVertex3f(-a, a,-a);	glVertex3f(-a,-a,-a);	glVertex3f( a,-a,-a);
		glColor3f(0,0,0);
		glVertex3f( b, b,-a);	glVertex3f(-b, b,-a);	glVertex3f(-b,-b,-a);	glVertex3f( b,-b,-a);
		//bottom
		glColor3f(1,0.9,0.71);
		glVertex3f( a,-a, a);	glVertex3f(-a,-a, a);	glVertex3f(-a,-a,-a);	glVertex3f( a,-a,-a);
		//front
		glVertex3f( a, a, a);	glVertex3f(-a, a, a);	glVertex3f(-a,-a, a);	glVertex3f( a,-a, a);
		glColor3f(0,0,0);
		glVertex3f( b, b, a);	glVertex3f(-b, b, a);	glVertex3f(-b,-b, a);	glVertex3f( b,-b, a);
		//top
		glVertex3f( a, a, a);	glVertex3f(-a, a, a);	glVertex3f(-a, a,-a);	glVertex3f( a, a,-a);
		//left
		glVertex3f(-a, a, a);	glVertex3f(-a, a,-a);	glVertex3f(-a,-a,-a);	glVertex3f(-a,-a, a);
		//right
		glVertex3f( a, a,-a);	glVertex3f( a, a, a);	glVertex3f( a,-a, a);	glVertex3f( a,-a,-a);
	glEnd();
	glColor3f(0,0,0);
	glBegin(GL_LINE_LOOP);
		glVertex3f( a, a,-a);	glVertex3f(-a, a,-a);	glVertex3f(-a,-a,-a);	glVertex3f( a,-a,-a);
	glEnd();
	glBegin(GL_LINE_LOOP);
		glVertex3f( a,-a, a);	glVertex3f(-a,-a, a);	glVertex3f(-a,-a,-a);	glVertex3f( a,-a,-a);
	glEnd();
	glBegin(GL_LINE_LOOP);
		glVertex3f( a, a, a);	glVertex3f(-a, a, a);	glVertex3f(-a,-a, a);	glVertex3f( a,-a, a);
	glEnd();
	glBegin(GL_LINE_LOOP);
		glVertex3f( a, a, a);	glVertex3f(-a, a, a);	glVertex3f(-a, a,-a);	glVertex3f( a, a,-a);
	glEnd();
	glBegin(GL_LINE_LOOP);
		glVertex3f(-a, a, a);	glVertex3f(-a, a,-a);	glVertex3f(-a,-a,-a);	glVertex3f(-a,-a, a);
	glEnd();
	glBegin(GL_LINE_LOOP);
		glVertex3f( a, a,-a);	glVertex3f( a, a, a);	glVertex3f( a,-a, a);	glVertex3f( a,-a,-a);
	glEnd();
}

static GLfloat theta[] =	{0.0,0.0,0.0}; 
static GLint axis = 2;

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glRotatef(theta[0], 1.0, 0.0, 0.0);
	glRotatef(theta[1], 0.0, 1.0, 0.0);
	glRotatef(theta[2], 0.0, 0.0, 1.0);
	cube(1.0);
	glFlush();
	glutSwapBuffers();
}
void spinCube()
{
	theta[axis] += 1;
	if( theta[axis] > 360.0 ) 
		theta[axis] -= 360.0;
	glutPostRedisplay();
}
void mouse(int btn, int state, int x, int y)
{
	if(btn==GLUT_LEFT_BUTTON && state == GLUT_DOWN) 
		axis = 0;
	if(btn==GLUT_MIDDLE_BUTTON && state == GLUT_DOWN) 
		axis = 1;
	if(btn==GLUT_RIGHT_BUTTON && state == GLUT_DOWN) 
		axis = 2;
}
void myReshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w <= h)
		glOrtho(-2.0, 2.0, -2.0 * (GLfloat) h / (GLfloat) w, 2.0 * (GLfloat) h / (GLfloat) w, -10.0, 10.0);
	else
		glOrtho(-2.0 * (GLfloat) w / (GLfloat) h, 2.0 * (GLfloat) w / (GLfloat) h, -2.0, 2.0, -10.0, 10.0);
	glMatrixMode(GL_MODELVIEW);
}
int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Rotating a Color Cube");
	glutReshapeFunc(myReshape);
	glutDisplayFunc(display);
	glutIdleFunc(spinCube);
	glutMouseFunc(mouse);
	glEnable(GL_DEPTH_TEST);
	glutMainLoop();
	return 0;
}




