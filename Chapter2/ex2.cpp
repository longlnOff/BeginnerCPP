// Exercise 2-2. Write a program that will compute the area of a circle. The program should
// prompt for the radius of the circle to be entered from the keyboard. Calculate the area using
// the formula area = pi * radius * radius, and then display the result.

#include <iostream>
#include <format>
#include <numbers>

int main(void)
{
    double radius {};
    std::cout << "Enter the radius of the circle: ";
    std::cin >> radius;
    double area {std::numbers::pi * radius * radius};
    std::cout << std::format("The area of the circle with radius {} is {:.2f}", radius, area) << std::endl;
    return 0;
}