
// Exercise 5-3. Create a program that uses a do-while loop to count the number of
// nonwhitespace characters entered on a line. The count should end when the first # character is
// found.

#include <iostream>
#include <format>

int main()
{
    char ch {};
    int count {};
    do {
        std::cout << "Enter a character: ";
        std::cin >> ch;
        if (ch != ' ' && ch != '\n' && ch != '\t' && ch != '#') {
            ++count;
        }
    } while (ch != '#');
    std::cout << "The number of non-whitespace characters entered is: " << count << std::endl;
    return 0;
}