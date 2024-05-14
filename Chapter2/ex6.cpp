// Exercise 2-6. Reproduce Table 2-6 with a program, without hard-coding the numeric values or
// filling spaces, of course. If your command-line interface does not support Unicode characters
// (perfectly possible), you can replace π with “pi” and omit φ (the Greek letter “phi,” in case you
// were wondering).
#include <iostream>
#include <format>
#include <numbers>
#include <vector>

int main(void)
{
    std::cout << std::format("{:<20} {:35} {}\n", "Constant", "Description", "Aproximate Value");
    std::cout << std::format("{:<20} {:35} {:.5f}...\n", "std::numbers::e", "The base of the natural logarithm", std::numbers::e);
    std::cout << std::format("{:<20} {:36} {:.5f}...\n", "std::numbers::pi", "π", std::numbers::pi);
    std::cout << std::format("{:<20} {:35} {:.5f}...\n", "std::numbers::sqrt2", "Square root of 2", std::numbers::sqrt2);
    std::cout << std::format("{:<20} {:36} {:.3f}...\n", "std::numbers::phi", "The golden ratio constant φ", std::numbers::phi);
    
    return 0;
}