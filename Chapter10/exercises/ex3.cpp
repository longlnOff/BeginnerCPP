// Exercise 10-3. Write a function template called plus() that takes two arguments of potentially 
// different types and returns a value equal to the sum of both arguments. Next, make sure that 
// plus() can be used as well to add the values pointed to by two given pointers.
// Extra: Can you now make it so that you can also concatenate two string literals using plus()? 
// Warning: This may not be as easy as you think!

#include <iostream>
#include <string>
#include <format>
#include <string_view>


template <typename T1, typename T2>
auto plus(const T1& a, const T2& b)
{
    return a + b;
}

// Template for pointer
template <typename T1, typename T2>
auto plus(T1 *a , T2 *b)
{
    return *a + *b;
}

auto plus(std::string_view a, std::string_view b)
{
    return std::string{a} + std::string{b};
}

int main()
{
    int small_int {10};
    int a {12};
    double b {23};
    std::cout << plus(a, b) << std::endl;
    std::cout << plus(&a, &b) << std::endl;
    std::string_view p {"Hello fen"};
    std::string_view q {" Hello my friend"};
    std::cout << plus(p, q) << std::endl;

}


