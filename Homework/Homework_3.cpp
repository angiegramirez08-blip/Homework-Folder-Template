#include <iostream>
#include <cmath>

using namespace std;

int main() {
    // declarations
    int choice;
    double radius, height, length, width, side;
    double area;
    const double PI = 3.14159;

    // menu
    cout << "Choose a shape to calculate the area:" << endl;
    cout << "1. Circle" << endl;
    cout << "2. Square" << endl;
    cout << "3. Rectangle" << endl;
    cout << "4. Cylinder (surface area)" << endl;
    cout << "Enter your choice (1-4): ";
    cin >> choice;

    if (choice == 1) {
        cout << "Enter the radius of the circle: ";
        cin >> radius;
        area = PI * radius * radius;
        cout << "The area of the circle is: " << area << endl;
    }
    else if (choice == 2) {
        cout << "Enter the side length of the square: ";
        cin >> side;
        area = side * side;
        cout << "The area of the square is: " << area << endl;
    }
    else if (choice == 3) {
        cout << "Enter the length and width of the rectangle: ";
        cin >> length >> width;
        area = length * width;
        cout << "The area of the rectangle is: " << area << endl;
    }
    else if (choice == 4) {
        cout << "Enter the radius and height of the cylinder: ";
        cin >> radius >> height;
        area = 2 * PI * radius * (radius + height);
        cout << "The surface area of the cylinder is: " << area << endl;
    }
    else {
        cout << "Invalid choice!" << endl;
    }
}