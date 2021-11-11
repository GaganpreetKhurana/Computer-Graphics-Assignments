/*
    Assumptions:
    1. Top Left is Origin(0,0)
    
    Command to run (Windows):
    g++ 2D_Transformations.cpp -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32 && a

    Initial object is in RED colour
    Final object is in YELLOW colour
    Pivot point is in WHITE colour
*/

#include <graphics.h>
#include <iostream>
#include <math.h>
using namespace std;

pair<int, int> inputPoint()
{
    // To input a point coordinates and return a pair

    int x, y;

    cout << "X: ";
    cin >> x;

    cout << "Y: ";
    cin >> y;

    return make_pair(x, y);
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
    sprintf(buffer, " 2D Transformations ");
    outtextxy(200, 5, buffer);

    // List of operations
    cout << "Operations:\n";
    cout << "1. Translate a point P to P'\n";
    cout << "2. Translate a polygon\n";
    cout << "3. Rotate a point P by an angle Alpha.\n";
    cout << "4. Rotate a polygon by an angle Alpha.\n";

    // Input User choice as Integer
    cout << "Enter Choice: ";
    int choice = 0;
    cin >> choice;

    // Switch case for operations
    switch (choice)
    {
    case 1:
    {
        // Option 1: Translate Point

        // Input point to be translated
        cout << "Enter Point P:\n";
        pair<int, int> P = inputPoint();

        // Input translation factor (tx,ty)
        cout << "Enter Translation Factor T:\n";
        pair<int, int> translationFactor = inputPoint();

        // New Point after translation
        pair<int, int> newPoint = make_pair(P.first + translationFactor.first, P.second + translationFactor.second);
        cout << "New Point After Translation: (" << newPoint.first << "," << newPoint.second << ")\n";

        // Draw points on screen

        // Point P - RED
        putpixel(P.first, P.second, 4);
        sprintf(buffer, "P: (%d,%d)", P.first, P.second);
        outtextxy(P.first - 30, P.second - 20, buffer);

        // Point newPoint - YELLOW
        putpixel(newPoint.first, newPoint.second, 14);
        sprintf(buffer, "New Point: (%d,%d)", newPoint.first, newPoint.second);
        outtextxy(newPoint.first + 30, newPoint.second + 20, buffer);

        break;
    }
    case 2:
    {
        // Option 2 - Translate Polygon

        // Input translation factor - (tx,ty)
        cout << "Enter Translation Factor T:\n";
        pair<int, int> translationFactor = inputPoint();

        // Polygon
        // Take number of sides as Input
        int numberOfSides;
        cout << "Enter Number of Sides: ";
        cin >> numberOfSides;

        int coordinates[2 * (numberOfSides + 1)]; // to store coordinates

        // Take coordinates as input from user
        cout << "Enter Vertices (In Cyclic order):    x   y\n";
        for (int i = 0; i < numberOfSides; i++)
        {
            cout << "Vertice " << i + 1 << ": ";
            cin >> coordinates[2 * i] >> coordinates[2 * i + 1];
        }
        // To draw coordinates using drawpoly() first and last vertice in array should be same
        coordinates[2 * numberOfSides] = coordinates[0];
        coordinates[2 * numberOfSides + 1] = coordinates[1];

        // Set boundary colour to RED
        int boundary_colour = 4;
        setcolor(boundary_colour);

        // Draw Initial Polygon
        drawpoly(numberOfSides + 1, coordinates);

        //Translation
        for (int i = 0; i < numberOfSides; i++)
        {
            coordinates[2 * i] += translationFactor.first;
            coordinates[2 * i + 1] += translationFactor.second;
        }
        coordinates[2 * numberOfSides] = coordinates[0];
        coordinates[2 * numberOfSides + 1] = coordinates[1];

        // Set boundary colour to YELLOW
        boundary_colour = 14;
        setcolor(boundary_colour);

        // Draw Translated Polygon
        drawpoly(numberOfSides + 1, coordinates);

        // Print New Vertice coordinates
        cout << "New Vertices (In Cyclic order):    x   y\n";
        for (int i = 0; i < numberOfSides; i++)
        {
            cout << "Vertice " << i + 1 << ": (" << coordinates[2 * i] << "," << coordinates[2 * i + 1] << ")\n";
        }

        break;
    }
    case 3:
    {
        // Option 3. Point Rotation by alpha (degrees)

        // Input point to be rotated
        cout << "Enter Point P:\n";
        pair<int, int> P = inputPoint();

        // Input rotation angle in degrees
        cout << "Enter rotation angle alpha (in degrees): ";
        float alpha;
        cin >> alpha;

        // convert alpha from degree to radians
        float angleInRadians = alpha * (PI / 180);

        // Pivot
        pair<int, int> pivot = make_pair(0, 0);

        // Ask if user wishes to rotate about origin
        char rotationAboutOrigin = 'Y';
        cout << "Do you wish to rotate about origin?(Y/N) ";
        cin >> rotationAboutOrigin;
        if (rotationAboutOrigin == 'N')
        {
            // Input new pivot point if user wants to
            cout << "Enter the point about which you wish to rotate:\n";
            pivot = inputPoint();
        }
        else if (rotationAboutOrigin != 'Y')
        {
            // To handle invalid input
            cout << "Invalid Input!!\n";
            return 0;
        }

        // Calculate difference between point and pivot coordinates
        pair<float, float> shift = make_pair(P.first - pivot.first, P.second - pivot.second);

        // Calculate new point
        pair<float, float> newPoint;
        newPoint.first = pivot.first + shift.first * cos(angleInRadians) - shift.second * sin(angleInRadians);
        newPoint.second = pivot.second + shift.first * sin(angleInRadians) + shift.second * cos(angleInRadians);
        cout << "New Point After Rotation: (" << newPoint.first << "," << newPoint.second << ")\n";

        // Point P - RED
        putpixel(P.first, P.second, 4);
        sprintf(buffer, "P: (%d,%d)", P.first, P.second);
        outtextxy(P.first - 30, P.second - 20, buffer);

        // Point Pivot - WHITE
        putpixel(pivot.first, pivot.second, 15);
        sprintf(buffer, "Pivot: (%d,%d)", pivot.first, pivot.second);
        outtextxy(pivot.first - 30, pivot.second - 20, buffer);

        // Point newPoint - YELLOW
        putpixel(newPoint.first, newPoint.second, 14);
        sprintf(buffer, "New Point: (%f,%f)", newPoint.first, newPoint.second);
        outtextxy(newPoint.first + 30, newPoint.second + 20, buffer);

        break;
    }
    case 4:
    {
        // Option 4 - Rotate Polygon

        //Polygon
        // Take number of sides as Input
        int numberOfSides;
        cout << "Enter Number of Sides: ";
        cin >> numberOfSides;

        int coordinates[2 * (numberOfSides + 1)]; // To store vertices of polygon

        // Take coordinates as input from user
        cout << "Enter Vertices (In Cyclic order):    x   y\n";
        for (int i = 0; i < numberOfSides; i++)
        {
            cout << "Vertice " << i + 1 << ": ";
            cin >> coordinates[2 * i] >> coordinates[2 * i + 1];
        }
        coordinates[2 * numberOfSides] = coordinates[0];
        coordinates[2 * numberOfSides + 1] = coordinates[1];

        // Set boundary colour to RED
        int boundary_colour = 4;
        setcolor(boundary_colour);

        // Draw Initial Polygon
        drawpoly(numberOfSides + 1, coordinates);

        // Input rotation angle alpha in degrees
        cout << "Enter rotation angle alpha (in degrees): ";
        float alpha;
        cin >> alpha;

        // Convert alpha to radians
        float angleInRadians = alpha * (PI / 180);

        // Pivot
        pair<int, int> pivot = make_pair(0, 0);

        // Ask if user wishes to rotate about origin
        char rotationAboutOrigin = 'Y';
        cout << "Do you wish to rotate about origin?(Y/N) ";
        cin >> rotationAboutOrigin;
        if (rotationAboutOrigin == 'N')
        {
            // Take new pivot as input if user wants to
            cout << "Enter the point about which you wish to rotate:\n";
            pivot = inputPoint();
        }
        else if (rotationAboutOrigin != 'Y')
        {
            // To handle invalid input
            cout << "Invalid Input!!\n";
            return 0;
        }

        // Rotation
        pair<float, float> shift; // To store difference between vertice and pivot

        // Traverse through vertices
        for (int i = 0; i < numberOfSides; i++)
        {
            // Calculate difference
            shift.first = coordinates[2 * i] - pivot.first;
            shift.second = coordinates[2 * i + 1] - pivot.second;

            // Calculate new vertice
            coordinates[2 * i] = pivot.first + shift.first * cos(angleInRadians) - shift.second * sin(angleInRadians);
            coordinates[2 * i + 1] = pivot.second + shift.first * sin(angleInRadians) + shift.second * cos(angleInRadians);
        }
        coordinates[2 * numberOfSides] = coordinates[0];
        coordinates[2 * numberOfSides + 1] = coordinates[1];

        // Set boundary colour to YELLOW
        boundary_colour = 14;
        setcolor(boundary_colour);

        // Draw Rotated Polygon
        drawpoly(numberOfSides + 1, coordinates);

        // New vertice coordinates after rotation
        cout << "New Vertices (In Cyclic order):    x   y\n";
        for (int i = 0; i < numberOfSides; i++)
        {
            cout << "Vertice " << i + 1 << ": (" << coordinates[2 * i] << "," << coordinates[2 * i + 1] << ")\n";
        }

        // Point Pivot - WHITE
        putpixel(pivot.first, pivot.second, 15);
        sprintf(buffer, "Pivot: (%d,%d)", pivot.first, pivot.second);
        outtextxy(pivot.first - 30, pivot.second - 20, buffer);

        break;
    }
    default:
    {
        cout << "Invalid Choice!!\n";
        return 0;
    }
    }

    getch();
    closegraph();
}
