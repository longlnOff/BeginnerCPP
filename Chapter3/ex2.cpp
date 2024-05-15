// Exercise 3-2. Write a program to calculate how many square boxes can be contained in a
// single layer on a rectangular shelf, with no overhang. The dimensions of the shelf in feet and
// the dimensions of a side of the box in inches are read from the keyboard. Use variables of type
// double for the length and depth of the shelf and type int for the length of the side of a box.
// Define and initialize an integer constant to convert from feet to inches (1 foot equals 12 inches).
// Calculate the number of boxes that the shelf can hold in a single layer of type long and output
// the result.

#include <iostream>
#include <format>

int main(void)
{
    const int FeetToInch {12};
    int BoxSide {};
    double ShelfDepth {};
    double ShelfLength {};
    long num_box {};
    std::cout << "please enter shelf's depth in feet: ";
    std::cin >> ShelfDepth;
    std::cout << "Please enter shelf's length in feet: ";
    std::cin >> ShelfLength;
    std::cout << "Please enter box's side in inch: ";
    std::cin >> BoxSide;
    num_box = static_cast<long>(ShelfDepth * 12 / BoxSide) * static_cast<long>(ShelfLength * 12 / BoxSide);
    std::cout << std::format("Number of box which can be fitted in shelf: {:^5}", num_box) << std::endl;

    return 0;
}

