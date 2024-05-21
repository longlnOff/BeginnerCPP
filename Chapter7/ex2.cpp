// Exercise 7-2. Write a program that reads text entered over an arbitrary number of lines. Find 
// and record each unique word that appears in the text and record the number of occurrences 
// of each word. Output the words and their occurrence counts. Words and counts should align 
// in columns. The words should align to the left; the counts to the right. There should be three 
// words per row in your table.

#include <iostream>
#include <format>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string InputText {};
    const string separators{ " ,;:.\"!?'\n" };      // Word delimiters
    vector<string> UniqueWords {};
    vector<u_int> CountWords {};

    cout << "Please enter text (use # to interupt)" << endl;
    getline(cin, InputText, '#');
    
    size_t StartIndex {InputText.find_first_not_of(separators)};
    while (StartIndex != string::npos)
    {
        size_t end {InputText.find_first_of(separators, StartIndex + 1)};
        bool IsUnique {true};
        if (end == string::npos)
            end = InputText.length();
        string word {InputText.substr(StartIndex, end - StartIndex)};
        for (size_t i {0}; i < UniqueWords.size(); ++i)
        {
            int value {word.compare(UniqueWords[i])};
            if (value == 0)
            {
                CountWords[i] += 1;
                IsUnique = false;
                break;
            }
        }
        if (IsUnique)
        {
            UniqueWords.push_back(word);
            CountWords.push_back(1);
        }
        StartIndex = InputText.find_first_not_of(separators, end + 1);
    }



    for (size_t i {}; i < CountWords.size(); ++i)
    {
        cout << format("word: {:>4}, count: {:<4}\t", UniqueWords.at(i), CountWords.at(i));
        if (i % 3 == 2)
            cout << endl;

    }
    cout << endl;

    return 0;
}