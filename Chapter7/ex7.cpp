// Exercise 7-7. Create a program that reads an arbitrarily long sequence of integer numbers 
// typed by the user into a single string object. The numbers of this sequence are to be 
// separated by spaces and terminated by a # character. The user may or may not press Enter 
// between two consecutive numbers. Next, extract all numbers from the string one by one.

#include <iostream>
#include <format>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string InputString {};
    vector<int> Numbers {};
    string Seperators {" ,;:.\"!?'\n"};
    cout << "Please enter string of numbers, each number is seperated by space or endline (# to interrupt): " << endl;
    getline(cin, InputString, '#');

    size_t start_index {InputString.find_first_not_of(Seperators)};
    while (start_index != string::npos)
    {
        size_t end_index {InputString.find_first_of(Seperators, start_index + 1)};
        if (end_index == string::npos)
            end_index = InputString.length();
        string word {InputString.substr(start_index, end_index - start_index)};
        Numbers.push_back(stoi(word));
        start_index = InputString.find_first_not_of(Seperators, end_index + 1);
    }
    cout << "List number: " << endl;
    for (auto &i : Numbers)
        cout << i << ' ';
    cout << endl;

    return 0;
}
