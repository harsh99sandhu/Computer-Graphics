#include<GL/glut.h>
#include<stdio.h>
#include<math.h>
int x2,x3,y2,y3;
  
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(0,0,0);
	glPointSize(3);
	int x,y,d,dx,dy,m;
	dx=x3-x2;
	dy=y3-y2;
	m=dy/dx;
/* m>1 */
	if(m>1)
{
	x=x2;
	y=y2;
	d=(2*dy)-dx;	

	for (x;x<=x3;x++)
	{
		if(d>0)
		{
			glBegin(GL_POINTS);
			glVertex2f(x,y);
			y=y+1;
			d=d+(2*dy)-(2*dx);
			glEnd();
			
		}
		else
		{
			glBegin(GL_POINTS);
			glVertex2f(x,y);
			d=d+(2*dy);
			glEnd();

		}
		glFlush(); 
	}
 
}	
/* m<=1 */
	else
{
	x=x2;
	y=y2;
	d=(2*dx)-dy;	

	for (x;x<=x3;x++)
	{
		if(d>0)
		{
			glBegin(GL_POINTS);
			glVertex2f(x,y);
			y=y+1;
			d=d+(2*dx)-(2*dy);
			glEnd();
			
		}
		else
		{
			glBegin(GL_POINTS);
			glVertex2f(x,y);
			d=d+(2*dx);
			glEnd();

		}
		glFlush(); 
	}
 	
}
	
}
 
 
int main(int argc, char** argv) 
{
	printf("Enter the value of x1 : ");
	scanf("%d",&x2);
	printf("Enter the value of y1 : ");
	scanf("%d",&y2);
	printf("Enter the value of x2 : ");
	scanf("%d",&x3);
	printf("Enter the value of y2 : ");
	scanf("%d",&y3);
	 
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (500,500);
	glutInitWindowPosition (100,100);
	glutCreateWindow ("Bresenham's algorithm by Harsh Sandhu");
	glClearColor(1,0,0,0);
	gluOrtho2D(-1,50,-1,50);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
