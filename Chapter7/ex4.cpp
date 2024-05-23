// Exercise 7-4. Write a program that prompts for the input of two words and determines 
// whether one is an anagram of the other. An anagram of a word is formed by rearranging its 
// letters, using each of the original letters precisely once. For instance, listen and silent are 
// anagrams of one another, but listens and silent are not.


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
    cin >> word1;
    cout << "Enter string 2: ";
    cin >> word2;
    string word2_copy {word2};

    // Algorithm: Loop throught string 1, delete in string 2.
    for (char &i : word1)
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