#include<GL/glut.h>
void display()
{
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(0.545,0.271,0.075);

/*Mountains*/
  glBegin(GL_TRIANGLES);
  glVertex2f(-12,5);
  glVertex2f(-8,10);
  glVertex2f(-6,5);
  glEnd();

  glBegin(GL_TRIANGLES);
  glVertex2f(-6,5);
  glVertex2f(-3,10);
  glVertex2f(-0,5);
  glEnd();

  glBegin(GL_TRIANGLES);
  glVertex2f(0,5);
  glVertex2f(2,8);
  glVertex2f(5,5);
  glEnd();

  glBegin(GL_TRIANGLES);
  glVertex2f(5,5);
  glVertex2f(7.5,7);
  glVertex2f(9,5);
  glEnd();

  glBegin(GL_TRIANGLES);
  glVertex2f(9,5);
  glVertex2f(12,9);
  glVertex2f(14,5);
  glEnd();
  

/*Green field*/
  glColor3f(0.486,0.988,0);
  glBegin(GL_POLYGON);
  glVertex2f(-12,5);
  glVertex2f(14,5);
  glVertex2f(20,2);
  glVertex2f(-12,2);
  glEnd();


/*Rays*/
  glColor3f(1,1,0);
  glBegin(GL_LINES);
  glVertex2f(6,10);
  glVertex2f(6.5,10.5);
  glEnd();

  glBegin(GL_LINES);
  glVertex2f(6.5,9.5);
  glVertex2f(7.5,10);
  glEnd();

  glBegin(GL_LINES);
  glVertex2f(6.5,9);
  glVertex2f(7.5,9);
  glEnd();

  glBegin(GL_LINES);
  glVertex2f(6,8);
  glVertex2f(6.5,7);
  glEnd();

  glBegin(GL_LINES);
  glVertex2f(5,8);
  glVertex2f(4,7);
  glEnd();

  glBegin(GL_LINES);
  glVertex2f(6.5,8.5);
  glVertex2f(7,8);
  glEnd();

  glBegin(GL_LINES);
  glVertex2f(4.5,9);
  glVertex2f(3.5,9);
  glEnd();

  glBegin(GL_LINES);
  glVertex2f(5,10);
  glVertex2f(4.5,10.5);
  glEnd();

  glBegin(GL_LINES);
  glVertex2f(5.5,10);
  glVertex2f(5.5,11);
  glEnd();

  glBegin(GL_LINES);
  glVertex2f(5.5,8);
  glVertex2f(5.5,7);
  glEnd();

  glBegin(GL_LINES);
  glVertex2f(4.5,8.5);
  glVertex2f(3.5,8);
  glEnd();

  glBegin(GL_LINES);
  glVertex2f(4.5,9.5);
  glVertex2f(3.5,10);
  glEnd();

/*Sand*/
  glColor3f(0.545,0.271,0.075);
  glBegin(GL_POLYGON);
  glVertex2f(-12,2);
  glVertex2f(20,2);
  glVertex2f(20,1);
  glVertex2f(-12,1);
  glEnd();

/*Road*/
  glColor3f(0,0,0);
  glBegin(GL_POLYGON);
  glVertex2f(-12,1);
  glVertex2f(20,1);
  glVertex2f(20,-1);
  glVertex2f(-12,-1);
  glEnd();

/*Strips*/
  glColor3f(1,1,1);
  glBegin(GL_POLYGON);
  glVertex2f(-12,0.1);
  glVertex2f(-11,0.1);
  glVertex2f(-11,-0.1);
  glVertex2f(-12,-0.1);
  glEnd();

  glBegin(GL_POLYGON);
  glVertex2f(4,0.1);
  glVertex2f(5,0.1);
  glVertex2f(5,-0.1);
  glVertex2f(4,-0.1);
  glEnd();

  glBegin(GL_POLYGON);
  glVertex2f(19,0.1);
  glVertex2f(20,0.1);
  glVertex2f(20,-0.1);
  glVertex2f(19,-0.1);
  glEnd();

  glBegin(GL_POLYGON);
  glVertex2f(-4,0.1);
  glVertex2f(-3,0.1);
  glVertex2f(-3,-0.1);
  glVertex2f(-4,-0.1);
  glEnd();

  glBegin(GL_POLYGON);
  glVertex2f(12,0.1);
  glVertex2f(13,0.1);
  glVertex2f(13,-0.1);
  glVertex2f(12,-0.1);
  glEnd();

/*Blackground*/
  glColor3f(0.714,0.718,0.420);
  glBegin(GL_POLYGON);
  glVertex2f(-12,-1);
  glVertex2f(20,-1);
  glVertex2f(20,-9);
  glVertex2f(-12,-9);
  glEnd();

/*House*/
  glColor3f(1,0,0);
  glBegin(GL_TRIANGLES);
  glVertex2f(0,-2);
  glVertex2f(2,-5);
  glVertex2f(-2,-5);
  glEnd();

  glColor3f(0.118,0.565,1);
  glBegin(GL_POLYGON);
  glVertex2f(0,-2);
  glVertex2f(5,-2);
  glVertex2f(7,-5);
  glVertex2f(2,-5);
  glEnd();

  glColor3f(1,0,0);
  glBegin(GL_POLYGON);
  glVertex2f(2,-5);
  glVertex2f(7,-5);
  glVertex2f(7,-8);
  glVertex2f(2,-8);
  glEnd();

  glColor3f(0.118,0.565,1);
  glBegin(GL_POLYGON);
  glVertex2f(2,-5);
  glVertex2f(2,-8);
  glVertex2f(-2,-8);
  glVertex2f(-2,-5);
  glEnd();

  glColor3f(0,0,0);
  glBegin(GL_POLYGON);
  glVertex2f(-1,-6);
  glVertex2f(1,-6);
  glVertex2f(1,-8);
  glVertex2f(-1,-8);
  glEnd();

  glBegin(GL_POLYGON);
  glVertex2f(3,-6);
  glVertex2f(6,-6);
  glVertex2f(6,-7.5);
  glVertex2f(3,-7.5);
  glEnd();

  glColor3f(1,1,1); 
  glBegin(GL_LINES);
  glVertex2f(4.5,-6);
  glVertex2f(4.5,-7.5);
  glEnd();

  glBegin(GL_LINES);
  glVertex2f(3,-6.75);
  glVertex2f(6,-6.75);
  glEnd();

  glColor3f(0.502,0,0.502);
  glBegin(GL_POLYGON);
  glVertex2f(-1,-8);
  glVertex2f(1,-8);
  glVertex2f(0,-9);
  glVertex2f(-2,-9);
  glEnd();

/*Trees*/
  glColor3f(0,0.392,0);
  glBegin(GL_TRIANGLES);
  glVertex2f(11,-2);
  glVertex2f(13,-4);
  glVertex2f(9,-4);
  glEnd();

  glBegin(GL_TRIANGLES);
  glVertex2f(11,-4);
  glVertex2f(13,-6);
  glVertex2f(9,-6);
  glEnd();

  glBegin(GL_TRIANGLES);
  glVertex2f(-8,-2);
  glVertex2f(-6,-4);
  glVertex2f(-10,-4);
  glEnd();

  glBegin(GL_TRIANGLES);
  glVertex2f(-8,-4);
  glVertex2f(-6,-6);
  glVertex2f(-10,-6);
  glEnd();

  glColor3f(0.545,0.271,0.075);
  glBegin(GL_POLYGON);
  glVertex2f(11.5,-6);
  glVertex2f(11.5,-9);
  glVertex2f(10.5,-9);
  glVertex2f(10.5,-6);
  glEnd();

  glBegin(GL_POLYGON);
  glVertex2f(-7.5,-6);
  glVertex2f(-7.5,-9);
  glVertex2f(-8.5,-9);
  glVertex2f(-8.5,-6);
  glEnd();


  glFlush();

}

