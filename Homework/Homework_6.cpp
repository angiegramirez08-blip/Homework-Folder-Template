
//Homework 6: This code swaps data from one array to another using 2 arrays

#include <iostream>
using namespace std;

//Function for Part 2
//Finds and prints values in 2 arrays

void findCommon(int arr1[], int arr2[], int size)
{
    cout << "Common values: ";
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (arr1[i] == arr2[j])
            {
                cout << arr1[i] << " ";
                break; //stops when a common value is found to avoid duplicates

            }
        }
    }
    cout << endl;
}

int main()
{
    int data[5] = {1, 3, 6, 7, 9};
    int data1[5] = {5, 3, 3, 11, 9};
    int size = 5;

    //Begins Part 1: swaps the contents of the two arrays----------

    for (int i = 0; i < size; i++)
    {
        int temp = data[i];
        data[i] = data1[i];
        data1[i] = temp;
    }

    cout << "After swapping: " << endl;

    cout << "data: ";
    for (int i = 0; i < size; i++)
    {
        cout << data[i] << " ";
    }
    cout << endl;

    cout << "data1: ";
    for (int i = 0; i < size; i++)
    {
        cout << data1[i] << " ";
    }
    
    cout << endl;

    //Part 1 Ends-------------------------------------------------

    //Begins Part 2: finds and prints common values in the two arrays----------------------

    findCommon(data, data1, size);

    //Part 2 Ends--------------------------------------------------------------------------

    return 0;
}