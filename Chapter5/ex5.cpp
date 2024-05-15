
// Exercise 5-5. Write a program equivalent to that of Exercise 5-4, except for the following:
// •If before you used a for loop to count the characters, you now use while, or vice
// versa.
// •This time you should first reverse the characters in the array, before printing them
// out left to right (for the sake of the exercise you could still use a loop to print out
// the characters one by one).

#include <iostream>
#include <format>

int main()
{
    char str[1000];
    std::cout << "Enter a string: ";
    std::cin.getline(str, 1000);
    int count {};
    int i {};
    while (str[i] != '\0') {
        ++count;
        ++i;
    }
    std::cout << "The number of characters entered is: " << count << std::endl;
    std::cout << "The string in reverse order is: ";
    for (int i {count - 1}; i >= 0; --i) {
        std::cout << str[i];
    }
    std::cout << std::endl;
    return 0;
}