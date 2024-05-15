
// Exercise 4-3. Create a program that prompts for input of a number (nonintegral numbers are
// allowed) between 1 and 100. Use a nested if, first to verify that the number is within this
// range and then, if it is, to determine whether it is greater than, less than, or equal to 50. The
// program should output information about what was found.

#include <iostream>
#include <format>

int main(int argc, char* argv[])
{
    float number {};
    std::cout << "Enter a number between 1 and 100: ";
    std::cin >> number;
    std::cout << "You entered " << number << "." << std::endl;
    if (number > 1.0 && number < 100.0) {
        std::cout << "The number is between 1 and 100." << std::endl;
        if (number > 50.0) {
            std::cout << "The number is greater than 50." << std::endl;
        } else if (number < 50.0) {
            std::cout << "The number is less than 50." << std::endl;
        } else {
            std::cout << "The number is equal to 50." << std::endl;
        }
    } else {
        std::cout << "The number is not between 1 and 100." << std::endl;
    }
}