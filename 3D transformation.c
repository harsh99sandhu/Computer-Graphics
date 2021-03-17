#include<GL/glut.h>
#include<stdio.h> 
#include<math.h>
float
x1=0, y_1=30, z1=0, 
x2=20, y2=30, z2=0,
x3=20, y3=0, z3=0,
x4=0, y4=0, z4=0,
x5=0+10, y5=30+10, z5=-40,
x6=20+10, y6=30+10, z6=-40,
x7=20+10, y7=0+10, z7=-40,
x8=0+10, y8=0+10, z8=-40,
tx,ty,tz,xc,yc,zc,theta,sx,sy,sz;
int c,a;

void translate(float *x,float *y,float *z,float tx,float ty,float tz)
{
    *x = *x + tx;
    *y = *y + ty;
    *z = *z + tz;
}

void rotation(float *x,float *y,float *z,float theta)
{
    theta = (3.1415 / 180 ) * theta;
    float xTemp = *x;
    float yTemp = *y;
    switch(a)
    {
    	case 1:
    	*x=*x;
    	*y = *y * cos(theta) - *z * sin(theta);
    	*z = yTemp * sin(theta) + *z * cos(theta) ;
    	
    	case 2:
    	*x = *z * sin(theta) + *x * cos(theta);
    	*y=*y;
   	*z = *y * cos(theta) - xTemp * sin(theta) ;
    	
    	case 3:
    	*x = *x * cos(theta) - *y * sin(theta);
    	*y = xTemp * sin(theta) + *y * cos(theta) ;
    	*z=*z;
    	break;
    }
    
}

void scale(float *x,float *y,float *z,float sx,float sy,float sz)
{
    *x = *x * sx;
    *y = *y * sy;
    *z = *z * sz;
}
void reflection(float *x,float *y,float *z)
{
	switch(a)
	{
		case 1:
		*x=*x;
		*y=*y;
		*z=-*z;
		break;
		case 2:
		*x=-*x;
		*y=*y;
		*z=*z;
		break;
		case 3:
		*x=*x;
		*y=-*y;
		*z=*z;
		break;
	}
}

void shear(float *x,float *y,float *z,float sx,float sy,float sz)
{

    switch(a)
	{
		case 1:
		*x=*x;
		*y=*y + sy * (*x);
		*z=*z + sz * (*x);
		break;
		case 2:
		*x = *x + sx * (*y);
		*y=*y;
		*z=*z + sz * (*y);
		break;
		case 3:
		*x = *x + sx * (*z);
    		*y = *y + sy * (*z);
    		*z=*z;
		break;
	}
}

void draw_quad()
{

    	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    	
      // Begin drawing the color cube with 6 quads
      // Front face (y = 1.0f)
      // Define vertices in counter-clockwise (CCW) order with normal pointing out
      glBegin(GL_LINE_LOOP);
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f(x1,y_1,z1);
      glVertex3f(x2,y2,z2);
      glVertex3f(x3,y3,z3);
      glVertex3f(x4,y4,z4);
      glEnd();
 
      // Back face (y = -1.0f)
      glBegin(GL_LINE_LOOP);
      glColor3f(1.0f, 0.5f, 0.0f);     // Orange
      glVertex3f(x5,y5,z5);
      glVertex3f(x6,y6,z6);
      glVertex3f(x7,y7,z7);
      glVertex3f(x8,y8,z8);
      glEnd();
 
      // Top face  (z = 1.0f)
      glBegin(GL_LINE_LOOP);
      glColor3f(1.0f, 0.0f, 0.0f);     // Red
      glVertex3f(x5,y5,z5);
      glVertex3f(x6,y6,z6);
      glVertex3f(x2,y2,z2);
      glVertex3f(x1,y_1,z1);
      glEnd();
 
      // Bottom face (z = -1.0f)
      glBegin(GL_LINE_LOOP);
      glColor3f(1, 1, 0);     // Yellow
      glVertex3f(x8,y8,z8);
      glVertex3f(x7,y7,z7);
      glVertex3f(x3,y3,z3);
      glVertex3f(x4,y4,z4);
      glEnd();
 
      // Left face (x = -1.0f)
      glBegin(GL_LINE_LOOP);
      glColor3f(0.0f, 0.0f, 1.0f);  // Blue
      glVertex3f(x1,y_1,z1);
      glVertex3f(x5,y5,z5);
      glVertex3f(x8,y8,z8);
      glVertex3f(x4,y4,z4);
      glEnd();
 
      // Right face (x = 1.0f)
      glBegin(GL_LINE_LOOP);
      glColor3f(1.0f, 0.0f, 1.0f); // Magenta
      glVertex3f(x2,y2,z2);
      glVertex3f(x6,y6,z6);
      glVertex3f(x7,y7,z7);
      glVertex3f(x3,y3,z3);
 	  glEnd();

    glFlush();

}

void display()
{
	draw_quad();
}

