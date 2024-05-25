// Exercise 8-1. Write a function, validate_input(), that accepts two integer arguments that 
// represent the upper and lower limits for an integer that is to be entered. It should accept a third 
// argument that is a string describing the input, with the string being used in the prompt for input 
// to be entered. The function should prompt for input of the value within the range specified by 
// the first two arguments and include the string identifying the type of value to be entered. The 
// function should check the input and continue to prompt for input until the value entered by the 
// user is valid. Use the validate_input() function in a program that obtains a user’s date of 
// birth and outputs it in the form of this example:
// You were born on the 21st of November, 2012
// The program should be implemented so that separate functions, month(), year(), and day(), 
// manage the input of the corresponding numerical values. Don’t forget leap years—February 29, 
// 2017, is not allowed!

#include <iostream>
#include <string>
#include <vector>
#include <format>

using namespace std;

uint validate_input(const uint &upper, const uint &lower, const string &prompt = "Enter number");
uint day_f(const uint &year, const uint &month);
uint month_f();
uint year_f();
string ending_date(const uint &day);


int main()
{   
    vector<string> month_name {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    uint year {};
    uint day {};
    uint month {};

    year = year_f();
    month = month_f();
    day = day_f(year, month);
    cout << format("You were born on the {}{} of {}, {}", day, ending_date(day), month_name[month-1], year) << endl;

    return 0;
}

string ending_date(const uint &day)
{
    if (day == 1 || day == 21 || day == 31)
        return "st";
    else if (day == 2 || day == 22)
        return "nd";
    else if (day == 3 || day == 23)
        return "rd";
    else
        return "th";
}

uint year_f()
{
    return validate_input(2021, 1900, "Enter year");
}

uint month_f()
{
    return validate_input(12, 1, "Enter month");
}

uint day_f(const uint &year, const uint &month)
{
    vector<uint> date_in_month {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && year % 4 == 0 && !(year % 100 == 0 && year % 400 != 0))
        return validate_input(29, 1, "a date");
    else
        return validate_input(date_in_month[month - 1], 1, "a date");
}

uint validate_input(const uint &upper, const uint &lower, const string &prompt)
{
    uint input {};
    cout << prompt << endl;
    cout << format("Value must in between {} and {}.", lower, upper) << endl;
    cin >> input;
    while ((input < lower) || (input > upper))
    {   
        cout << "please enter a valid number: ";
        cout << "Value must in between " << lower << " and " << upper << endl;
        cin >> input;
    }

    return input;
}

