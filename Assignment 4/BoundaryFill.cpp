/*
    Assumptions:
    1. Top Left is Origin(0,0)
    2. All inputs are +ve
    
    Command to run (Windows):
    g++ BoundaryFill.cpp -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32 && a
*/

#include <graphics.h>
#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int gDrive = DETECT;
    int gMode;

    // Take number of sides as Input
    int numberOfSides;
    cout << "Enter Number of Sides: ";
    cin >> numberOfSides;
    int coordinates[2 * (numberOfSides + 1)];

    // Take coordinates as input from user
    cout << "Enter Vertices (In Cyclic order):    x   y\n";
    for (int i = 0; i < numberOfSides; i++)
    {
        cout << "Vertice " << i + 1 << ": ";
        cin >> coordinates[2 * i] >> coordinates[2 * i + 1];
    }
    coordinates[2 * numberOfSides] = coordinates[0];
    coordinates[2 * numberOfSides + 1] = coordinates[1];

    initgraph(&gDrive, &gMode, NULL);

    // Draw Polygon
    drawpoly(numberOfSides + 1, coordinates);
    getch();
    closegraph();
}
