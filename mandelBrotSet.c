#include<GL/freeglut.h>
#include<math.h>
#include<stdlib.h>

#define MAX 100
#define threshold 125

typedef struct {
    double real, imaginary;
}complexNumber;

typedef struct {
    double x, y;
}coordinate;

typedef struct {
    GLubyte red, green, blue;
}pixel;
// x will be used to decide the color variations
float x = 0;

int height = 270;
int width = 200;

pixel color, black;

void putPixel(int col, int row, pixel color) {
    glColor3ub(color.red, color.green, color.blue);
    glBegin(GL_POINTS);
    glVertex2i(col, row);
    glEnd();
    glFlush();
}

void init() {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1, 1, 1, 0);
    gluOrtho2D(0, 200, 0, 200);
    //Initialising RGB Values for Black
    black.red = 0;
    black.green = 0;
    black.blue = 0;
}

void display() {

    double x = 0, y = 0;
    int i = 0;
    complexNumber mComplexNumber;
    for (int row = 0;row < height;row++) {
        for (int col = 0;col < width;col++) {
            mComplexNumber.real = (col - width/2.0)*4.0/width;
            mComplexNumber.imaginary = (row - height/2.0)*4.0/width;

            x=0,y=0,i=0;

            while(x*x + y*y <= 4 && i < MAX) {
                y = 2*x*y + mComplexNumber.imaginary;
                x = x*x - y*y + mComplexNumber.real;
                i++;
            }

            if (i >= MAX) {
                //double z = sqrt(mComplexNumber.real*mComplexNumber.real + mComplexNumber.imaginary*mComplexNumber.imaginary);
                //int brightness = 256.0 * log2(1.75 + i - log2(log2(z))) / log2(MAX);
                //color.red = brightness;
                //color.blue = brightness
                color.red = x*255+threshold;
                color.blue = y*255+threshold;
                color.green = 2*x*255+threshold;
            }
            else {
                color.red = 255;
                color.blue = 255;
                color.green = 255;
            }
            putPixel(col, row, color);
        }
    }
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Magical Mystery Tour (Mandelbrot Set)");
    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}