#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

// Global variables for map boundaries
int leftside;
int rightside;
int topside;
int bottomside;
bool inside;

// Creating map function
void createmap()
{
    int widthHalf;
    int heightHalf;

    widthHalf = rand() % 10 + 1; // numbers 1-10
    heightHalf = rand() % 10 + 1; // numbers 1-10

    leftside = -widthHalf;
    rightside = widthHalf;
    topside = heightHalf;
    bottomside = -heightHalf;

    cout << "\n The random map has been created with the following dimensions:\n";
    cout << "Map corners are:\n";
    cout << "A(" << leftside << ", " << topside << ")\n";
    cout << "B(" << rightside << ", " << topside << ")\n";
    cout << "C(" << rightside << ", " << bottomside << ")\n";
    cout << "D(" << leftside << ", " << bottomside << ")\n";
}
    // check if point is in the map
    bool checklocation(int userx, int usery)
    {
        if (userx >= leftside && userx <= rightside)
        {
            if (usery >= bottomside && usery <= topside)
            {
                inside = true; // point is inside the map
                //return true;
            }
        }
        else
        {
            inside = false; // point is outside the map
            //return false;
        }
        return inside;
    }

    int main()
    {
        srand(time(0)); 

        string name;
        int x;
        int y;

        cout << "Enter your name: ";
        getline(cin, name);

        cout << "Enter the x coordinate: ";
        cin >> x;
        cout << "Enter the y coordinate: ";
        cin >> y;

        createmap();

        bool result;
        result = checklocation(x, y);

        if (result == true)
        {
            cout << name << ", your point (" << x << ", " << y << ") is inside the map.\n";
        }
        else
        {
            cout << name << ", your point (" << x << ", " << y << ") is outside the map.\n";
        }
        return 0;
    }