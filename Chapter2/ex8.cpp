// Exercise 2-8. Here’s an extra exercise for puzzle fans. Write a program that will prompt the user
// to enter two different positive integers. Identify in the output the value of the larger integer and
// the value of the smaller integer. Using the decision-making facilities of Chapter 5, this would
// be like stealing a piece of cake from a baby while walking in the park. What makes this a tough
// brain teaser, though, is that this can be done solely with the operators you’ve learned about in
// this chapter!

#include <iostream>
#include <cmath>
#include <assert.h>
#include <typeinfo>
#include <format>

int main(void)
{
    size_t number1 {};
    size_t number2 {};

    std::cout << "Please enter positive integer number 1: ";
    std::cin >> number1;
    std::cout << "Please enter positive integer number 2: ";
    std::cin >> number2;

    assert(typeid(number1) == typeid(size_t) && typeid(number2) == typeid(size_t));
    size_t larger_num {(number1 * (number1 / number2) + number2 * (number2 / number1)) / (number1 / number2 + number2 / number1)};
    size_t smaller_num {(number2 * (number1 / number2) + number1 * (number2 / number1)) / (number1 / number2 + number2 / number1)};
    std::cout << larger_num << std::endl;
    std::cout << smaller_num << std::endl;



    return 0;
}