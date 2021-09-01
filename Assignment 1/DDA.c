#include <stdio.h>
#include<GL/glut.h>
#include<math.h>
int x1;
int y_1;
int x2;
int y2;
void setPixel( int x,int y){
    glBegin(GL_POINTS);
    glVertex2i(x,y);
    glEnd();
    glFlush();
}
void DDA()
 {
     int dx = abs(x1 - x2);
     int dy = abs(y_1 - y2);
     float steps = fmax(dx, dy);
     float xINC,yINC;
     xINC = dx / steps;
     yINC = dy / steps;
     float X = (float)x1;
     float Y = (float)y_1;

     for (int i = 0; i <= steps; i++)
     {
         printf("Step ");
         printf("%d", i + 1  );
         printf( ": " );
         printf( "%f",X );
         printf(" " );
         printf("%f", Y);
         printf( "\n");
         setPixel((int)round(X), (int)round(Y));
         X += xINC;
         Y += yINC;
     }
}
// function to initialize
void myInit (void)
{
	// making background color black as first
	// 3 arguments all are 0.0
	glClearColor(0.0, 0.0, 0.0, 1.0);
	
	// making picture color green (in RGB mode), as middle argument is 1.0
	glColor3f(1.0, 1.0, 0.0);
	
	// breadth of picture boundary is 1 pixel
	glPointSize(3.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	// setting window dimension in X- and Y- direction
	gluOrtho2D(-780, 780, -420, 420);
}
int main(int argc, char** argv)
{
    
    printf("Enter coordinates of point A:\n");
    printf("x: ");
    scanf("%d",&x1);
    printf("\ny: ");
    scanf("%d",&y_1);
    printf("\nEnter coordinates of point B:\n");
    printf("x: ");
    scanf("%d",&x2);
    printf("\ny: ");
    scanf("%d",&y2);
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
//g++ DDA.c -lGL -lGLU -lglut