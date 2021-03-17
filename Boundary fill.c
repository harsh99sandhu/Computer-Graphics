#include<GL/glut.h>
#include<stdio.h> 


void bound_fill(int x, int y, float* fillColor, float* bc){
    float color[3];
    glReadPixels(x,y,1.0,1.0,GL_RGB,GL_FLOAT,color);
    if((color[0]!=bc[0] || color[1]!=bc[1] || color[2]!=bc[2])&&(
     color[0]!=fillColor[0] || color[1]!=fillColor[1] || color[2]!=fillColor[2]))
    {
        glColor3f(fillColor[0],fillColor[1],fillColor[2]);
        glBegin(GL_POINTS);
        glVertex2i(x,y);
        glEnd();
        glFlush();
        bound_fill(x+1,y,fillColor,bc);
     	bound_fill(x-1,y,fillColor,bc);
        bound_fill(x,y+1,fillColor,bc);
        bound_fill(x,y-1,fillColor,bc);
        //bound_fill(x-1,y-1,fillColor,bc);
        //bound_fill(x-1,y+1,fillColor,bc);
        //bound_fill(x+1,y-1,fillColor,bc);
        //bound_fill(x+1,y+1,fillColor,bc);
    }

}


void display()
{

	glClear(GL_COLOR_BUFFER_BIT);
  	glColor3f(0,1,0);
  	glBegin(GL_LINE_LOOP);  // GL_LINE_LOOP	taken	
	glVertex2f(100,100);
  	glVertex2f(100,200);
  	glVertex2f(200,200);
  	glVertex2f(200,100);
    	glEnd();
    	glFlush();

}

void myMouseFunc(int button, int state, int x, int y)
{

	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{ 
		float bCol[] = {0,1,0};
            	float fillcolor[] = {0,0,1};
            	bound_fill(110,110,fillcolor,bCol);
	}
	
}



int main(int argc, char** argv) 
{	
	
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (500,500);
	glutInitWindowPosition (100,100);
	glutCreateWindow ("Boundary fill by Harsh Sandhu");
	glClearColor(1,0,0,0);
	gluOrtho2D(0,500,0,500);     // equal to window size
	glutDisplayFunc(display);
	glutMouseFunc(myMouseFunc);
	glutMainLoop();
	return 0;
}
