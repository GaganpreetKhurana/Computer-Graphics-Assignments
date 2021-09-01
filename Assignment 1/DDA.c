/*
    C program to implement DDA line drawing algorithm using OpenGL
*/
#include <stdio.h>
#include <GL\glut.h>
#include <math.h>

// Coordinates
int x1;
int y_1;
int x2;
int y2;

// function to set pixel
void setPixel(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
    glFlush();
}

//DDA algorithm
void DDA()
{
    // Abs difference
    int dx = abs(x1 - x2);
    int dy = abs(y_1 - y2);

    // Steps
    float steps = fmax(dx, dy);

    //Calculate Increments
    float xINC, yINC;
    xINC = dx / steps;
    yINC = dy / steps;

    // Initial Points
    float X = (float)x1;
    float Y = (float)y_1;

    printf("Starting point: (%d,%d)\n", x1, y_1);
    printf("End point: (%d,%d)\n", x2, y2);
    printf("Absolute differences: (%d,%d)\n", dx, dy);
    printf("Steps: %f\n", steps);
    printf("Increments: (%f,%f")\n,xINC,yINC);
    printf("STEP:    |(X,Y)|      Point")

        for (int i = 0; i <= steps; i++)
    {
        printf("%d:    |(%f,%f)|      (%d,%d)\n", i + 1, X, Y, (int)round(X), (int)round(Y));

        //Draw
        setPixel((int)round(X), (int)round(Y));

        //Increment
        X += xINC;
        Y += yINC;
    }
}

// function to initialize
void myInit(void)
{
    // making background color black as first
    // 3 arguments all are 0.0
    glClearColor(0.0, 0.0, 0.0, 1.0);

    // making picture color green (in RGB mode), as middle argument is 1.0
    glColor3f(0.0, 1.0, 0.0);

    // breadth of picture boundary is 3 pixel
    glPointSize(3.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // setting window dimension in X- and Y- direction
    gluOrtho2D(-780, 780, -420, 420);
}
int main(int argc, char **argv)
{
    // Take coordinates as input from user
    printf("Enter coordinates of point A:\n");
    printf("x: ");
    scanf("%d", &x1);
    printf("y: ");
    scanf("%d", &y_1);
    printf("Enter coordinates of point B:\n");
    printf("x: ");
    scanf("%d", &x2);
    printf("y: ");
    scanf("%d", &y2);
    printf("\n");

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    // giving window size in X- and Y- direction
    glutInitWindowSize(1024, 720);
    glutInitWindowPosition(0, 0);

    // Giving name to window
    glutCreateWindow("DDA");
    myInit();

    glutDisplayFunc(DDA);
    glutMainLoop();
    return 0;
}

//Terminal command to run on Linux
//gcc DDA.c -lGL -lGLU -lglut && ./a.out
