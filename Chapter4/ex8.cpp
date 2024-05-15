
// Exercise 4-8. Create a program that prompts the user to enter an amount of money between
// $0 and $10 (decimal places allowed). Any other value is to be rejected politely. Determine
// how many quarters (25c), dimes (10c), nickels (5c), and pennies (1c) are needed to make up
// that amount. For our non-American readers, one dollar ($) equals 100 cents (c). Output this
// information to the screen and ensure that the output makes grammatical sense (for example, if
// you need only one dime, then the output should be “1 dime” and not “1 dimes”).

#include <iostream>
#include <format>

int main(int argc, char* argv[])
{
    double amount {};
    std::cout << "Enter an amount of money between $0 and $10: ";
    std::cin >> amount;
    if (amount < 0 || amount > 10) {
        std::cout << "Sorry, the amount must be between $0 and $10." << std::endl;
        return 1;
    }
    int cents {static_cast<int>(amount * 100)};
    int quarters {cents / 25};
    cents %= 25;
    int dimes {cents / 10};
    cents %= 10;
    int nickels {cents / 5};
    cents %= 5;
    int pennies {cents};
    std::cout << "For $" << amount << " you need:" << std::endl;
    std::cout << std::format("{:d} quarter{}\n", quarters, quarters <= 1 ? "" : "s");
    std::cout << std::format("{:d} dime{}\n", dimes, dimes <= 1 ? "" : "s");
    std::cout << std::format("{:d} nickel{}\n", nickels, nickels <= 1 ? "" : "s");
    std::cout << std::format("{:d} penny{}\n", pennies, pennies <= 1 ? "" : "ies");
    
    return 0;
}