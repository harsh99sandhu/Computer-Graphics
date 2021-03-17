#include<GL/glut.h>
#include<stdio.h>
#include<math.h>
float r;
  
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
  	glColor3f(0,1,0);
	glBegin(GL_POLYGON);
	float theta;
	for(int i=0;i<360;i++)
	{
		theta=i*3.142/180;

		glVertex2f(r*cos(theta),r*sin(theta));
		
	}
	glEnd();

	glFlush();


}

int main(int argc, char** argv) 
{
	printf("Enter the value of radius : ");
	scanf("%f",&r);
	
	 
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (500,500);
	glutInitWindowPosition (100,100);
	glutCreateWindow ("Circle by polar equation - Harsh Sandhu");
	glClearColor(1,0,0,0);
	gluOrtho2D(-50,50,-50,50);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
