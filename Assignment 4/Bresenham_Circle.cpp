/*
    Assumptions:
    1. Top Left is Origin(0,0)
    
    Command to run (Windows):
    g++ Bresenham_Circle.cpp -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32 && a
*/

#include <graphics.h>
#include <iostream>
#include <math.h>
using namespace std;

void plotPoints(int x_center, int y_center, int X, int Y)
{
    // (x,y)
    cout << "(" << X + x_center << ", " << -Y + y_center << ") | ";
    putpixel(X + x_center, -Y + y_center, 2);
    delay(10);

    // (y,x)
    cout << "(" << Y + x_center << ", " << -X + y_center << ") | ";
    putpixel(Y + x_center, -X + y_center, 3);
    delay(10);

    // (y,-x)
    cout << "(" << Y + x_center << ", " << X + y_center << ") | ";
    putpixel(Y + x_center, X + y_center, 4);
    delay(10);

    // (x,-y)
    cout << "(" << X + x_center << ", " << Y + y_center << ") | ";
    putpixel(X + x_center, Y + y_center, 5);
    delay(10);

    // (-x,-y)
    cout << "(" << -X + x_center << ", " << Y + y_center << ") | ";
    putpixel(-X + x_center, Y + y_center, 6);
    delay(10);

    // (-y,-x)
    cout << "(" << -Y + x_center << ", " << X + y_center << ") | ";
    putpixel(-Y + x_center, X + y_center, 7);
    delay(10);

    // (-y,x)
    cout << "(" << -Y + x_center << ", " << -X + y_center << ") | ";
    putpixel(-Y + x_center, -X + y_center, 8);
    delay(10);

    // (-x,y)
    cout << "(" << -X + x_center << ", " << -Y + y_center << ")\n";
    putpixel(-X + x_center, -Y + y_center, 9);
    delay(10);
}
void DrawCircle(int x_center, int y_center, int r)
{
    cout << "Center: (" << x_center << "," << y_center << ")\n";
    cout << "Radius: " << r << endl;
    cout << "Points: \n";
    cout << "(x,y)  |  (y,x)   |  (y,-x)   |  (x,-y)  |   (-x,-y)   |  (-y,-x)   |  (-y,x)   |  (-x,y)\n";

    // for printing text at desired screen location.
    char buffer[30];

    // Title
    sprintf(buffer, " Bresenham Circle Drawing Algorithm ");
    outtextxy(200, 5, buffer);

    //Radius
    sprintf(buffer, "Radius: %d", r);
    outtextxy(250, 35, buffer);

    //Centre Point
    putpixel(x_center, y_center, 10);
    sprintf(buffer, "Centre: (%d,%d)", x_center, y_center);
    outtextxy(x_center - 45, y_center + 15, buffer);

    // Starting Points
    int X = 0;
    int Y = r;

    // Printing the initial point on the axes after translation
    plotPoints(x_center, y_center, X, Y);

    // Initialising the value of d (Decision Parameter)
    int d = 3 - 2 * r;

    while (Y >= X)
    {
        X++;

        // Check the decision parameter and update Y,d accordingly
        if (d > 0)
        {
            Y--;
            d += 4 * (X - Y) + 10;
        }
        else
        {
            d += 4 * X + 6;
        }

        //Plot he points in all 8 octants
        plotPoints(x_center, y_center, X, Y);
    }
}

int main()
{
    int gDrive = DETECT;
    int gMode;

    // Coordinates
    int x_center;
    int y_center;
    int r;

    // Take center coordinates and radius as input from user
    cout << "Enter coordinates of Center:\n";
    cout << "x: ";
    cin >> x_center;
    cout << "y: ";
    cin >> y_center;

    cout << "Enter Radius: ";
    cin >> r;
    cout << "\n\n";

    if (r < 0)
    {
        cout << "Radius cannot be negative!\n";
        return 0;
    }
    else
    {
        // Draw Circle using Bresenham Circle Drawing Algorithm
        initgraph(&gDrive, &gMode, NULL);
        DrawCircle(x_center, y_center, r);
        getch();
    }
}
