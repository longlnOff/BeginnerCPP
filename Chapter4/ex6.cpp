
// Exercise 4-6. Write a program that determines, using only the conditional operator, if an integer
// that is entered has a value that is 20 or less, is greater than 20 but not greater than 30, is
// greater than 30 but not exceeding 100, or is greater than 100.


#include <iostream>
#include <format>

int main(int argc, char* argv[])
{
    int number {};
    std::cout << "Enter an integer: ";
    std::cin >> number;
    std::cout << "You entered " << number << "." << std::endl;
    auto result {number <= 20 ? "20 or less" : number <= 30 ? "greater than 20 but not greater than 30" : number <= 100 ? "greater than 30 but not exceeding 100" : "greater than 100"};
    std::cout << "The number is " << result << "." << std::endl;

    return 0;
}
