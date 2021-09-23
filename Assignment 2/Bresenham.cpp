/*
    Assumptions:
    1. Top Left is Origin(0,0)
    2. x1 < x2 and y1< y2
    3. Slope of the line is between 0 and 1.For other slopes we need to modify the algorithm slightly

    Command to run (Windows):
    g++ Bresenham.cpp -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32
*/
#include <graphics.h>
#include <iostream>
using namespace std;

//Bresenham algorithm
void Bresenham(int x1, int y1, int x2, int y2)
{
    // Difference
    int dx = x2 - x1;
    int dy = y2 - y1;

    // Starting Points
    int X = x1;
    int Y = y1;

    // Decision Variable
    int p = (2 * dy) - dx;

    cout << "Starting point: (" + to_string(x1) + "," + to_string(y1) + ")\n";
    cout << "End Point: (" + to_string(x2) + "," + to_string(y2) + ")\n";
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
    outtextxy(x1 - 5, y1 - 5, buffer);

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
            Y++;
            p += (2 * dy) - (2 * dx);
        }
        else
        {
            p += 2 * dy;
        }
        X++;
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

    Bresenham(x1, y1, x2, y2);
    getch();
    closegraph();
}
