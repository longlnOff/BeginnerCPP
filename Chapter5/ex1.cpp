// Exercise 5-1. Write a program that outputs the squares of the odd integers from 1 up to a limit
// that is entered by the user.

#include <iostream>
#include <format>

int main()
{
    int limit {};
    std::cout << "Enter a limit: ";
    std::cin >> limit;
    for (int i {1}; i <= limit; i += 2) {
        std::cout << std::format("{:d} squared is {:d}\n", i, i * i);
    }
    return 0;
}