// Exercise 7-9. Extend your solution to Exercise 7-8 to remove all occurrences of the 
// tautogram’s beginning letter (ignoring casing). You could do it the easy way (remember the 
// Standard Library function you can use to accomplish this?), but perhaps it’s more interesting 
// to do it the hard way and write the complete code yourself?

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
    string text_without_start_letter {};
    for (char c : InputString)
    {
      if (tolower(c) != FirstChar)
      {
        text_without_start_letter.push_back(c);
      }
    }

    std::cout << "After removing this letter, the text becomes as follows:\n" << text_without_start_letter << std::endl;
    return 0;
}