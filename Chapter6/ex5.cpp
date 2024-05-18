
// Exercise 6-5. Revisit Exercise 6-3, but this time use a smart pointer to store the array, that is,
// if you haven’t already done so from the start. A good student should’ve known not to use the
// low-level memory allocation primitives….

#include <iostream>
#include <iomanip>
#include <memory>

int main()
{
    size_t ArraySize {};
    auto array {std::make_unique<float[]>(ArraySize)};
    float sum {};
    std::cout << "Please enter size of array: " << std::endl;
    std::cin >> ArraySize;

    for (size_t i {0}; i < ArraySize; ++i)
    {
        array[i] = (1.0 / ((i + 1)*(i+1)));
        sum += array[i];

    }
    sum *= 6;
    std::cout << "result is: " << sum << std::endl;


    return 0;
}