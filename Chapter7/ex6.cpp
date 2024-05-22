// Exercise 7-6. Write a program that reads a text string of arbitrary length from the keyboard 
// followed by a string containing one or more letters. Output a list of all the whole words in the 
// text that begin with any of the letters, uppercase or lowercase.

#include <iostream>
#include <format>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string InputString {};
    string LetterSequence {};
    string Seperators {" ,;:.\"!?'\n"};
    vector<string> OutPut {};
    cout << "Please enter string (# to interrupt): " << endl;
    getline(cin, InputString, '#');
    cout << "Please enter letter sequence: " << endl;
    cin >> LetterSequence;
    // Algorithm: Find each seperate word, compare first chracter in LetterSequence
    size_t start_index {InputString.find_first_not_of(Seperators)};
    while (start_index != string::npos)
    {
        size_t end_index {InputString.find_first_of(Seperators, start_index + 1)};
        if (end_index == string::npos)
            end_index = InputString.length();
        string word {InputString.substr(start_index, end_index - start_index)};
        string copy_letter {LetterSequence};
        for (auto &k : copy_letter)
            k = tolower(k);
        size_t check {copy_letter.find_first_of(tolower(word[0]))};
        if (check != string::npos)
            OutPut.push_back(word);

        start_index = InputString.find_first_not_of(Seperators, end_index + 1);
    }

    for (auto &i : OutPut)
        cout << i << endl;


    return 0;
}