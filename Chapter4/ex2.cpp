
// Exercise 4-2. Write another program that prompts for two integers to be entered. This time,
// any negative number or zero is to be rejected. Next, check whether one of the (strictly positive)
// numbers is an exact multiple of the other. For example, 63 is a multiple of 1, 3, 7, 9, 21, or 63.
// Note that the user should be allowed to enter the numbers in any order. That is, it does not
// matter whether the user enters the largest number first or the smaller one; both should work
// correctly!


#include <iostream>
#include <format>

int main(int argc, char* argv[])
{
    int num1, num2;
    std::cout << "Enter two integers: ";
    std::cin >> num1 >> num2;
    std::cout << "You entered " << num1 << " and " << num2 << std::endl;
    if (num1 <= 0 || num2 <= 0) {
        std::cout << "Please enter strictly positive numbers." << std::endl;
        return 1;
    }
    if (num1 % num2 == 0 || num2 % num1 == 0) {
        std::cout << "One of the numbers is an exact multiple of the other." << std::endl;
    } else {
        std::cout << "Neither number is an exact multiple of the other." << std::endl;
    }
    return 0;
}