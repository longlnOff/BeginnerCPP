// Exercise 7-5. Generalize the program of Exercise 7-4 such that it ignores spaces when 
// deciding whether two strings are anagrams. With this generalized definition, funeral and real 
// fun are considered anagrams, as are eleven plus two and twelve plus one, and desperation
// and a rope ends it.

#include <iostream>
#include <format>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string word1 {};
    string word2 {};
    cout << "Enter string 1: ";
    getline(cin, word1);
    cout << "Enter string 2: ";
    getline(cin, word2);
    string word1_copy {word1};
    string word2_copy {word2};

    // Algorithm: 
    // Loop throught string 1, delete in string 2.
    // Remove space in each string.

    size_t index {word1_copy.find(' ')};
    while (index != string::npos)
    {
        word1_copy.erase(index, 1);
        index = word1_copy.find(' ');
    }
    index = word2_copy.find(' ');
    while (index != string::npos)
    {
        word2_copy.erase(index, 1);
        index = word2_copy.find(' ');
    }



    for (char &i : word1_copy)
    {
        for (size_t j {0}; j < word2_copy.size(); ++j)
        {
            if (tolower(i) == tolower(word2_copy.at(j)))
            {
                word2_copy.erase(j, 1);
                break;
            }
        }
    }

    cout << '"' << word1 << '"' 
         << " and " 
         <<  '"' << word2 << '"'
         << " are "
         << (word2_copy.empty() ? "" : "not ")
         << "anagrams of one another."
         << endl;
    
    return 0;
}