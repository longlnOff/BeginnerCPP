
// Exercise 4-5. Add some code to the end of the main() function of Ex4_07.cpp to print an
// additional message. If you have exactly one mouse, output a message of the form “It is a
// brown/white mouse.” Otherwise, if you have multiple mice, compose a grammatically correct
// message of the form “Of these mice, N is a/are brown mouse/mice.” If you have no mice, no
// new message needs to be printed. Use an appropriate mixture of conditional operators and
// if/else statements.
// Using the conditional operator to select output.
#include <iostream>
#include <format>

int main()
{
    int mice {};               // Count of all mice
    int brown {};              // Count of brown mice
    int white {};              // Count of white mice

    std::cout << "How many brown mice do you have? ";
    std::cin >> brown;
    std::cout << "How many white mice do you have? ";
    std::cin >> white;

    mice = brown + white;
    if (mice == 0) 
    {
        std::cout << "You have no mice.\n";
    } 
    else if (mice == 1) 
    {
        std::cout << "It is a " << (brown ? "brown" : "white") << " mouse.\n";
    } 
    else
        std::cout << "Of these mice, " << mice << " is " << brown << " brown mouse" << (brown == 1 ? "" : "s") << " and " << white << " white mouse" << (white == 1 ? "" : "s") << ".\n";

}