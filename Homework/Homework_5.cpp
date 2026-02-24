#include <iostream>
using namespace std;

int main() {
    char message [100];
    int vowel_count = 0;

    cout << "Enter a sentence: ";
    cin.getline(message, 100);

    //loop to count the number of vowels in the sentence

    for (int i = 0; message[i] != '\0'; i++) {
        if (message[i] == 'a' || message[i] == 'e' || //if statement
        message[i] == 'i' || message[i] == 'o' ||
    message[i] == 'u') {
        vowel_count = vowel_count + 1;
    }
    }
    cout << "The number of vowels in the sentence is: " << vowel_count << endl;

    return 0;
}