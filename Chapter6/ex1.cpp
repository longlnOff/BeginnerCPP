// Exercise 6-1. Write a program that declares and initializes an array with the first 50 odd (as in
// not even) numbers. Output the numbers from the array ten to a line using pointer notation and
// then output them in reverse order, also using pointer notation.

#include <iostream>
#include <iomanip>
#include <memory>
#include <vector>

int main()
{
    int oddNumbers[50] {};
    for (int i {0}; i < 50; ++i)
    {
        *(oddNumbers + i) = 2 * i + 1;
    }

    std::cout << "Output the numbers from the array ten to a line using pointer notation" << std::endl;
    for (int i {0}; i < 50; ++i)
    {
        if (i % 10 == 0)
        {
            std::cout << std::endl;
        }
        std::cout << std::setw(4) << *(oddNumbers + i);
    }

    std::cout << std::endl << std::endl;
    std::cout << "Output the numbers in reverse order using pointer notation" << std::endl;
    for (int i {49}; i >= 0; --i)
    {
        if (i % 10 == 9)
        {
            std::cout << std::endl;
        }
        std::cout << std::setw(4) << *(oddNumbers + i);
    }
    std::cout << std::endl << std::endl;

    return 0;
}