void myMouseFunc(int button, int state, int x, int y)
{

	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{ 
		
        	switch(c)
	{
		case 1: 
        	translate(&x1, &y_1, &z1, tx, ty,tz);
        	translate(&x2, &y2, &z2, tx, ty,tz);
        	translate(&x3, &y3, &z3, tx, ty,tz);
        	translate(&x4, &y4, &z4, tx, ty,tz);
        	translate(&x5, &y5, &z5, tx, ty,tz);
        	translate(&x6, &y6, &z6, tx, ty,tz);
        	translate(&x7, &y7, &z7, tx, ty,tz);
        	translate(&x8, &y8, &z8, tx, ty,tz);
        	draw_quad();
		
    		break;
    		
    		case 2:
  
        	translate(&x1,&y_1,&z1,-xc,-yc,-zc);
        	translate(&x2,&y2,&z2,-xc,-yc,-zc);
        	translate(&x3,&y3,&z3,-xc,-yc,-zc);
        	translate(&x4,&y4,&z4,-xc,-yc,-zc);
        	translate(&x5,&y5,&z5,-xc,-yc,-zc);
        	translate(&x6,&y6,&z6,-xc,-yc,-zc);
        	translate(&x7,&y7,&z7,-xc,-yc,-zc);
        	translate(&x8,&y8,&z8,-xc,-yc,-zc);
		rotation(&x1, &y_1,&z1, theta);
        	rotation(&x2, &y2,&z2, theta);
        	rotation(&x3, &y3,&z3, theta);
        	rotation(&x4, &y4,&z4, theta);
        	rotation(&x5, &y5,&z5, theta);
        	rotation(&x6, &y6,&z6, theta);
        	rotation(&x7, &y7,&z7, theta);
        	rotation(&x8, &y8,&z8, theta);
        	translate(&x1,&y_1,&z1,xc,yc,zc);
        	translate(&x2,&y2,&z2,xc,yc,zc);
        	translate(&x3,&y3,&z3,xc,yc,zc);
        	translate(&x4,&y4,&z4,xc,yc,zc);
        	translate(&x5,&y5,&z5,xc,yc,zc);
        	translate(&x6,&y6,&z6,xc,yc,zc);
        	translate(&x7,&y7,&z7,xc,yc,zc);
        	translate(&x8,&y8,&z8,xc,yc,zc);
        	draw_quad();
        	
    		break;
    		
    		case 3:
    		
		scale(&x1, &y_1,&z1, sx,sy,sz);
        	scale(&x2, &y2,&z2, sx,sy,sz);
        	scale(&x3, &y3,&z3, sx,sy,sz);
        	scale(&x4, &y4,&z4, sx,sy,sz);
        	scale(&x5, &y5,&z5, sx,sy,sz);
        	scale(&x6, &y6,&z6, sx,sy,sz);
        	scale(&x7, &y7,&z7, sx,sy,sz);
        	scale(&x8, &y8,&z8, sx,sy,sz);
		draw_quad();
    		break;
    		
    		case 4:
    		
    		reflection(&x1, &y_1, &z1);
        	reflection(&x2, &y2, &z2);
        	reflection(&x3, &y3, &z3);
        	reflection(&x4, &y4, &z4);
        	reflection(&x5, &y5, &z5);
        	reflection(&x6, &y6, &z6);
        	reflection(&x7, &y7, &z7);
        	reflection(&x8, &y8, &z8);
        	draw_quad();
    		break;
    		
    		case 5:
    		shear(&x1, &y_1,&z1, sx,sy,sz);
        	shear(&x2, &y2,&z2, sx,sy,sz);
        	shear(&x3, &y3,&z3, sx,sy,sz);
        	shear(&x4, &y4,&z4, sx,sy,sz);
        	shear(&x5, &y5,&z5, sx,sy,sz);
        	shear(&x6, &y6,&z6, sx,sy,sz);
        	shear(&x7, &y7,&z7, sx,sy,sz);
        	shear(&x8, &y8,&z8, sx,sy,sz);
		draw_quad();
    		break;
	}}
	
}

int main(int argc, char** argv) 
{	
	//printf("Enter the first point (x1,y_1,z1) : ");
	//scanf("%f%f%f", &x1, &y_1, &z1);
       // printf("Enter the second point (x2,y2,z2) : ");
	//scanf("%f%f%f", &x2, &y2, &z2);
	printf("Enter \n1:Translation\n2:Rotation\n3:Scaling\n4:Reflection\n5:Shearing\n");
	scanf("%d",&c);
	switch(c)
	{
		case 1: 
		printf("Enter the translation factor (tx,ty,tz) : "); 
       		scanf("%f%f%f",&tx,&ty,&tz);
       		break;
       		
       		case 2:
       		printf("Enter the arbitary point (xc,yc,zc) : ");
		scanf("%f%f%f", &xc, &yc, &zc);
		printf("Enter the rotation angle in degree(theta) : ");
		scanf("%f", &theta);
		printf("1- x-axis\n2- y-axis\n3- z-axis\n");
    		scanf("%d",&a);
		break;
		
		case 3:
		
		printf("Enter the scaling factors (sx,sy,sz) : ");
		scanf("%f%f%f", &sx, &sy,&sz);
		break;
		
		case 4:
		printf("1- xy-axis\n2- yz-axis\n3- xz-axis\n");
    		scanf("%d",&a);
		break;
		
       		case 5:
       		printf("1- x-axis\n2- y-axis\n3- z-axis\n");
    		scanf("%d",&a);
		printf("Enter the shearing factors (sx,sy,sz) : ");
		scanf("%f%f%f", &sx, &sy,&sz);
       		break;
	}

	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize (640,480);
	glutInitWindowPosition (200,200);
	glutCreateWindow ("3D transformation by Harsh Sandhu");
	glClearColor(1,1,1,1);
	glOrtho(-200,200,-200,200,-200,200);    
	glEnable(GL_DEPTH_TEST);
	glutDisplayFunc(display);
	glutMouseFunc(myMouseFunc);
	glutMainLoop();
	return 0;
}
