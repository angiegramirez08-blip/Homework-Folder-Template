#include <iostream>
#include <stdexcept> //for exceptions

//exception class
class CustomException : public exception {
    public:
    const char* what() const noexcept {
        return "Error in nestedFuction";
    }
};

//division function
double divide(int numerator, int denominator) {
    if (denominator == 0) {
        throw runtime_error("Division by zero is not allowed.");
    }
    return (double)numerator / denominator;
}

//array access function
int accessArray(int arr[], int size, int index) {
    if (index < 0 || index >= size) {
        throw out_of_range("Index out of bounds.");
    }
    return arr[index];
}

//nested exception function
void nestedFunction() {
    throw CustomException();
}

//outer function
void outerFunction() {
try {
    nestedFunction(); 
}
catch (const CustomException& e) {
    cout << "Caught exception in outerFunction: " << e.what() << endl;
    throw; //rethrow exception
}
}

//main function
int main() {
    //nested exception demos
    try {
        outerFunction();
    }
    catch (const exception& e) {
        cout << "Caught rethrown exception in main: " << e.what() << endl;
    }

    cout << endl;

    //division demo
    int num, denom;

    cout << "Enter numerator: ";
    cin >> num;
    cout << "Enter denominator: ";
    cin >> denom;
    try {
        double result = divide(num, denom);
        cout << "Result: " << result << endl;
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
    cout << endl;

    //array access demo
    int size;
    cout << "Enter size of array: ";
    cin >> size;

    int arr[100]; 

    cout << "Enter " << size << " integers: " << endl;
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    int index;
    cout << "Enter index to access: ";
    cin >> index;

    try {
        int value = accessArray(arr, size, index);
        cout << "Value at index " << index << ": " << value << endl;
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
    return 0;
}