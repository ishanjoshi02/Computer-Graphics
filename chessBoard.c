#include <GL/glut.h>

typedef struct {
  GLubyte red, green, blue;
}pixel;

pixel c, d, boundary, fill;

int sign(int x) {
  if (x>=0)
    return 0;
  return 1;
}
void drawLine(int X1, int Y1, int X2, int Y2) {
  //DDA Line Drawing Algorithm
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
    glColor3ub(255,255,255);
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
void drawSquare(int x1, int y1, int x2, int y2) {
  //Used to Draw Squares using the co-ordinates of the two opposite vertices
  drawLine(x1, y1, x2, y1);
  drawLine(x1, y1, x1, y2);
  drawLine(x2, y2, x1, y2);
  drawLine(x2, y2, x2, y1);
}
void boundaryFill(int x, int y, pixel f) {
  glReadPixels(x, y, 1, 1, GL_RGB, GL_UNSIGNED_BYTE, &c);
  if (c.red != boundary.red && c.green != boundary.green && c.blue != boundary.blue &&
        c.red != f.red && c.green != f.green && c.blue != f.blue) {
    /* code */
    glBegin(GL_POINTS);
    glColor3ub(f.red, f.green, f.blue);
    glVertex2i(x,y);
    glEnd();
    glFlush();

    //recursive calls go here
    boundaryFill(x+1,y,f);
    boundaryFill(x-1,y,f);
    boundaryFill(x,y+1,f);
    boundaryFill(x,y-1,f);
  }
}
void init() {
  //Used to Initialise the Frame
  glClear(GL_COLOR_BUFFER_BIT);
  glClearColor(0,0,1,0);
  gluOrtho2D(0, 800, 0, 800);
  //Setting Boundary Color as White
  boundary.red = 1;
  boundary.green = 1;
  boundary.blue = 1;
}
void display() {
  //Loop to draw the 64 chess Squares
  int x, y, i, j, count;
  for(i=0,y=0;i<8;i++,y+=20) {
    for(j=0,x=0;j<8;j++,x+=20) {
      drawSquare(x, y, x+20, y+20);
    }
  }
  pixel newPixel;
  for(i=0,y=0,count=0;i<8;i++,y+=20) {
    for(j=0,x=0;j<8;j++,x+=20) {
      if (count == 0) {
        newPixel.red = 255;
        newPixel.blue = 255;
        newPixel.green = 255;
        count = 1;
      }
      else {
        newPixel.red = 0;
        newPixel.blue = 0;
        newPixel.green = 0;
        count = 0;
      }
      boundaryFill(x+10, y+10, newPixel);
    }
  }
}
int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(640, 480);
  glutInitWindowPosition(20,10);
  glutCreateWindow("Chess Board");
  init();
  glClear(GL_COLOR_BUFFER_BIT);
  glutDisplayFunc(display);
  glFlush();
  glutMainLoop();

  return 0;
}
