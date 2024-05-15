
// Exercise 5-2. Write a program that uses a while loop to accumulate the sum of an arbitrary
// number of integers entered by the user. After every iteration, ask the user whether they are
// done entering numbers. The program should output the total of all the values and the overall
// average as a floating-point value.


#include <iostream>
#include <format>

int main()
{
    int total {};
    int count {};
    char done {};
    while (done != 'y') {
        int number {};
        std::cout << "Enter a number: ";
        std::cin >> number;
        total += number;
        ++count;
        std::cout << "Are you done entering numbers? (y/n): ";
        std::cin >> done;
    }
    std::cout << "The total of all values is: " << total << std::endl;
    std::cout << "The overall average is: " << std::format("{:.2f}", static_cast<double>(total) / count) << std::endl;
    return 0;
}