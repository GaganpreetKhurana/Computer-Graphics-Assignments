/*
    Assumptions:
    1. Top Left is Origin(0,0)
    
    Command to run (Windows):
    g++ CeilingFan.cpp -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32 && a
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

    // for printing text at desired screen location.
    char buffer[30];

    // Title
    sprintf(buffer, " Ceiling Fan ");
    outtextxy(200, 5, buffer);


    // Set boundary colour to RED
    int boundary_colour = 4;
    setcolor(boundary_colour);

    int coordinates[6]= {250,250,13,186,186,13};
    
    pair<int, int> pivot = make_pair(150, 150);
    circle(pivot.first,pivot.second,35);
    line(pivot.first,pivot.second,coordinates[0],coordinates[1]);
    line(pivot.first,pivot.second,coordinates[2],coordinates[3]);
    line(pivot.first,pivot.second,coordinates[4],coordinates[5]);

    float angleInRadians;
    pair<float, float> shift;
    pair<float, float> newPoint;
    for(int alpha=1;alpha<120;alpha++)
    {
            angleInRadians = alpha * (PI / 180);
            //Translation
            
            for (int i = 0; i < 3; i++)
            {
                // // Set boundary colour to YELLOW
                // boundary_colour = 0;
                // setcolor(boundary_colour);
                // line(pivot.first,pivot.second,coordinates[2*i],coordinates[2*i+1]);
                shift.first = coordinates[2 * i] - pivot.first;
                shift.second = coordinates[2 * i + 1] - pivot.second;
                
                newPoint.first = pivot.first + shift.first * cos(angleInRadians) - shift.second * sin(angleInRadians);
                newPoint.second = pivot.second + shift.first * sin(angleInRadians) + shift.second * cos(angleInRadians);
                // Set boundary colour to YELLOW
                boundary_colour = 14;
                setcolor(boundary_colour);
                line(pivot.first,pivot.second,newPoint.first,newPoint.second);
                delay(30);
            }
            // Set boundary colour to RED
            int boundary_colour = 4;
            setcolor(boundary_colour);
            circle(pivot.first,pivot.second,35);
    }
    getch();
    closegraph();
}
