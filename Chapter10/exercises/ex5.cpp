// Exercise 10-5. Can you think of a way to verify that the compiler generates only one instance 
// of a function template for any given argument type? Do so for the larger() function in 
// Ex10_01.cpp.

// => Use static variable in function template

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
    std::cout << "Larger of 3.5 and 4.5 is " << larger(39.5, 4.5) << std::endl;

}


// Template for functions to return the larger of two values
template <typename T>
T larger(T a, T b)
{
    static int count {0};
    std::cout << "count value: " << count << std::endl;
    ++count;
    return a > b ? a : b;
}

const char * larger(const char *a, const char *b) // Function template prototype
{
    static int count {0};
    std::cout << "count value: " << count << std::endl;
    ++count;
    return std::string_view{a} > std::string_view{b} ? a : b;

}