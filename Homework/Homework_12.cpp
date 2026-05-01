#include <iostream>
#include <vector>
using namespace std;

int main()
{
    //initialize vectors
    vector<int> numbers1 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> numbers2 = {10, 20, 30, 40, 50, 60, 70, 80, 90};

    //iterators
    vector<int>::iterator i = numbers1.begin();
    vector<int>::iterator j = numbers2.begin();

    //interlace num2 into num1
    while (i != numbers1.end() && j != numbers2.end())
    {
        i++; 
        i = numbers1.insert(i, *j); 
        i++;
        j++;
    }

    //if num2 is longer
    while (j != numbers2.end())
    {
        numbers1.insert(numbers1.end(), *j);
        j++;
    }

    //prints
    cout << "Interlaced vector (numbers1): ";

    for (int x = 0; x < numbers1.size(); x++)
    {
        cout << numbers1[x] << " ";
    }
    cout << endl;

    return 0;
}