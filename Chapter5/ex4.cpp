
// Exercise 5-4. Use std::cin.getline(…) to obtain a C-style string of maximum 1,000
// characters from the user. Count the number of characters the user entered using an
// appropriate loop. Next, write a second loop that prints out all characters, one by one, but in a
// reverse order.

#include <iostream>
#include <format>

int main()
{
    char str[1000];
    std::cout << "Enter a string: ";
    std::cin.getline(str, 1000);
    int count {};
    for (int i {}; str[i] != '\0'; ++i) {
        ++count;
    }
    std::cout << "The number of characters entered is: " << count << std::endl;
    std::cout << "The string in reverse order is: ";
    for (int i {count - 1}; i >= 0; --i) {
        std::cout << str[i];
    }
    std::cout << std::endl;
    return 0;
}