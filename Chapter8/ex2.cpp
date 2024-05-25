// Exercise 8-2. Write a function that reads a string or array of characters as input and reverses 
// it. Justify your choice of parameter type? Provide a main() function to test your function that 
// prompts for a string of characters, reverses them, and outputs the reversed string.

#include <string>
#include <iostream>
#include <format>
#include <vector>

using namespace std;

string reverse_string(const string &input);

int main()
{
    string input {};
    cout << "Enter a string: ";
    getline(cin, input);
    cout << format("The reversed string is: {}", reverse_string(input)) << endl;

    return 0;
}

string reverse_string(const string &input)
{
    string reversed {};
    for (int i = input.size() - 1; i >= 0; --i)
        reversed += input[i];
    return reversed;
}