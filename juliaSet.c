#include<GL/freeglut.h>
#define MAX 300

typedef struct {
    double real, imaginary;
}complexNumber;

complexNumber z, c;

int height = 200;
int width = 200;

typedef struct {
    GLubyte red, green, blue;
}pixel;

pixel color;

void putPixel(int col, int row, pixel color) {
    glColor3f(color.red, color.green, color.blue);
    glBegin(GL_POINTS);
    glVertex2i(col, row);
    glEnd();
    glFlush();
}

void init() {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1,0,0,0);
    gluOrtho2D(0, 200, 0, 200);
    //Initialising Values for the Constant Imaginary Number
    c.real = 12;
    c.imaginary = 10;
}

void display() {
    int n;
    z.real = 2;
    z.imaginary = 9;
    while(n<MAX && abs(z) < 2) {

    }   
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Magical Mystery Tour (Julia Set)");
    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
