#include <graphics.h>
#include <iostream>
using namespace std;

//DDA algorithm
void Breesham(int x1, int y_1, int x2, int y2)
{
    // Difference
    int dx = x2 - x1;
    int dy = y2 - y_1;

    int X = x1;
    int Y = y_1;

    int p = 2 * dy - dx;

    cout << "Starting point: (" + to_string(x1) + "," + to_string(y_1) + ")\n";
    cout << "End Point: (" + to_string(x2) + "," + to_string(y2) + ")\n";
    cout << "Difference: (" + to_string(dx) + "," + to_string(dy) + ")\n";

    while (X < x2)
    {

        cout << X << " " << Y << " " << p << endl;
        if (p >= 0)
        {
            putpixel(X, Y, 7);
            Y = Y + 1;
            p = p + 2 * dy - 2 * dx;
        }
        else
        {
            putpixel(X, Y, 7);
            p = p + 2 * dy;
        }
        X = X + 1;
    }
}

int main()
{
    int gDrive = DETECT;
    int gMode;
    initgraph(&gDrive, &gMode, NULL);

    // Coordinates
    int x1 = 0;
    int y_1 = 0;
    int x2 = 100;
    int y2 = 100;

    // Take coordinates as input from user
    cout << "Enter coordinates of point A:\n";
    // cout<<"x: ";
    // cin>>x1;
    // cout<<"y: ";
    // cin>>y_1;
    // cout << "Enter coordinates of point B:\n";
    // cout << "x: ";
    // cin >> x2;
    // cout << "y: ";
    // cin >> y2;
    // cout << "\n";

    Breesham(x1, y_1, x2, y2);
    getch();
    // closegraph();
}

// g++ - o example hut.cpp - lbgi - lgdi32 - lcomdlg32 - luuid - loleaut32 - lole32