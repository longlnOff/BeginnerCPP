// Exercise 4-1. Write a program that prompts for two integers to be entered and then uses an
// if-else statement to output a message that states whether the integers are the same.

#include <iostream>

int main() {
    int num1, num2;
    std::cout << "Enter two integers: ";
    std::cin >> num1 >> num2;
    std::cout << "You entered " << num1 << " and " << num2 << std::endl;
    if (num1 == num2) {
        std::cout << "The integers are the same." << std::endl;
    } else {
        std::cout << "The integers are not the same." << std::endl;
    }
    return 0;
}