/*
    Assumptions:
    1. Top Left is Origin(0,0)
    2. All inputs are +ve
    
    Command to run (Windows):
    g++ MidPoint_Circle.cpp -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32 && a
*/

#include <graphics.h>
#include <iostream>
#include <math.h>
using namespace std;

void DrawCircle(int x, int y, int r)
{
    cout << "Center: (" << x << "," << y<< ")\n";
    cout << "Radius: " << r <<endl;

    // Starting Points
    int X = r;
    int Y = 0;

    // Printing the initial point on the axes
    // after translation
    cout << "(" << X + x << ", " << Y + y << ") ";
    // delay(50);
    putpixel(X + x , Y + y, 7);
     
    // When radius is zero only a single
    // point will be printed
    if (r > 0)
    {
        cout << "(" << X + x << ", " << -Y + y << ") ";
        putpixel(X + x , -Y + y, 7);
        cout << "(" << Y + x << ", " << X + y << ") ";
        putpixel(Y + x , X + y, 7);
        cout << "(" << -Y + x << ", " << X + y << ")\n";
        putpixel(-Y + x , X + y, 7);
    }
     
    // Initialising the value of P
    int P = 1 - r;
    while (X > Y)
    {
        Y++;
         
        // Mid-point is inside or on the perimeter
        if (P <= 0)
            P = P + 2*Y + 1;
        // Mid-point is outside the perimeter
        else
        {
            X--;
            P = P + 2*Y - 2*X + 1;
        }
         
        // All the perimeter points have already been printed
        if (X < Y)
            break;
         
        // Printing the generated point and its reflection
        // in the other octants after translation
        cout << "(" << X + x << ", " << Y + y << ") ";
        putpixel(X + x , Y + y, 7);
        cout << "(" << -X + x << ", " << Y + y << ") ";
        putpixel(-X + x , Y + y, 7);
        cout << "(" << X + x << ", " << -Y + y << ") ";
        putpixel(X + x , -Y + y, 7);
        cout << "(" << -X + x << ", " << -Y + y << ")\n";
        putpixel(-X + x , -Y + y, 7);
         
        // If the generated point is on the line x = y then
        // the perimeter points have already been printed
        if (X != Y)
        {
            cout << "(" << Y + x << ", " << X + y << ") ";
            putpixel(Y + x , X + y, 7);
            cout << "(" << -Y + x << ", " << X + y << ") ";
            putpixel(-Y + x , X + y, 7);
            cout << "(" << Y + x << ", " << -X + y << ") ";
            putpixel(Y + x , -X + y, 7);
            cout << "(" << -Y + x << ", " << -X + y << ")\n";
            putpixel(-Y + x , -X + y, 7);
        }
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

    // Take coordinates as input from user
    cout << "Enter coordinates of Center:\n";
    cout << "x: ";
    cin >> x;
    cout << "y: ";
    cin >> y;
    cout << "Enter Radius: ";
    cin >> r;
    cout << "\n";

    // Draw Circle using Mid Point Circle Drawing Algorithm
    DrawCircle(x,y,r);
    getch();
    closegraph();
}
