
// Exercise 6-3. Write a program that reads an array size from the keyboard and dynamically
// allocates an array of that size to hold floating-point values. Using pointer notation, initialize all
// the elements of the array so that the value of the element at index position n is 1 / (n + 1)2.
// Calculate the sum of the elements using array notation, multiply the sum by 6, and output the
// square root of that result.

#include <iostream>
#include <iomanip>

int main()
{
    size_t ArraySize {};
    float * array {new float[ArraySize]};
    float sum {};
    std::cout << "Please enter size of array: " << std::endl;
    std::cin >> ArraySize;

    for (size_t i {0}; i < ArraySize; ++i)
    {
        *(array + i) = 1.0 / ((i + 1)*(i+1));
        sum += *(array + i);

    }
    sum *= 6;
    std::cout << "result is: " << sum << std::endl;
    delete [] array;

    return 0;
}