// Exercise 2-7. Add a row to your table of Exercise 2-6 for sin(π/4), showing the result with
// exponent notation and five digits after the decimal point. Make sure the exponent component
// begins with a capital E, not a lowercase e.
#include <iostream>
#include <format>
#include <numbers>
#include <vector>
#include <cmath>

int main(void)
{
    std::cout << std::format("{:<30} {:35} {}\n", "Constant", "Description", "Aproximate Value");
    std::cout << std::format("{:<30} {:35} {:.5f}...\n", "std::numbers::e", "The base of the natural logarithm", std::numbers::e);
    std::cout << std::format("{:<30} {:36} {:.5f}...\n", "std::numbers::pi", "π", std::numbers::pi);
    std::cout << std::format("{:<30} {:35} {:.5f}...\n", "std::numbers::sqrt2", "Square root of 2", std::numbers::sqrt2);
    std::cout << std::format("{:<30} {:36} {:.3f}...\n", "std::numbers::phi", "The golden ratio constant φ", std::numbers::phi);
    std::cout << std::format("{:<30} {:36} {:.3f}...\n", "std::numbers::phi", "The golden ratio constant φ", std::numbers::phi);
    std::cout << std::format("{:<30} {:35} {:.5E}\n", "std::sin(std::pi / 4.0)", "sin(pi / 4)", std::sin(std::numbers::pi / 4.0));
    
    
    return 0;
}