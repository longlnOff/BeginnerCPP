// Exercise 8-3. Write a program that accepts from two to four command-line arguments. If it is 
// called with less than two or more than four arguments, output a message telling the user what 
// they should do and then exit. If the number of arguments is correct, output them, each on a 
// separate line.

#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    const int min_arg {3};
    const int max_arg {5};
    if (argc < min_arg || argc > max_arg)
        cout << "Program only accepts from two to four command-line arguments" << endl;
    else
    {
        cout << "Each command line: " << endl;
        for (uint i {1}; i < argc; ++i)
            cout << argv[i] << endl;

    }
    

    return 0;
}