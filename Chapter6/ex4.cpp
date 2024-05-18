
// Exercise 6-4. Repeat the calculation in Exercise 6-3 but using a vector<> container allocated
// in the free store. Test the program with more than 100,000 elements. Do you notice anything
// interesting about the result?

#include <iostream>
#include <iomanip>
#include <vector>
int main()
{
    size_t ArraySize {};
    std::vector<float> array {};
    float sum {};
    std::cout << "Please enter size of array: " << std::endl;
    std::cin >> ArraySize;

    for (size_t i {0}; i < ArraySize; ++i)
    {
        array.push_back(1.0 / ((i + 1)*(i+1)));
        sum += array[i];

    }
    sum *= 6;
    std::cout << "result is: " << sum << std::endl;

    return 0;
}