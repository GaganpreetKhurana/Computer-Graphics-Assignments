/*
    Assumptions:
    1. Top Left is Origin(0,0)
    2. All inputs are +ve
    
    Command to run (Windows):
    g++ Bresenham.cpp -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32 && a
*/

#include <graphics.h>
#include <iostream>
#include <math.h>
using namespace std;

void BresenhamLow(int x1, int y1, int x2, int y2)
{
    /*
        For -1 < Slope < 1 
        X coordinate is incremented by 1 in every interation of while loop
    */

    // Difference
    int dx = x2 - x1;
    int dy = y2 - y1;

    // Starting Points
    int X = x1;
    int Y = y1;

    // To handle negative slope
    int yi = 1;
    if (dy < 0)
    {
        yi = -1;
        dy = -dy;
    }

    // Decision Variable
    int p = (2 * dy) - dx;

    cout << "Difference: (" + to_string(dx) + "," + to_string(dy) + ")\n";
    cout << "Decision Variable: " + to_string(p) + "\n";
    cout << "Points(X,Y)     |    Decision Variable\n";

    // for printing text at desired screen location.
    char buffer[30];

    // Title
    sprintf(buffer, " Bresenham Line Drawing Algorithm ");
    outtextxy(200, 5, buffer);

    //Start Point
    sprintf(buffer, "(%d,%d)", x1, y1);
    outtextxy(x1 - 15, y1 - 15, buffer);

    //End Point
    sprintf(buffer, "(%d,%d)", x2, y2);
    outtextxy(x2 + 5, y2 + 5, buffer);

    while (X <= x2)
    {
        cout << "(" << X << "," << Y << ")       |   " << p << endl;

        delay(50);

        putpixel(X, Y, 7);

        if (p >= 0)
        {
            Y += yi;
            p += (2 * dy) - (2 * dx);
        }
        else
        {
            p += 2 * dy;
        }
        X++;
    }
}

void BresenhamHigh(int x1, int y1, int x2, int y2)
{
    /*
        For Slope <= -1 or Slope >=1 
        Y coordinate is incremented by 1 in every interation
        Basically X and Y are interchanged in this function compared to BresenhamLow
    */

    // Difference
    int dx = x2 - x1;
    int dy = y2 - y1;

    // Starting Points
    int X = x1;
    int Y = y1;

    // To handle negative slope
    int xi = 1;
    if (dx < 0)
    {
        xi = -1;
        dx = -dx;
    }

    // Decision Variable
    int p = (2 * dx) - dy;

    cout << "Difference: (" + to_string(dx) + "," + to_string(dy) + ")\n";
    cout << "Decision Variable: " + to_string(p) + "\n";
    cout << "Points(X,Y)     |    Decision Variable\n";

    // for printing text at desired screen location.
    char buffer[30];

    // Title
    sprintf(buffer, " Bresenham Line Drawing Algorithm ");
    outtextxy(200, 5, buffer);

    //Start Point
    sprintf(buffer, "(%d,%d)", x1, y1);
    outtextxy(x1 - 15, y1 - 15, buffer);

    //End Point
    sprintf(buffer, "(%d,%d)", x2, y2);
    outtextxy(x2 + 5, y2 + 5, buffer);

    while (Y <= y2)
    {
        cout << "(" << X << "," << Y << ")       |   " << p << endl;

        delay(50);

        putpixel(X, Y, 7);

        if (p >= 0)
        {
            X += xi;
            p += (2 * dx) - (2 * dy);
        }
        else
        {
            p += 2 * dx;
        }
        Y++;
    }
}

void DrawLine(int x1, int y1, int x2, int y2)
{

    cout << "Point A: (" + to_string(x1) + "," + to_string(y1) + ")\n";
    cout << "Point B: (" + to_string(x2) + "," + to_string(y2) + ")\n";

    if (abs(y2 - y1) < abs(x2 - x1))
    {
        //  -1 < Slope < 1

        //Because the line is drawn with the increasing value of x (X++ in the loop in algorithm)
        if (x1 > x2)
        {
            BresenhamLow(x2, y2, x1, y1);
        }
        else
        {
            BresenhamLow(x1, y1, x2, y2);
        }
    }
    else
    { // Slope =< -1 or slope >= 1

        //Because the line is drawn with the increasing value of y (Y++ in the loop in algorithm)
        if (y1 > y2)
        {
            BresenhamHigh(x2, y2, x1, y1);
        }
        else
        {
            BresenhamHigh(x1, y1, x2, y2);
        }
    }
}
int main()
{
    int gDrive = DETECT;
    int gMode;
    initgraph(&gDrive, &gMode, NULL);

    // Coordinates
    int x1;
    int y1;
    int x2;
    int y2;

    // Take coordinates as input from user
    cout << "Enter coordinates of point A:\n";
    cout << "x: ";
    cin >> x1;
    cout << "y: ";
    cin >> y1;
    cout << "Enter coordinates of point B:\n";
    cout << "x: ";
    cin >> x2;
    cout << "y: ";
    cin >> y2;
    cout << "\n";

    // Draw Line using Bresenham Line Drawing Algorithm
    DrawLine(x1, y1, x2, y2);
    getch();
    closegraph();
}
