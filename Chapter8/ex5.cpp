// Exercise 8-5. Define a function that checks whether a given number is prime. Your primal check 
// does not have to be efficient; any algorithm you can think of will do. In case you have forgotten, 
// a prime number is a natural number strictly greater than 1 and with no positive divisors other 
// than 1 and itself. Write another function that generates a vector<> with all natural numbers 
// less or equal to a first number and starting from another. By default it should start from 1. 
// Create a third function that given a vector<> of numbers outputs another vector<> containing 
// all the prime numbers it found in its input. Use these three functions to create a program that 
// prints out all prime numbers less or equal to a number chosen by the user (print, for instance, 
// 15 primes per line). Note: In principle, you do not need any vectors to print these prime 
// numbers; obviously, these extra functions have been added for the sake of the exercise.


// NOTE FOR OUPUT PARAMETERS AND RETURN VALUE
/* 
In modern C++, you should generally choose to return values over output parameters. This makes 
function signatures and calls much easier to read. Arguments are for input, and all output is returned. The 
mechanism that makes this possible is called MOVE SEMANTICS and is discussed in detail in Chapter 18. In a 
nutshell, MOVE SEMANTICS ensures that returning objects that manage dynamically allocated memory—such 
as vectors and strings—no longer involves copying that memory and is therefore very cheap. Notable 
exceptions are arrays or objects that contain an array, such as std::array<>. 
For these it is still better to use output parameters.
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <format>

using namespace std;

bool IsPrimeNumber(const uint &number);
vector<uint> GenerateNumbers(const uint &limit, const uint &start = 1);
vector<uint> GetPrimeNumbers(const vector<uint> &list_number);
void PrintPrime(const vector<uint> &list_prime, const uint &number_per_line);


int main(int argc, char *argv[])
{
    uint limit {};
    uint start {};

    cout << "Please enter limit for your sequence: ";
    cin >> limit;
    cout << "Please enter start for your sequence (default = 1): ";
    cin >> start;
    vector<uint> list_prime {GetPrimeNumbers(GenerateNumbers(limit, start))};
    PrintPrime(list_prime, 15);

    return 0;
}

void PrintPrime(const vector<uint> &list_prime, const uint &number_per_line)
{
    for (uint i {0}; i < list_prime.size(); ++i)
    {
        cout << format("{:<10}", list_prime[i]);
        if (i % number_per_line == (number_per_line - 1))
            cout << endl;
    }
    cout << endl;
}



bool IsPrimeNumber(const uint &number)
{
    bool isprime {true};
    if (number % 2 == 0)
        isprime = false;
    else
    {
        uint sqrt_number {static_cast<uint>(sqrt(number))};
        for (uint i {3}; i < sqrt_number; i += 2)
        {
            if (number % i == 0)
            {
                isprime = false;
                break;
            }
        }
    }

    return isprime;
}


vector<uint> GenerateNumbers(const uint &limit, const uint &start)
{
    vector<uint> list_number {};
    for (uint i {start}; i <= limit; ++i)
        list_number.push_back(i);
    
    return list_number;
}


vector<uint> GetPrimeNumbers(const vector<uint> &list_number)
{
    vector<uint> list_prime {};
    for (auto &i : list_number)
        if (IsPrimeNumber(i))
            list_prime.push_back(i);

    return list_prime;
}
