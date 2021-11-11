/*
    Assumptions:
    1. Top Left is Origin(0,0)
    
    Command to run (Windows):
    g++ CeilingFan.cpp -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32 && a

    Initial objects are RED in colour
    Transformed objects are YELLOW in colour
*/

#include <graphics.h>
#include <iostream>
#include <math.h>
using namespace std;

void printPointPair(pair<float, float> point)
{
    // To print a pair
    cout << "(" << point.first << "," << point.second << ")     |   ";
}
int main()
{
    int gDrive = DETECT;
    int gMode;
    initgraph(&gDrive, &gMode, NULL);

    // Initialize a const equal to Pi
    const float PI = acos(-1);

    // for printing text at desired screen location.
    char buffer[30];

    // Title
    sprintf(buffer, " Ceiling Fan ");
    outtextxy(200, 5, buffer);

    // Set boundary colour to RED
    int boundary_colour = 4;
    setcolor(boundary_colour);

    // End Points of lines at 120 degrees to each other
    pair<float, float> coordinates[3] = {make_pair(250, 250), make_pair(13.3975, 186.603), make_pair(186.603, 13.3975)};
    cout << "Initial Line End Points: \n";
    for (int line = 0; line < 3; line++)
    {
        printPointPair(coordinates[line]);
    }
    cout << endl
         << endl;

    //coordinates of end points in previous interation - to remove the line
    pair<float, float> previousCoordinates[3] = {make_pair(-1, -1), make_pair(-1, -1), make_pair(-1, -1)};

    pair<int, int> pivot = make_pair(150, 150); // Center of Circle

    // Draw Circle and lines in RED colour
    circle(pivot.first, pivot.second, 35);
    line(pivot.first, pivot.second, coordinates[0].first, coordinates[0].second);
    line(pivot.first, pivot.second, coordinates[1].first, coordinates[1].second);
    line(pivot.first, pivot.second, coordinates[2].first, coordinates[2].second);

    float angleInRadians; // to store angle in radians

    pair<float, float> shift[3]; // difference between pivot and end point
    for (int line = 0; line < 3; line++)
    {
        shift[line].first = coordinates[line].first - pivot.first;
        shift[line].second = coordinates[line].second - pivot.second;
    }

    pair<float, float> newPoint; // To store new point after transformation

    //Rotations
    cout << "Rotated Line End Points: \n";
    for (int alpha = 1; alpha < 120; alpha++)
    {
        angleInRadians = alpha * (PI / 180);

        // Loop through lines
        for (int i = 0; i < 3; i++)
        {
            // Set boundary colour to BLACK - to remove previous line
            boundary_colour = 0;
            setcolor(boundary_colour);

            line(pivot.first, pivot.second, previousCoordinates[i].first, previousCoordinates[i].second);

            //Calculate new Point after rotation
            newPoint.first = pivot.first + shift[i].first * cos(angleInRadians) - shift[i].second * sin(angleInRadians);
            newPoint.second = pivot.second + shift[i].first * sin(angleInRadians) + shift[i].second * cos(angleInRadians);

            // Set boundary colour to YELLOW
            boundary_colour = 14;
            setcolor(boundary_colour);
            line(pivot.first, pivot.second, newPoint.first, newPoint.second);
            printPointPair(newPoint);

            // set previous coordinate
            previousCoordinates[i] = newPoint;
            delay(30);
        }
        cout << endl;
        //Draw circle again after every iteration as line can overlap circle
        // Set boundary colour to RED
        int boundary_colour = 4;
        setcolor(boundary_colour);
        circle(pivot.first, pivot.second, 35);
    }

    // Draw inital lines again
    line(pivot.first, pivot.second, coordinates[0].first, coordinates[0].second);
    line(pivot.first, pivot.second, coordinates[1].first, coordinates[1].second);
    line(pivot.first, pivot.second, coordinates[2].first, coordinates[2].second);

    putpixel(pivot.first, pivot.second, 15); // set pivot pixel - WHITE colour

    getch();
    closegraph();
}
