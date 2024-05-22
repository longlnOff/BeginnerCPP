// Exercise 7-8. A tautogram is a body of text in which all words start with the same letter. In 
// English, an example would be “Truly tautograms triumph, trumpeting trills to trounce terrible 
// travesties.” Ask the user for a string, and verify whether it is a tautogram (ignoring casing). If 
// it is, output also the letter by which each word starts.

// Note: True tautograms are truly tough to throw together, so perhaps you can bend the rules 
// a bit? Maybe allow short words to glue the text together (such as “a,” “to,” “is,” “are,” etc.), 
// or only require a certain percentage of words to begin with the same letter? Have some fun 
// with it!

#include <iostream>
#include <format>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string InputString {};
    string Seperators {" ,;:.\"!?'\n"};
    cout << "Please enter string (# to interrupt): " << endl;
    getline(cin, InputString, '#');
    char FirstChar {'.'};
    bool tautogram {true};
    size_t start_index {InputString.find_first_not_of(Seperators)};
    while (start_index != string::npos)
    {
        size_t end_index {InputString.find_first_of(Seperators, start_index + 1)};
        if (end_index == string::npos)
            end_index = InputString.length();
        string word {InputString.substr(start_index, end_index - start_index)};
        if (FirstChar == '.')
            FirstChar = tolower(word[0]);
        if (FirstChar != tolower(word[0]))
        {
            tautogram = false;
            break;
        }

        start_index = InputString.find_first_not_of(Seperators, end_index + 1);
    }
    cout << "String is: " << InputString << endl;
    cout << (tautogram ? "" : "Not") << ' ' << "Tautogram" << endl;
}