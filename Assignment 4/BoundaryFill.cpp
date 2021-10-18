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
void boundary_fill_colour(int x, int y, int boundary_colour, int fill_colour)
{
    cout<<x<<" "<<y<<endl;
    if (getpixel(x, y) != boundary_colour && getpixel(x, y) != fill_colour)
    {
        putpixel(x, y, fill_colour);
        boundary_fill_colour(x + 1, y, fill_colour, boundary_colour);
        boundary_fill_colour(x, y + 1, fill_colour, boundary_colour);
        boundary_fill_colour(x - 1, y, fill_colour, boundary_colour);
        boundary_fill_colour(x, y - 1, fill_colour, boundary_colour);
        boundary_fill_colour(x - 1, y - 1, fill_colour, boundary_colour);
        boundary_fill_colour(x - 1, y + 1, fill_colour, boundary_colour);
        boundary_fill_colour(x + 1, y - 1, fill_colour, boundary_colour);
        boundary_fill_colour(x + 1, y + 1, fill_colour, boundary_colour);
    }
}
int main()
{
    int gDrive = DETECT;
    int gMode;

    // Take number of sides as Input
    int numberOfSides;
    cout << "Enter Number of Sides: ";
    numberOfSides=3;
    // cin >> numberOfSides;
    int coordinates[2 * (numberOfSides + 1)]={40,60,134,100,350,465};

    // // Take coordinates as input from user
    // cout << "Enter Vertices (In Cyclic order):    x   y\n";
    // for (int i = 0; i < numberOfSides; i++)
    // {
    //     cout << "Vertice " << i + 1 << ": ";
    //     cin >> coordinates[2 * i] >> coordinates[2 * i + 1];
    // }
    coordinates[2 * numberOfSides] = coordinates[0];
    coordinates[2 * numberOfSides + 1] = coordinates[1];

    // SET seed and fill color
    int x_seed, y_seed, fill_colour;
    fill_colour = 14; // YELLOW
    x_seed = 170;
    y_seed = 200;

    initgraph(&gDrive, &gMode, NULL);

    // Set colour to RED
    int boundary_colour = 4;
    setcolor(boundary_colour);

    // Draw Polygon
    drawpoly(numberOfSides + 1, coordinates);

    //Fill Colour using Boundary Fill
    boundary_fill_colour(x_seed, y_seed, boundary_colour, fill_colour);
    getch();
    closegraph();
}
