#include<GL/glut.h>
#include<stdio.h>
#include<math.h>
float x2,x3,y2,y3;
 
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(1,1,1);
	glPointSize(3);
	float y,i,m,c=10;
	m=(y3-y2)/(x3-x2);  	

	for (i=x2 ;i<=x3;i++)
	{
		y = m*i + c;
 		y=round(y);
		
		glBegin(GL_POINTS);
		glVertex2f(i,y);
		glEnd();

	}
 
	glFlush(); 
	
}
 
int main(int argc, char** argv) 
{
	printf("Enter the value of x1 : ");
	scanf("%f",&x2);
	printf("Enter the value of y1 : ");
	scanf("%f",&y2);
	printf("Enter the value of x2 : ");
	scanf("%f",&x3);
	printf("Enter the value of y2 : ");
	scanf("%f",&y3);
	 
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (500,500);
	glutInitWindowPosition (100,100);
	glutCreateWindow ("mx+c - Harsh Sandhu");
	glClearColor(1,0,0,0);
	gluOrtho2D(-1,50,-1,50);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
