// Exercise 2-1. Create a program that converts inches to feet and inches. In case you’re
// unfamiliar with imperial units: 1 foot equals 12 inches. An input of 77 inches, for instance,
// should thus produce an output of 6 feet and 5 inches. Prompt the user to enter an integer value
// corresponding to the number of inches and then make the conversion and output the result.

#include <iostream>
#include <format>


int main(void)
{
    int inches {};
    const size_t inchesToFoot {12};
    std::cout << "Enter the number of inches: ";
    std::cin >> inches;
    int feet = inches / inchesToFoot;
    int remainingInches = inches % inchesToFoot;
    std::cout << std::format("{} inches is equal to {} feet and {} inches", inches, feet, remainingInches) << std::endl;
    return 0;
}