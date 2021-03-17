#include<GL/glut.h>
#include<stdio.h> 
#include<math.h>
float x1, y_1, x2, y2,x3,y3,x4,y4,tx,ty,xc,yc,theta,sx,sy;
int c;

void translate(float *x,float *y,float tx,float ty)
{
    *x = *x + tx;
    *y = *y + ty;
}

void rotation(float *x,float *y,float theta)
{
    theta = (3.1415 / 180 ) * theta;
    float xTemp = *x;
    *x = *x * cos(theta) - *y * sin(theta);
    *y = xTemp * sin(theta) + *y * cos(theta) ;
}

void scale(float *x,float *y,float sx,float sy)
{
    *x = *x * sx;
    *y = *y * sy;
}

void shear(float *x,float *y,float sx,float sy)
{
    float xTemp = *x;
    *x = *x + sx * (*y);
    *y = *y + sy * xTemp;
}

void display()
{
	switch(c)
	{
		case 1: 
    		glClear(GL_COLOR_BUFFER_BIT);
    		glColor3f(0,1,0);
    		glBegin(GL_LINES);
        	glVertex2f(x1,y_1);
        	glVertex2f(x2,y2);
    		glEnd();
    		glFlush();
		break;
		
		case 2:
		glClear(GL_COLOR_BUFFER_BIT);
    		glColor3f(0,1,0);
    		glBegin(GL_LINES);
        	glVertex2f(x1,y_1);
        	glVertex2f(x2,y2);
    		glEnd();
    		glFlush();
		break;
		
		case 3:
		glClear(GL_COLOR_BUFFER_BIT);
    		glColor3f(0,1,0);
    		glBegin(GL_LINES);
    		glVertex2f(x1,y_1);
        	glVertex2f(x2,y2);
        	glVertex2f(x2,y2);
        	glVertex2f(x3,y3);
        	glVertex2f(x3,y3);
        	glVertex2f(x4,y4);
        	glVertex2f(x4,y4);
        	glVertex2f(x1,y_1);
    		glEnd();
    		glFlush();
		break;
		
		case 4:
		glClear(GL_COLOR_BUFFER_BIT);
    		glColor3f(0,1,0);
    		glBegin(GL_LINES);
        	glVertex2f(x1,y_1);
        	glVertex2f(x2,y2);
    		glEnd();
    		glFlush();
		break;
		
		case 5:
		glClear(GL_COLOR_BUFFER_BIT);
    		glColor3f(0,1,0);
    		glBegin(GL_LINES);
        	glVertex2f(x1,y_1);
        	glVertex2f(x2,y2);
    		glEnd();
    		glFlush();
		break;
		
		case 6:
		glClear(GL_COLOR_BUFFER_BIT);
    		glColor3f(0,1,0);
    		glBegin(GL_LINES);
    		glVertex2f(x1,y_1);
        	glVertex2f(x2,y2);
        	glVertex2f(x2,y2);
        	glVertex2f(x3,y3);
        	glVertex2f(x3,y3);
        	glVertex2f(x4,y4);
        	glVertex2f(x4,y4);
        	glVertex2f(x1,y_1);
    		glEnd();
    		glFlush();
		break;
	}

}

