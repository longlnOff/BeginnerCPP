// Exercise 9-5. As promised, write yet another variant of Ex8_09A, Ex8_09B, and Ex8_09C, 
// where this time the average10() function uses one of the vocabulary types seen in this 
// chapter. Show that this one function can be called both for fixed-size C-style arrays and 
// std::array<> containers, and only so for arrays of ten elements.

// Passing an array to a function - use std::array<>
#include <iostream>
#include <array>
#include <span>

double average10(std::span<const double> array);        // Function prototype

int main()
{
    std::array<double,10> values{ 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0 };
    // std::array<double,3> values{ 1.0, 2.0, 3.0 };           // Only three values!!!
    std::cout << "Average = " << average10(std::span<const double> {values}) << std::endl;
}

// Function to compute an average
double average10(std::span<const double> array)
{
    double sum {};                          // Accumulate total in here
    for (double val : array)
        sum += val;                         // Sum array elements
    return sum / array.size();              // Return average
}