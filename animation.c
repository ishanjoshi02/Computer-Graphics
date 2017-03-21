#include<GL/freeglut.h>
#include <unistd.h>
int sign(int x) {
    if (x>=0)
        return 1;
    return 0;
}
void ddaWhite(int X1,int Y1,int X2,int Y2){
 float x,y,dx,dy,length;
	int i;
	
	dx=abs(X2-X1);
	dy=abs(Y2-Y1);
	if(dx>=dy)
		length=dx;
	else
		length=dy;
	dx=(X2-X1)/length;
	dy=(Y2-Y1)/length;
	x=X1 + 0.5*sign(X1);
	y=Y1 + 0.5*sign(Y1);
	i=1;
	while(i<=length)
	{
	
     glColor3f(1.0,1.0,1.0);
     glBegin(GL_POINTS);
	 glVertex2i(x,y);
     glEnd();
     glFlush();
	 x=x+dx;
	 y=y+dy;
     i=i+1;
	}
	glFlush();
}
void ddaBlack(int X1,int Y1,int X2,int Y2){
 float x,y,dx,dy,length;
	int i;
	
	dx=abs(X2-X1);
	dy=abs(Y2-Y1);
	if(dx>=dy)
		length=dx;
	else
		length=dy;
	dx=(X2-X1)/length;
	dy=(Y2-Y1)/length;
	x=X1 + 0.5*sign(X1);
	y=Y1 + 0.5*sign(Y1);
	i=1;
	while(i<=length)
	{
	
     glColor3f(0,0,0);
     glBegin(GL_POINTS);
	 glVertex2i(x,y);
     glEnd();
     glFlush();
	 x=x+dx;
	 y=y+dy;
     i=i+1;
	}
	glFlush();
}
void init() {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1,1,1,0);
    gluOrtho2D(0,800,0,800);
}
void drawBar(int x1, int y1, int x2, int y2) {
    ddaWhite(x1,y1,x2,y1);
    ddaWhite(x1,y1,x1,y2);
    ddaWhite(x2,y1,x2,y2);
    ddaWhite(x1,y2,x2,y2);
}
void drawBarBlack(int x1, int y1, int x2, int y2) {
    ddaBlack(x1,y1,x2,y1);
    ddaBlack(x1,y1,x1,y2);
    ddaBlack(x2,y1,x2,y2);
    ddaBlack(x1,y2,x2,y2);
}
void display() {
    //Code to display Platform and Pole i.e. Stationary Objects
    drawBar(50, 50, 200, 0);
    drawBar(50,50,60,720);
    ddaBlack(51,50,59,50);
    int x1=61, y1=60, y2 = 200;
    int x2 = 400;
    for(;y2<=720;y1+=4,y2+=4) {
        drawBar(x1, y1, x2,y2);
        usleep(1000000);
        drawBarBlack(x1, y1, x2,y2);
    }
}
int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(720,480);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Oh it moves too!!!!!!");
    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}