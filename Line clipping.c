#include<GL/glut.h>
#include<stdio.h>
int v;
	
typedef struct coordinate
{
	int x,y;
	char code[4];
}PT;

PT p1,p2,p3,p4,ptemp;
 
void drawwindow();
void drawline(PT p1,PT p2);
PT setcode(PT p);
int visibility(PT p1,PT p2);
PT resetendpt(PT p1,PT p2);

void drawwindow()
{

	glBegin(GL_LINES);		
	glVertex2f(100,0);
  	glVertex2f(300,0);
	glVertex2f(300,0);
  	glVertex2f(300,250);
	glVertex2f(300,250);
  	glVertex2f(100,250);
	glVertex2f(100,250);
	glVertex2f(100,0);
	glEnd();

}
 
void drawline(PT p1,PT p2)
{
	glBegin(GL_LINES);	
	glVertex2f(p1.x,p1.y);
  	glVertex2f(p2.x,p2.y);
	glEnd();
}
 
PT setcode(PT p)	//for setting the 4 bit code
{
	PT ptemp;
	
	if(p.y<0)
		ptemp.code[0]='1';	//Top
	else
		ptemp.code[0]='0';
	
	if(p.y>250)
		ptemp.code[1]='1';	//Bottom
	else
		ptemp.code[1]='0';
		
	if(p.x>300)
		ptemp.code[2]='1';	//Right
	else
		ptemp.code[2]='0';
		
	if(p.x<100)
		ptemp.code[3]='1';	//Left
	else
		ptemp.code[3]='0';
	
	ptemp.x=p.x;
	ptemp.y=p.y;
	
	return(ptemp);
}
 
int visibility(PT p1,PT p2)
{
	int i,flag=0;
	
	for(i=0;i<4;i++)
	{
		if((p1.code[i]!='0') || (p2.code[i]!='0'))
			flag=1;
	}
	
	if(flag==0)
		return(0);
	
	for(i=0;i<4;i++)
	{
		if((p1.code[i]==p2.code[i]) && (p1.code[i]=='1'))
			flag='0';
	}
	
	if(flag==0)
		return(1);
	
	return(2);
}
 
PT resetendpt(PT p1,PT p2)
{
	PT temp;
	int x,y,i;
	float m,k;
	
	if(p1.code[3]=='1')
		x=100;
	
	if(p1.code[2]=='1')
		x=300;
	
	if((p1.code[3]=='1') || (p1.code[2]=='1'))
	{
		m=(float)(p2.y-p1.y)/(p2.x-p1.x);
		k=(p1.y+(m*(x-p1.x)));
		temp.y=k;
		temp.x=x;
		
		for(i=0;i<4;i++)
			temp.code[i]=p1.code[i];
		
		if(temp.y<=250 && temp.y>=0)
			return (temp);
	}
	
	if(p1.code[0]=='1')
		y=0;
	
	if(p1.code[1]=='1')
		y=250;
		
	if((p1.code[0]=='1') || (p1.code[1]=='1'))
	{
		m=(float)(p2.y-p1.y)/(p2.x-p1.x);
		k=(float)p1.x+(float)(y-p1.y)/m;
		temp.x=k;
		temp.y=y;
		
		for(i=0;i<4;i++)
			temp.code[i]=p1.code[i];
		
		return(temp);
	}
	else
		return(p1);
}

void display()  
{  
	glClear(GL_COLOR_BUFFER_BIT);
  	glColor3f(0,1,0);   
	drawwindow();
	drawline(p1,p2);

	p1=setcode(p1);
	p2=setcode(p2);
	v=visibility(p1,p2);
	glFlush();
}	
void myMouseFunc(int button, int state, int x, int y)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{ 
	glClear(GL_COLOR_BUFFER_BIT);	
	glColor3f(0,1,0); 		
	switch(v)
	{
	case 0:drawwindow();
		drawline(p1,p2);
		break;
	case 1:	drawwindow();
		break;
	case 2:	p3=resetendpt(p1,p2);
		p4=resetendpt(p2,p1);
		drawwindow();
		drawline(p3,p4);
		break;
	}
	glFlush();	
	}
}
	


int main(int argc, char** argv) 
{	

	printf("Enter x1 and y1\n");
	scanf("%d %d",&p1.x,&p1.y);
	printf("Enter x2 and y2\n");
	scanf("%d %d",&p2.x,&p2.y);
	

	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (500,500);
	glutInitWindowPosition (100,100);
	glutCreateWindow ("Line clipping by Harsh Sandhu");
	glClearColor(1,0,0,0);
	gluOrtho2D(-100,400,-100,400);
	glutDisplayFunc(display);
  	glutMouseFunc(myMouseFunc);
	glutMainLoop();
	return 0;
}
