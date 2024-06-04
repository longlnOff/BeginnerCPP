// Exercise 10-1. In C++17, the Standard Library <algorithm> module gained the handy 
// std::clamp() function template. The expression clamp(a,b,c) is used to clamp the value a
// to a given closed interval [b,c]. That is, if a is less than b, the result of the expression will be 
// b; and if a is greater than c, the result will be c; otherwise a lies within the interval [b,c] and 
// clamp() simply returns a. Write your own my_clamp() function template and try it with a little 
// test program.

#include <iostream>
#include <string>

template <typename T> T clamp(T &a, T &b, T&c);


int main()
{
    int a {2}, b {5}, c {8};
    std::cout << clamp(a, b, c) << std::endl;

    double d {13.3}, e {4.5}, f {9.2};
    std::cout << clamp(d, e, f) << std::endl;

    return 0;
}



template <typename T> T clamp(T &a, T &b, T&c)
{
    if (a >= b and a <= c)
        return a;
    else
        return a < b ? b : c;
}