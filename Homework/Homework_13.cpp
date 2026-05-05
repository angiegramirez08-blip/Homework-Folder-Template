#include <iostream>
#include <map>
using namespace std;

int main() {
    //two maps
    map<int, int> numbers1;
    map<int, int> numbers2;

    //fill numbers1
    for (int i = 1; i <= 9; i++) {
        numbers1[i] = i;
    }

    //numbers2
    for (int i = 1; i <= 9; i++) {
        numbers2[i] = i * 10;
    }

    //interlace maps
    map<int, int> result;
    map <int, int>::iterator it1 = numbers1.begin();
    map <int, int>::iterator it2 = numbers2.begin();

    while (it1 != numbers1.end() || it2 != numbers2.end()) {
        if (it1 != numbers1.end()) {
            result[it1->first] = it1->second;
            it1++;
        }
        if (it2 != numbers2.end()) {
            result[it2->second] = it2->first;
            it2++;
        }
    }
    numbers1 = result;

    //prints the interlaced map
    cout << "Interlaced map numbers1: ";
    for (const auto& pair : numbers1) {
        cout << pair.first << ": " << pair.second << " ";
    }
    cout << endl;
    return 0;
}