void myMouseFunc(int button, int state, int x, int y)
{

	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{ 
		
        	switch(c)
	{
		case 1: 
        	glClear(GL_COLOR_BUFFER_BIT);
    		glColor3f(0,1,0);
    		glBegin(GL_LINES);
        	translate(&x1, &y_1, tx, ty);
        	translate(&x2, &y2, tx, ty);
        	glVertex2f(x1,y_1);
        	glVertex2f(x2,y2);
		glEnd();
    		glFlush();
    		break;
    		
    		case 2:
    		glClear(GL_COLOR_BUFFER_BIT);
    		glColor3f(0,1,0);
    		glBegin(GL_LINES);
        	translate(&x1,&y_1,-xc,-yc);
        	translate(&x2,&y2,-xc,-yc);
		rotation(&x1, &y_1, theta);
        	rotation(&x2, &y2, theta);
        	translate(&x1,&y_1,xc,yc);
        	translate(&x2,&y2,xc,yc);
        	glVertex2f(x1,y_1);
        	glVertex2f(x2,y2);
        	glEnd();
    		glFlush();
    		break;
    		
    		case 3:
    		glClear(GL_COLOR_BUFFER_BIT);
    		glColor3f(0,1,0);
    		glBegin(GL_LINES);
		scale(&x1, &y_1, sx,sy);
        	scale(&x2, &y2, sx,sy);
        	scale(&x3, &y3, sx,sy);
        	scale(&x4, &y4, sx,sy);
		glVertex2f(x1,y_1);
        	glVertex2f(x2,y2);
        	glVertex2f(x2,y2);
        	glVertex2f(x3,y3);
        	glVertex2f(x3,y3);
        	glVertex2f(x4,y4);
        	glVertex2f(x4,y4);
        	glVertex2f(x1,y_1);
    		glEnd();
    		glFlush();
    		break;
    		
    		case 4:
    		glClear(GL_COLOR_BUFFER_BIT);
    		glColor3f(0,1,0);
    		glBegin(GL_LINES);
        	glVertex2f(-x1,y_1);
        	glVertex2f(-x2,y2);
    		glEnd();
    		glFlush();
    		break;
    		
    		case 5:
    		glClear(GL_COLOR_BUFFER_BIT);
    		glColor3f(0,1,0);
    		glBegin(GL_LINES);
        	glVertex2f(x1,-y_1);
        	glVertex2f(x2,-y2);
    		glEnd();
    		glFlush();
    		break;
    		
    		case 6:
    		glClear(GL_COLOR_BUFFER_BIT);
    		glColor3f(0,1,0);
    		glBegin(GL_LINES);
    		shear(&x1,&y_1,sx,sy);
        	shear(&x2,&y2,sx,sy);
        	shear(&x3,&y3,sx,sy);
        	shear(&x4,&y4,sx,sy);
		glVertex2f(x1,y_1);
        	glVertex2f(x2,y2);
        	glVertex2f(x2,y2);
        	glVertex2f(x3,y3);
        	glVertex2f(x3,y3);
        	glVertex2f(x4,y4);
        	glVertex2f(x4,y4);
        	glVertex2f(x1,y_1);
    		glEnd();
    		glFlush();
    		break;
	}}
	
}

int main(int argc, char** argv) 
{	
	printf("Enter the first point (x1,y_1) : ");
	scanf("%f%f", &x1, &y_1);
        printf("Enter the second point (x2,y2) : ");
	scanf("%f%f", &x2, &y2);
	printf("Enter \n1:Translation\n2:Rotation\n3:Scaling\n4:Reflection about y-axis\n5:Reflection about x-axis\n6:Shearing\n");
	scanf("%d",&c);
	switch(c)
	{
		case 1: 
		printf("Enter the translation factor (tx,ty) : "); 
       		scanf("%f%f",&tx,&ty);
       		break;
       		
       		case 2:
       		printf("Enter the arbitary point (xc,yc) : ");
		scanf("%f%f", &xc, &yc);
		printf("Enter the rotation angle in degree(theta) : ");
		scanf("%f", &theta);
		break;
		
		case 3:
		printf("Enter the third point (x3,y3) : ");
		scanf("%f%f", &x3, &y3);
        	printf("Enter the fourth point (x4,y4) : ");
		scanf("%f%f", &x4, &y4);
		printf("Enter the scaling factors (sx,sy) : ");
		scanf("%f%f", &sx, &sy);
		break;
		
		case 4:
		printf("New coordinates = (%f, %f) and (%f,%f)",-x1,y_1,-x2,y2);
		break;
		
		case 5:
		printf("New coordinates = (%f, %f) and (%f,%f)",x1,-y_1,x2,-y2);
		break;
		
       		case 6:
       		printf("Enter the third point (x3,y3) : ");
		scanf("%f%f", &x3, &y3);
        	printf("Enter the fourth point (x4,y4) : ");
		scanf("%f%f", &x4, &y4);
		printf("Enter the shearing factors (sx,sy) : ");
		scanf("%f%f", &sx, &sy);
       		break;
	}
	
   
        
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (640,480);
	glutInitWindowPosition (200,200);
	glutCreateWindow ("2D transformation by Harsh Sandhu");
	glClearColor(1,0,0,0);
	gluOrtho2D(-1000,1000,-1000,1000);    
	glutDisplayFunc(display);
	glutMouseFunc(myMouseFunc);
	glutMainLoop();
	return 0;
}