void myMouseFunc(int button, int state, int x, int y)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{ 
		glColor3f(0.251,0.878,0.816);
  		glBegin(GL_POLYGON);
  		glVertex2f(20,5);
  		glVertex2f(20,2);
  		glVertex2f(14,5);
  		glVertex2f(13,7);
  		glEnd();
  		glFlush();	
	}
}

void myKeyFunc(int key,int x, int y)
{
	if(key == GLUT_KEY_UP)
	{
		glColor3f(1,1,0);
  		glBegin(GL_POLYGON);
  		glVertex2f(5,8);
  		glVertex2f(4.5,8.5);
  		glVertex2f(4.5,9.5);
  		glVertex2f(5,10);
  		glVertex2f(6,10);
  		glVertex2f(6.5,9.5);
  		glVertex2f(6.5,8.5);
  		glVertex2f(6,8);
  		glEnd();
  		glFlush();
	}
	
	else if(key == GLUT_KEY_DOWN)
	{
	
  		glColor3f(1,0.549,0);
  		glBegin(GL_POLYGON);
  		glVertex2f(5,8);
  		glVertex2f(4.5,8.5);
  		glVertex2f(4.5,9.5);
  		glVertex2f(5,10);
  		glVertex2f(6,10);
  		glVertex2f(6.5,9.5);
  		glVertex2f(6.5,8.5);
  		glVertex2f(6,8);
  		glEnd();
  		glFlush();
	}
}


int main(int argc,char** argv)
{
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
  glutInitWindowSize(700,500);
  glutInitWindowPosition(200,200);
  glutCreateWindow("Scenery by Harshpreet Singh Sandhu");
  glClearColor(1,1,1,1);
  gluOrtho2D(-12,20,-9,12);
  glutDisplayFunc(display);
  glutMouseFunc(myMouseFunc);
  glutSpecialFunc(myKeyFunc);
  glutMainLoop();
  return 0;
}
