
// Exercise 6-2. Revisit the previous exercise, but instead of accessing the array values using
// the loop counter, this time you should employ pointer increments (using the ++ operator) to
// traverse the array when outputting it for the first time. After that, use pointer decrements
// (using --) to traverse the array again in the reverse direction.

#include <iostream>
#include <iomanip>
#include <memory>
#include <vector>

int main()
{
    int oddNumbers[50] {};
    int *PoddNumbers {oddNumbers};
    for (int i {0}; i < 50; ++i)
    {
        *PoddNumbers = 2 * i + 1;
        PoddNumbers++;
    }
    PoddNumbers = oddNumbers;

    std::cout << "Output the numbers from the array ten to a line using pointer notation" << std::endl;
    for (int i {0}; i < 50; ++i)
    {
        if (i % 10 == 0)
        {
            std::cout << std::endl;
        }
        std::cout << std::setw(4) << *PoddNumbers++;
    }

    std::cout << std::endl << std::endl;
    std::cout << "Output the numbers in reverse order using pointer notation" << std::endl;
    for (int i {49}; i >= 0; --i)
    {
        if (i % 10 == 9)
        {
            std::cout << std::endl;
        }
        std::cout << std::setw(4) << *--PoddNumbers;
        ;
    }
    std::cout << std::endl << std::endl;

    return 0;
}