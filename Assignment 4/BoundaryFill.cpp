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
void boundary_fill_colour(int x, int y, int fill_colour, int boundary_colour)
{
    if (getpixel(x, y) != boundary_colour && getpixel(x, y) != fill_colour)
    {
        putpixel(x, y, fill_colour);
        boundary_fill_colour(x + 1, y, fill_colour, boundary_colour);
        boundary_fill_colour(x, y + 1, fill_colour, boundary_colour);
        boundary_fill_colour(x - 1, y, fill_colour, boundary_colour);
        boundary_fill_colour(x, y - 1, fill_colour, boundary_colour);
        // boundary_fill_colour(x - 1, y - 1, fill_colour, boundary_colour);
        // boundary_fill_colour(x - 1, y + 1, fill_colour, boundary_colour);
        // boundary_fill_colour(x + 1, y - 1, fill_colour, boundary_colour);
        // boundary_fill_colour(x + 1, y + 1, fill_colour, boundary_colour);
    }
}
int main()
{
    int gDrive = DETECT;
    int gMode;

    // Take number of sides as Input
    int numberOfSides;
    cout << "Enter Number of Sides: ";
    cin >> numberOfSides;

    int coordinates[2 * (numberOfSides + 1)];

    // To take seed coordinate as average
    int sum_x = 0, sum_y = 0;

    // Take coordinates as input from user
    cout << "Enter Vertices (In Cyclic order):    x   y\n";
    for (int i = 0; i < numberOfSides; i++)
    {
        cout << "Vertice " << i + 1 << ": ";
        cin >> coordinates[2 * i] >> coordinates[2 * i + 1];
        sum_x += coordinates[2 * i];
        sum_y += coordinates[2 * i + 1];
    }
    coordinates[2 * numberOfSides] = coordinates[0];
    coordinates[2 * numberOfSides + 1] = coordinates[1];

    // SET seed and fill color
    int x_seed, y_seed, fill_colour;
    fill_colour = 14; // YELLOW
    x_seed = sum_x / numberOfSides;
    y_seed = sum_y / numberOfSides;

    initgraph(&gDrive, &gMode, NULL);

    // Set colour to RED
    int boundary_colour = 4;
    setcolor(boundary_colour);

    // Draw Polygon
    drawpoly(numberOfSides + 1, coordinates);
    putpixel(x_seed,y_seed,5);
    //Fill Colour using Boundary Fill
    delay(100);
    boundary_fill_colour(x_seed, y_seed, fill_colour, boundary_colour);
    // cout << "Done\n";
    getch();
    closegraph();
    
}
