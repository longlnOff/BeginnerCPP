// Exercise 7-3. Write a program that reads a text string of arbitrary length from the keyboard 
// and prompts for entry of a word that is to be found in the string. The program should find 
// and replace all occurrences of this word, regardless of case, by as many asterisks as 
// there are characters in the word. It should then output the new string. Only whole words 
// are to be replaced. For example, if the string is "Our house is at your disposal." and 
// the word that is to be found is "our", then the resultant string should be as follows: 
// "*** house is at your disposal." and not "*** house is at y*** disposal.".

#include <iostream>
#include <string>
#include <format>
#include <algorithm>

using namespace std;

int main()
{
    string InputText {};
    string ReplacedWord {};
    const string Separators{ " ,;:.\"!?'\n" };      // Word delimiters

    cout << "Please enter input string (Enter to interrupt): " << endl;
    getline(cin, InputText);
    cout << "Please enter replaced word (# to interrupt): " << endl;
    getline(cin, ReplacedWord, '#');
    for (auto &i : ReplacedWord)
        i = tolower(i);
    // Argothirm: 
    // 1. Find start and end of word
    // 2. Convert word to lower case
    // 2. Compare ReplaceWord with sub-string
    // 3. If true replace with *
    size_t start {InputText.find_first_not_of(Separators)};

    while (start != string::npos)
    {
        size_t end {InputText.find_first_of(Separators, start + 1)};
        if (end == string::npos)
            end = InputText.length();
        string TempWord {InputText.substr(start, end - start)};
        for (auto &i : TempWord)
            i = tolower(i);
        int CompareValue {ReplacedWord.compare(TempWord)};

        // cout << format("Compared value: {}", CompareValue) << endl;
        // cout << format("String compared: {}", TempWord) << endl;
        // cout << format("Replace word: {}", ReplacedWord) << endl;

        if (CompareValue == 0)
            InputText.replace(start, end - start, ReplacedWord.length(), '*');

        start = InputText.find_first_not_of(Separators, end + 1);
    }

    cout << "String after replace: " << InputText << endl;
    cout << "Replaced Word: " << ReplacedWord << endl;

    return 0;
}