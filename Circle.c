#include<GL/glut.h>
#include<stdio.h>
int r;

//Starting from origin by default

void Symmetry(int x,int y)  
   {  

	glBegin(GL_POINTS);
	glVertex2f(x,y);  
    	glVertex2f(x,-y);  
    	glVertex2f(y,x);  
    	glVertex2f(y,-x);  
    	glVertex2f(-x,-y);  
   	glVertex2f(-y,-x);  
    	glVertex2f(-x,y);  
    	glVertex2f(-y,x);  

	glEnd();

   } 
  
void display()  
{  
	glClear(GL_COLOR_BUFFER_BIT);
  	glColor3f(0,1,0);  
	glPointSize(3);  	
	int x=0;
   	int y=r;
	int d=1-r;  
    	Symmetry(x,y);  
  
    	while(x<y)  
    	{  
		x++;  		
		if(d<0)  
        	{  
       			d=d+(2*x)+1;
			   
        	}  
        	else  
        	{  
        		y=y-1;          		
			d=d+2*(x-y)+1; 

        	}  

       		Symmetry(x,y);  

	}
		
  	glFlush();
}  

int main(int argc, char** argv) 
{	
	printf("Enter the value of r : ");
	scanf("%d",&r);

	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (500,500);
	glutInitWindowPosition (100,100);
	glutCreateWindow ("Circle by Harsh Sandhu");
	glClearColor(1,0,0,0);
	gluOrtho2D(-50,50,-50,50);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
