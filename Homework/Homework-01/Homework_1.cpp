#include <iostream>
#include <string>
#include <limits>
#include <bitset>

// Function to convert an integer to its binary representation (Statement)
template <typename T>
std::string toBinary (T value) {
    return std::bitset<std::numeric_limits<T>::digits + std::is_floating_point<T>::value>(*reinterpret_cast<unsigned long long*>(&value)).to_string();
}
// Function to convert (If statements into main)(Execution from statement)
int main() {
    std::string input;
    std::cout << "Enter a char, int, or float to convert to binary:" << std::endl;
    while (std::cin >> input && input != "exit") {
        try{
            // Try convert to int
            size_t pos;
            int intValue = std::stoi(input, &pos);
            if (pos == input.length()) {
                std::cout << "Integer binary: " << toBinary(intValue) << std::endl;
                continue;
            }

            // Try convert to float
            float floatValue = std::stof(input, &pos);
            if (pos == input.length()) {
                std::cout << "Float binary: " << toBinary(floatValue) << std::endl;
                continue;
                    }
                    // If not int or float, treat as char
                    if (input.length() == 1) {
                        char charValue = input[0];
                        std::cout << "char binary: " << toBinary(charValue) << std::endl;
                        continue;
                    }

                    std::cout << "Invalid input. Please enter a single char, int, or float." << std::endl;

    } catch (const std::exception& e) {
        std::cout << "Error:" << e.what() << std::endl;
    }
}
    std::cout << "Exiting program." << std::endl;
    return 0;
}
