// Exercise 10-2. Alter the last lines of Ex10_01’s main() function as follows:
// const auto a_string = "A", z_string = "Z";
// std::cout << "Larger of " << a_string << " and " << z_string
// << " is " << larger(a_string, z_string) << std::endl;
// If you now run the program, you may very well get the following output (if not, try rearranging 
// the order in which a_string and z_string are declared):
// Larger of 1.5 and 2.5 is 2.5
// Larger of 3.5 and 4.5 is 4.5
// Larger of 17011983 and 10 is 17011983
// Larger of A and Z is A
// What’s that? "A" is larger than "Z"? Can you explain what went wrong? Can you fix it?
// Hint: To compare two character arrays, you could perhaps first convert them to another string 
// representation.

#include <iostream>
#include <format>
#include <string>
#include <string_view>

template<typename T> T larger(T a, T b); // Function template prototype
const char * larger(const char *a, const char *b); // Function template prototype

int main()
{
    std::cout << "Larger of 1.5 and 2.5 is " << larger(1.5, 2.5) << std::endl;
    std::cout << "Larger of 3.5 and 4.5 is " << larger(3.5, 4.5) << std::endl;
    int big_int {17011983}, small_int {10};
    std::cout << std::format("Larger of {} and {} is {}\n",
    big_int, small_int, larger(big_int, small_int));
    const auto z_string_1 = "Z", a_string_1 = "A";
    std::cout << "Larger of " << a_string_1 << " and " << z_string_1
    << " is " << larger(a_string_1, z_string_1) << std::endl;

}


// Template for functions to return the larger of two values
template <typename T>
T larger(T a, T b)
{

    return a > b ? a : b;
}

const char * larger(const char *a, const char *b) // Function template prototype
{
    return std::string_view{a} > std::string_view{b} ? a : b;

}
