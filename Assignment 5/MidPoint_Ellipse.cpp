/*
    Assumptions:
    1. Top Left is Origin(0,0)
    
    Command to run (Windows):
    g++ MidPoint_Ellipse.cpp -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32 && a
*/

#include <graphics.h>
#include <iostream>
using namespace std;

void plotPoints(int x_center, int y_center, float X, float Y)
{
    // (x,y)
    cout << "(" << X + x_center << ", " << Y + y_center << ") | ";
    putpixel(X + x_center, Y + y_center, 2);
    delay(10);

    // (x,-y)
    cout << "(" << X + x_center << ", " << -Y + y_center << ") | ";
    putpixel(X + x_center, -Y + y_center, 5);
    delay(10);

    // (-x,-y)
    cout << "(" << -X + x_center << ", " << -Y + y_center << ") | ";
    putpixel(-X + x_center, -Y + y_center, 6);
    delay(10);

    // (-x,y)
    cout << "(" << -X + x_center << ", " << Y + y_center << ")\n";
    putpixel(-X + x_center, Y + y_center, 9);
    delay(10);
}
void DrawEllipse(int x_center, int y_center, int r_X, int r_Y)
{
    cout << "Center: (" << x_center << "," << y_center << ")\n";
    cout << "X Radius: " << r_X << endl;
    cout << "Y Radius: " << r_Y << endl;
    cout << "Points: \n";
    cout << "(x,y)  |  (x,-y)  |   (-x,-y)   |  (-x,y)\n";

    // for printing text at desired screen location.
    char buffer[30];

    // Title
    sprintf(buffer, " MidPoint Ellipse Drawing Algorithm ");
    outtextxy(200, 5, buffer);

    //Radius
    sprintf(buffer, "X Radius: %d", r_X);
    outtextxy(250, 35, buffer);
    sprintf(buffer, "Y Radius: %d", r_Y);
    outtextxy(250, 50, buffer);

    //Centre Point
    putpixel(x_center, y_center, 10);
    sprintf(buffer, "Centre: (%d,%d)", x_center, y_center);
    outtextxy(x_center - 45, y_center + 15, buffer);

    // Starting Points
    float X = 0;
    float Y = r_Y;

    // Printing the initial point on the axes after translation
    plotPoints(x_center, y_center, X, Y);

    //  Region 1

    // Initialising the value of decisionParameter_1
    int decisionParameter_1 = (r_Y * r_Y) - (r_X * r_X * r_Y) + (0.25 * r_X * r_X);

    float dx = 2 * r_Y * r_Y * X;
    float dy = 2 * r_X * r_X * Y;

    while (dx < dy)
    {
        X++;

        // Check the decision parameter and update values accordingly
        if (decisionParameter_1 <= 0)
        {
            dx += (2 * r_Y * r_Y);
            decisionParameter_1 += dx + (r_Y * r_Y);
        }
        else
        {
            Y--;
            dx += (2 * r_Y * r_Y);
            dy -= (2 * r_X * r_X);
            decisionParameter_1 += dx - dy + (r_Y * r_Y);
        }

        //Plot he points in all 4 quarters
        plotPoints(x_center, y_center, X, Y);
    }

    //Region 2

    // Initialising the value of decisionParameter_2
    int decisionParameter_2 = ((r_Y * r_Y) * (X + 0.5) * (X + 0.5)) + ((r_X * r_X) * (Y - 1) * (Y - 1)) - (r_X * r_X * r_Y * r_Y);

    while (Y >= 0)
    {
        Y--;

        // Check the decision parameter and update values accordingly
        if (decisionParameter_2 > 0)
        {
            dy -= (2 * r_X * r_X);
            decisionParameter_2 += (r_X * r_X) - dy;
        }
        else
        {
            X++;
            dx += (2 * r_Y * r_Y);
            dy -= (2 * r_X * r_X);
            decisionParameter_2 += dx - dy + (r_X * r_X);
        }

        //Plot he points in all 4 quarters
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
    int r_X;
    int r_Y;

    // Take center coordinates and radius as input from user
    cout << "Enter coordinates of Center:\n";
    cout << "x: ";
    cin >> x_center;
    cout << "y: ";
    cin >> y_center;

    cout << "Enter X Radius: ";
    cin >> r_X;
    cout << "Enter Y Radius: ";
    cin >> r_Y;
    cout << "\n\n";

    if (r_X < 0 || r_Y < 0)
    {
        cout << "Radius cannot be negative!\n";
        return 0;
    }
    else
    {
        // Draw Ellipse using MidPoint Ellipse Drawing Algorithm
        initgraph(&gDrive, &gMode, NULL);
        DrawEllipse(x_center, y_center, r_X, r_Y);
        getch();
    }
}
