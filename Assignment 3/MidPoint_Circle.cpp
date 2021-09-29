/*
    Assumptions:
    1. Top Left is Origin(0,0)
    
    Command to run (Windows):
    g++ MidPoint_Circle.cpp -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32 && a
*/

#include <graphics.h>
#include <iostream>
#include <math.h>
using namespace std;

void plotPoints(int x, int y, int X, int Y)
{
    // (x,y)
    cout << "(" << X + x << ", " << -Y + y << ") | ";
    putpixel(X + x, -Y + y, 2);
    delay(10);

    // (y,x)
    cout << "(" << Y + x << ", " << -X + y << ") | ";
    putpixel(Y + x, -X + y, 3);
    delay(10);

    // (y,-x)
    cout << "(" << Y + x << ", " << X + y << ") | ";
    putpixel(Y + x, X + y, 4);
    delay(10);

    // (x,-y)
    cout << "(" << X + x << ", " << Y + y << ") | ";
    putpixel(X + x, Y + y, 5);
    delay(10);

    // (-x,-y)
    cout << "(" << -X + x << ", " << Y + y << ") | ";
    putpixel(-X + x, Y + y, 6);
    delay(10);

    // (-y,-x)
    cout << "(" << -Y + x << ", " << X + y << ") | ";
    putpixel(-Y + x, X + y, 7);
    delay(10);

    // (-y,x)
    cout << "(" << -Y + x << ", " << -X + y << ") | ";
    putpixel(-Y + x, -X + y, 8);
    delay(10);

    // (-x,y)
    cout << "(" << -X + x << ", " << -Y + y << ")\n";
    putpixel(-X + x, -Y + y, 9);
    delay(10);
}
void DrawCircle(int x, int y, int r)
{
    cout << "Center: (" << x << "," << y << ")\n";
    cout << "Radius: " << r << endl;
    cout << "Points: \n";
    cout << "(x,y)  |  (y,x)   |  (y,-x)   |  (x,-y)  |   (-x,-y)   |  (-y,-x)   |  (-y,x)   |  (-x,y)\n";

    // for printing text at desired screen location.
    char buffer[30];

    // Title
    sprintf(buffer, " Mid Point Circle Drawing Algorithm ");
    outtextxy(200, 5, buffer);

    //Radius
    sprintf(buffer, "Radius: %d", r);
    outtextxy(250, 35, buffer);

    //Centre Point
    putpixel(x, y, 10);
    sprintf(buffer, "Centre: (%d,%d)", x, y);
    outtextxy(x - 45, y + 15, buffer);

    // Starting Points
    int X = 0;
    int Y = r;

    // Printing the initial point on the axes after translation
    plotPoints(x, y, X, Y);

    // Initialising the value of P (Decision Parameter)
    int P = 1 - r;
    while (Y > X)
    {

        // Mid-point is inside or on the perimeter
        if (P < 0)
        {
            P += 2 * X + 3;
        }
        else
        {
            // Mid-point is outside the perimeter
            P += 2 * X - 2 * Y + 5;
            Y--;
        }

        plotPoints(x, y, X, Y);
        X++;
    }
}

int main()
{
    int gDrive = DETECT;
    int gMode;
    initgraph(&gDrive, &gMode, NULL);

    // Coordinates
    int x;
    int y;
    int r;

    // Take center coordinates and radius as input from user
    cout << "Enter coordinates of Center:\n";
    cout << "x: ";
    cin >> x;
    cout << "y: ";
    cin >> y;

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
        // Draw Circle using Mid Point Circle Drawing Algorithm
        DrawCircle(x, y, r);
        getch();
    }
}
