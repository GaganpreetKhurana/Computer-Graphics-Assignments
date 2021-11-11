/*
    Assumptions:
    1. Top Left is Origin(0,0)
    
    Command to run (Windows):
    g++ 2D_Transformations.cpp -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32 && a
*/

#include <graphics.h>
#include <iostream>
#include <math.h>
using namespace std;

pair<int, int> inputPoint()
{
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
    const float PI = acos(-1);
    cout << PI << endl;

    // for printing text at desired screen location.
    char buffer[30];

    // Title
    sprintf(buffer, " 2D Transformations ");
    outtextxy(200, 5, buffer);

    cout << "Options:\n";
    cout << "1. Translate a point P to P'\n";
    cout << "2. Translate a polygon\n";
    cout << "3. Rotate a point P by an angle Alpha.\n";
    cout << "4. Rotate a polygon by an angle Alpha.\n";
    cout << "Enter Choice: ";

    int choice = 0;
    cin >> choice;
    switch (choice)
    {
        case 1:
        {
            cout << "Enter Point P:\n";
            pair<int, int> P = inputPoint();

            cout << "Enter Translation Factor T:\n";
            pair<int, int> translationFactor = inputPoint();

            pair<int, int> newPoint = make_pair(P.first + translationFactor.first, P.second + translationFactor.second);
            cout << "New Point After Translation: (" << newPoint.first << "," << newPoint.second << ")\n";

            // Point P
            putpixel(P.first, P.second, 4);
            sprintf(buffer, "P: (%d,%d)", P.first, P.second);
            outtextxy(P.first - 30, P.second - 20, buffer);

            // Point newPoint
            putpixel(newPoint.first, newPoint.second, 14);
            sprintf(buffer, "New Point: (%d,%d)", newPoint.first, newPoint.second);
            outtextxy(newPoint.first + 30, newPoint.second + 20, buffer);

            break;
        }
        case 2:
        {
            cout << "Enter Translation Factor T:\n";
            pair<int, int> translationFactor = inputPoint();

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

            // Set boundary colour to RED
            int boundary_colour = 4;
            setcolor(boundary_colour);

            // Draw Polygon
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

            // Draw Polygon
            drawpoly(numberOfSides + 1, coordinates);

            // New coordinates
            cout << "New Vertices (In Cyclic order):    x   y\n";
            for (int i = 0; i < numberOfSides; i++)
            {
                cout << "Vertice " << i + 1 << ": (" << coordinates[2 * i] << "," << coordinates[2 * i + 1] << ")\n";
            }

            break;
        }
        case 3:
        {
            cout << "Enter Point P:\n";
            pair<int, int> P = inputPoint();

            cout << "Enter Rotation Angle alpha (in degrees): ";
            float alpha;
            cin >> alpha;

            float angleInRadians = alpha * (PI / 180);

            pair<int, int> pivot = make_pair(0, 0);
            char rotationAboutOrigin = 'Y';
            cout << "Do you wish to rotate about origin?(Y/N) ";
            cin >> rotationAboutOrigin;
            if (rotationAboutOrigin == 'N')
            {
                cout << "Enter the point about which you wish to rotate:\n";
                pivot = inputPoint();
            }
            pair<float, float> shift = make_pair(P.first - pivot.first, P.second - pivot.second);

            pair<float, float> newPoint;
            newPoint.first = pivot.first + shift.first * cos(angleInRadians) - shift.second * sin(angleInRadians);
            newPoint.second = pivot.second + shift.first * sin(angleInRadians) + shift.second * cos(angleInRadians);
            cout << "New Point After Rotation: (" << newPoint.first << "," << newPoint.second << ")\n";

            // Point P
            putpixel(P.first, P.second, 4);
            sprintf(buffer, "P: (%d,%d)", P.first, P.second);
            outtextxy(P.first - 30, P.second - 20, buffer);

            // Point Pivot
            putpixel(pivot.first, pivot.second, 6);
            sprintf(buffer, "Pivot: (%d,%d)", pivot.first, pivot.second);
            outtextxy(pivot.first - 30, pivot.second - 20, buffer);

            // Point newPoint
            putpixel(newPoint.first, newPoint.second, 14);
            sprintf(buffer, "New Point: (%f,%f)", newPoint.first, newPoint.second);
            outtextxy(newPoint.first + 30, newPoint.second + 20, buffer);

            break;
        }
        case 4:
        {
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

            // Set boundary colour to RED
            int boundary_colour = 4;
            setcolor(boundary_colour);

            // Draw Polygon
            drawpoly(numberOfSides + 1, coordinates);

            cout << "Enter Rotation Angle alpha (in degrees): ";
            float alpha;
            cin >> alpha;

            float angleInRadians = alpha * (PI / 180);

            pair<int, int> pivot = make_pair(0, 0);
            char rotationAboutOrigin = 'Y';
            cout << "Do you wish to rotate about origin?(Y/N) ";
            cin >> rotationAboutOrigin;
            if (rotationAboutOrigin == 'N')
            {
                cout << "Enter the point about which you wish to rotate:\n";
                pivot = inputPoint();
            }
            //Translation
            pair<float, float> shift;
            for (int i = 0; i < numberOfSides; i++)
            {
                shift.first = coordinates[2 * i] - pivot.first;
                shift.second = coordinates[2 * i + 1] - pivot.second;
                coordinates[2 * i] = pivot.first + shift.first * cos(angleInRadians) - shift.second * sin(angleInRadians);
                coordinates[2 * i + 1] = pivot.second + shift.first * sin(angleInRadians) + shift.second * cos(angleInRadians);
            }
            coordinates[2 * numberOfSides] = coordinates[0];
            coordinates[2 * numberOfSides + 1] = coordinates[1];

            // Set boundary colour to YELLOW
            boundary_colour = 14;
            setcolor(boundary_colour);

            // Draw Polygon
            drawpoly(numberOfSides + 1, coordinates);

            // New coordinates
            cout << "New Vertices (In Cyclic order):    x   y\n";
            for (int i = 0; i < numberOfSides; i++)
            {
                cout << "Vertice " << i + 1 << ": (" << coordinates[2 * i] << "," << coordinates[2 * i + 1] << ")\n";
            }

            // Point Pivot
            putpixel(pivot.first, pivot.second, 10);
            sprintf(buffer, "Pivot: (%d,%d)", pivot.first, pivot.second);
            outtextxy(pivot.first - 30, pivot.second - 20, buffer);

            break;
        }
        default:
        {
            cout << "Invalid Choice!!\n";
            return 0;
            break;
        }
    }

    getch();
    closegraph();
}
