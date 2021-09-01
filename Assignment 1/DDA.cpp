#include <iostream>
#include "graphics.h
using namespace std;

// void DDA(int x1, int y1, int x2, int y2)
// {
//     int dx = abs(x1 - x2);
//     int dy = abs(y1 - y2);
//     float steps = max(dx, dy);
//     xINC = dx / steps;
//     yINC = dy / steps;
//     float X = x1;
//     float Y = y1;

//     for (int i = 0; i <= steps; i++)
//     {
//         cout << "Step " << i + 1 << ": " << X << " " << Y << endl;
//         putpixel(round(X), round(Y), WHITE);
//         X += xINC;
//         Y += yINC;
//     }
// }
int main()
{
    int x1, y1, x2, y2;
    cout << "Enter coordinates of point A:\n";
    cout << "x: ";
    cin >> x1;
    cout << "\ny: ";
    cin >> y1;
    cout << "\nEnter coordinates of point B:\n";
    cout << "x: ";
    cin >> x2;
    cout << "\ny: ";
    cin >> y2;
    cout << "\n";

    int gd = DETECT, gm;
    char driverPath[] = "C:\\Program Files (x86)\\mingw-w64\\i686-8.1.0-posix-dwarf-rt_v6-rev0\\mingw32\\lib\\gcc\\i686-w64-mingw32\\8.1.0\\libbgi.a";
    // Initialize graphics function
    cout << gd << endl;
    initgraph(&gd, &gm, driverPath);
       //DDA(x1, y1, x2, y2);
    return 0;
}