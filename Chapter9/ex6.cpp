// Exercise 9-6. Suppose you have a vector<> and you know for a fact that it contains 
// exactly ten elements (or at least ten elements). Can you then call the average10()
// function of the previous example to compute the average of these ten elements (or the 
// ten first elements)? Not directly, obviously, but it is possible! 
// After all, all the necessary  data (ten consecutive elements) is present in the vector. 
// You may want to consult a Standard Library reference for this.
#include <iostream>
#include <array>
#include <span>

double average10(std::span<const double> array);        // Function prototype

int main()
{
    std::array<double,10> values{ 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0 };
    // std::array<double,3> values{ 1.0, 2.0, 3.0 };           // Only three values!!!
    std::cout << "Average = " << average10(std::span<const double, 10> {values}) << std::endl;
}

// Function to compute an average
double average10(std::span<const double> array)
{
    double sum {};                          // Accumulate total in here
    for (double val : array)
        sum += val;                         // Sum array elements
    return sum / array.size();              // Return average
}