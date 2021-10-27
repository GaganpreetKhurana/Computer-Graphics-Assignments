/*
    Assumptions:
    1. Top Left is Origin(0,0)
    2. All inputs are +ve
    
    Command to run (Windows):
    g++ FloodFill.cpp -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32 && a
*/

#include <graphics.h>
#include <iostream>
using namespace std;

const int BACKGROUND_COLOUR = 0; // Black
void flood_fill_colour(int x, int y, int fill_colour)
{
    // Check if current pixel colour is not equal to boundary/colour to be filled
    if (getpixel(x, y) == BACKGROUND_COLOUR && getpixel(x, y) != fill_colour)
    {
        // Fill colour
        putpixel(x, y, fill_colour);

        // Traverse 4 adjacent pixels
        flood_fill_colour(x + 1, y, fill_colour);
        flood_fill_colour(x, y + 1, fill_colour);
        flood_fill_colour(x - 1, y, fill_colour);
        flood_fill_colour(x, y - 1, fill_colour);
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

    // Take coordinates as input from user
    cout << "Enter Vertices (In Cyclic order):    x   y\n";
    for (int i = 0; i < numberOfSides; i++)
    {
        cout << "Vertice " << i + 1 << ": ";
        cin >> coordinates[2 * i] >> coordinates[2 * i + 1];
    }
    coordinates[2 * numberOfSides] = coordinates[0];
    coordinates[2 * numberOfSides + 1] = coordinates[1];

    // Take seed as input and set fill color

    int x_seed, y_seed, fill_colour;
    fill_colour = 14; // YELLOW
    cout << "Enter seed coordinates:\nx: ";
    cin >> x_seed;
    cout << "y: ";
    cin >> y_seed;

    initgraph(&gDrive, &gMode, NULL);

    // Set boundary colour to RED
    int boundary_colour = 4;
    setcolor(boundary_colour);

    // Draw Polygon
    drawpoly(numberOfSides + 1, coordinates);

    //Fill Colour using Boundary Fill
    flood_fill_colour(x_seed, y_seed, fill_colour);
    getch();
    closegraph();

    cout << "Complete\n";
}
