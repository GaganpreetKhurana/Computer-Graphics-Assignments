/*
    C program to implement DDA line drawing algorithm using OpenGL
    
    Keep large absolute difference to see the animation so that the
    number of steps are > 150

    ORIGIN (0,0) is set at TOP left corner - x:[0,1920], y:[0,1080]
    To move it to center of screen comment line 94 and uncomment line 97 - x:[-960,960], y:[-540,540]

    Terminal command to run on Linux
    g++ DDA.c -lGL -lGLU -lglut && ./a.out
*/
#include <stdio.h>
#include <GL/glut.h>
#include <math.h>

// Coordinates
int x1;
int y_1;
int x2;
int y2;

//SET SCREEN SIZE/ORIGIN
const int SCREEN_WIDTH_DDA = 1920;
const int SCREEN_HEIGHT_DDA = 1080;
const int SCREEN_ORIGIN_X_DDA = 0;
const int SCREEN_ORIGIN_Y_DDA = 0;


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
    int dx =  x2 - x1; 
    int dy = y2 - y_1;
    
    // Steps
    float steps = fmax(abs(dx),abs(dy));

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
    printf("Steps: %.3f\n", steps);
    printf("Increments: (%.3f,%.3f)\n",xINC,yINC);
    printf("STEP:    |(X,Y)|                      Point\n\n");

    for (int i = 0; i <= steps; i++)
    {
        printf("%d:    |(%.3f,%.3f)|      (%d,%d)\n", i, X, Y, (int)round(X), (int)round(Y));

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
    glPointSize(2.0);
    glMatrixMode(GL_PROJECTION);
    //glLoadIdentity();

    // setting window dimension in X- and Y- direction

    // ORIGIN at TOP LEFT
    gluOrtho2D(0, SCREEN_WIDTH_DDA, SCREEN_HEIGHT_DDA, 0);

    // ORIGIN at CENTER
    //gluOrtho2D(-(SCREEN_WIDTH_DDA/2),(SCREEN_WIDTH_DDA/2),-(SCREEN_HEIGHT_DDA/2),(SCREEN_HEIGHT_DDA/2));
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
    glutInitWindowSize(SCREEN_WIDTH_DDA, SCREEN_HEIGHT_DDA);
    glutInitWindowPosition(SCREEN_ORIGIN_X_DDA, SCREEN_ORIGIN_Y_DDA);

    // Giving name to window
    glutCreateWindow("DDA");
    myInit();

    glutDisplayFunc(DDA);
    
    glutMainLoop();
    
    return 0;
}