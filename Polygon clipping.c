#include<GL/glut.h>
#include<stdio.h> 

int points[80][2] = { { 0 } }, new[80][2] = { { 0 } };
int xmin, ymin, xmax, ymax, n;

int leftClip(int, int);
int topClip(int, int);
int rightClip(int, int);
int bottomClip(int, int);

int leftClip(int limit, int xmin) {
	int i, j = 0, x1, y1, x2, y2;
	float m;
	for (i = 0; i < limit; i++) {
		x1 = points[i][0];
		y1 = points[i][1];
		x2 = points[(i + 1) % limit][0];
		y2 = points[(i + 1) % limit][1];
		if (x2 - x1)
			m = (y2 - y1) * 1.0 / (x2 - x1);

		if (x1 <= xmin && x2 <= xmin)
			continue;
		if (x1 >= xmin && x2 >= xmin) {
			new[j][0] = x2;
			new[j++][1] = y2;
			continue;
		}
		if (x1 >= xmin && x2 <= xmin) {
			new[j][0] = xmin;
			new[j++][1] = y1 + m * (xmin - x1);
			continue;
		}
		if (x1 <= xmin && x2 >= xmin) {
			new[j][0] = xmin;
			new[j++][1] = y1 + m * (xmin - x1);
			new[j][0] = x2;
			new[j++][1] = y2;
		}
	}

	for (i = 0; i < j; i++) {
		points[i][0] = new[i][0];
		points[i][1] = new[i][1];
		new[i][0] = new[i][1] = 0;
	}

	if (j < limit)
		for (; i < limit; i++)
			points[i][0] = points[i][1] = 0;

	return j;
}

int topClip(int limit, int ymin) {
	int i, j = 0, x1, y1, x2, y2;
	float m;
	for (i = 0; i < limit; i++) {
		x1 = points[i][0];
		y1 = points[i][1];
		x2 = points[(i + 1) % limit][0];
		y2 = points[(i + 1) % limit][1];
		if (x2 - x1)
			m = (y2 - y1) * 1.0 / (x2 - x1);

		if (y1 <= ymin && y2 <= ymin)
			continue;
		if (y1 >= ymin && y2 >= ymin) {
			new[j][0] = x2;
			new[j++][1] = y2;
			continue;
		}
		if (y1 >= ymin && y2 <= ymin) {
			new[j][0] = x1 + (ymin - y1) / m;
			new[j++][1] = ymin;
			continue;
		}
		if (y1 <= ymin && y2 >= ymin) {
			new[j][0] = x1 + (ymin - y1) / m;
			new[j++][1] = ymin;
			new[j][0] = x2;
			new[j++][1] = y2;
		}
	}

	for (i = 0; i < j; i++) {
		points[i][0] = new[i][0];
		points[i][1] = new[i][1];
		new[i][0] = new[i][1] = 0;
	}

	if (j < limit)
		for (; i < limit; i++)
			points[i][0] = points[i][1] = 0;

	return j;
}

int rightClip(int limit, int xmax) {
	int i, j = 0, x1, y1, x2, y2;
	float m;
	for (i = 0; i < limit; i++) {
		x1 = points[i][0];
		y1 = points[i][1];
		x2 = points[(i + 1) % limit][0];
		y2 = points[(i + 1) % limit][1];
		if (x2 - x1)
			m = (y2 - y1) * 1.0 / (x2 - x1);

		if (x1 >= xmax && x2 >= xmax)
			continue;
		if (x1 <= xmax && x2 <= xmax) {
			new[j][0] = x2;
			new[j++][1] = y2;
			continue;
		}
		if (x1 <= xmax && x2 >= xmax) {
			new[j][0] = xmax;
			new[j++][1] = y1 + m * (xmax - x1);
			continue;
		}
		if (x1 >= xmax && x2 <= xmax) {
			new[j][0] = xmax;
			new[j++][1] = y1 + m * (xmax - x1);
			new[j][0] = x2;
			new[j++][1] = y2;
		}
	}

	for (i = 0; i < j; i++) {
		points[i][0] = new[i][0];
		points[i][1] = new[i][1];
		new[i][0] = new[i][1] = 0;
	}

	if (j < limit)
		for (; i < limit; i++)
			points[i][0] = points[i][1] = 0;

	return j;
}

