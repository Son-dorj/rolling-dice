#include<GL/glut.h>
GLfloat vertices[][3]={ 	{-1,-1,-1},
					{ 1,-1,-1},
					{ 1, 1,-1},
					{-1, 1,-1},
					{-1,-1, 1},
					{ 1,-1, 1},
					{ 1, 1, 1},
					{-1, 1, 1}	};
void init()
{
	glClearColor(1,1,1,1);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
	glOrtho(-2.0, 2.0, -2.0, 2.0, -10.0, 10.0);
}
void dot(GLint a,GLint b)
{
	GLfloat l=(vertices[b][0]+vertices[a][0])/2;
	GLfloat m=(vertices[b][1]+vertices[a][1])/2;
	GLfloat n=vertices[b][2];
	glPointSize(15.0);
	glBegin(GL_POINTS);
	glColor3f(1,1,1);
	/*glVertex3f(l-0.2,m-0.2,n);
	glVertex3f(l+0.2,m-0.2,n);
	glVertex3f(l+0.2,m+0.2,n);
	glVertex3f(l-0.2,m+0.2,n);
	*/
	glVertex3f(l,m,n);
	glEnd();
}	
void side(GLint a,GLint b,GLint c,GLint d)
{
	glBegin(GL_POLYGON);
	glColor3f(0,0,0);
	glVertex3fv(vertices[a]);
	glVertex3fv(vertices[b]);
	glVertex3fv(vertices[c]);
	glVertex3fv(vertices[d]);
	glEnd();
	dot(a,c);
}
void cube()
{
	side(4,5,6,7);
}
void draw()
{
	glClear(GL_COLOR_BUFFER_BIT);
	cube();
	glFlush();
}

int main(int argv,char **argc)
{
	glutInit(&argv,argc);
	glutCreateWindow("dice");
	init();
	glutDisplayFunc(draw);
	glutMainLoop();
	return 0;
}
