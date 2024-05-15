
// Exercise 3-6. We’ll conclude with one more exercise for puzzle fans (and exclusively so).
// Write a program that prompts for two integer values to be entered and store them in integer
// variables, a and b, say. Swap the values of a and b without using a third variable. Output the
// values of a and b.
// Hint: This is a particularly tough nut to crack. To solve this puzzle, you exclusively need one
// single compound assignment operator.

#include <iostream>
#include <format>

int main()
{
    int a, b;
    std::cout << "Enter two integers: ";
    std::cin >> a >> b;

    std::cout << std::format("Before swap: a = {}, b = {}\n", a, b);
    
    int  m {a^b};
    a = m^a;
    b = m^b;

    std::cout << std::format("After swap: a = {}, b = {}\n", a, b);
}