int bottomClip(int limit, int ymax) {
	int i, j = 0, x1, y1, x2, y2;
	float m;
	for (i = 0; i < limit; i++) {
		x1 = points[i][0];
		y1 = points[i][1];
		x2 = points[(i + 1) % limit][0];
		y2 = points[(i + 1) % limit][1];
		if (x2 - x1)
			m = (y2 - y1) * 1.0 / (x2 - x1);

		if (y1 >= ymax && y2 >= ymax)
			continue;
		if (y1 <= ymax && y2 <= ymax) {
			new[j][0] = x2;
			new[j++][1] = y2;
			continue;
		}
		if (y1 <= ymax && y2 >= ymax) {
			new[j][0] = x1 + (ymax - y1) / m;
			new[j++][1] = ymax;
			continue;
		}
		if (y1 >= ymax && y2 <= ymax) {
			new[j][0] = x1 + (ymax - y1) / m;
			new[j++][1] = ymax;
			new[j][0] = x2;
			new[j++][1] = y2;
		}
	}

	for (i = 0; i < j; i++) {
		points[i][0] = new[i][0];
		points[i][1] = new[i][1];
		new[i][0] = new[i][1] = 0;
	}

	if (j < limit)
		for (; i < limit; i++)
			points[i][0] = points[i][1] = 0;

	return j;
}	

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
  	glColor3f(0,1,0);
	glBegin(GL_POLYGON);		
	glVertex2f(xmin,ymin);
  	glVertex2f(xmin,ymax);
  	glVertex2f(xmax,ymax);
  	glVertex2f(xmax,ymin);
  	glEnd();
  	
  	glColor3f(0,0,0);
	glBegin(GL_LINE_STRIP);

	for (int i = 0; i < n; i++)
	{
		
		glVertex2f(points[i][0], points[i][1]);
		glVertex2f(points[(i + 1) % n][0],points[(i + 1) % n][1]);
		
	
	}
	glEnd();
	glFlush();

}
 
void myMouseFunc(int button, int state, int x, int y)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{ 
	glClear(GL_COLOR_BUFFER_BIT);
  	glColor3f(0,1,0);
	glBegin(GL_POLYGON);		
	glVertex2f(xmin,ymin);
  	glVertex2f(xmin,ymax);
  	glVertex2f(xmax,ymax);
  	glVertex2f(xmax,ymin);
  	glEnd();
  	
  	int result = leftClip(n, xmin);
	result = topClip(result, ymin);
	result = rightClip(result, xmax);
	result = bottomClip(result, ymax);

	glColor3f(0,0,0);
	glBegin(GL_LINE_STRIP);
	for (int i = 0; i < result; i++)
	{
				
		
		glVertex2f(points[i][0], points[i][1]);
		glVertex2f(points[(i + 1) % result][0],points[(i + 1) % result][1]);
		
	}
	glEnd();
	glFlush();
		
	}
	
}


int main(int argc, char** argv) 
{	
	int i;
	printf("Enter the co-ordinates xmin and ymin of the clipping window: ");
	scanf("%d %d", &xmin, &ymin);
	printf("Enter the co-ordinates xmax and ymax of the clipping window: ");
	scanf("%d %d", &xmax, &ymax);

	printf("Enter the number of co-ordinates of the polygon: ");
	scanf("%d", &n);

	for (i = 0; i < n; i++) 
	{
		printf("Enter the co-ordinates of vertex %d: ", (i + 1));
		scanf("%d %d", &points[i][0], &points[i][1]);
	}

	
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (500,500);
	glutInitWindowPosition (100,100);
	glutCreateWindow ("Polygon clipping by Harsh Sandhu");
	glClearColor(1,0,0,0);
	gluOrtho2D(0,300,0,300);
	glutDisplayFunc(display);
	glutMouseFunc(myMouseFunc);
	glutMainLoop();
	return 0;
}
