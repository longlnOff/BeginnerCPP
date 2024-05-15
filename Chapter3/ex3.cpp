
// Exercise 3-3. Without running it, can you work out what the 
// following code snippet will produce as output?
// auto k {430u};
// auto j {(k >> 4) & ~(~0u << 3)};
// std::cout << j << std::endl;

// result: 2u
#include <iostream>
#include <format>


int main(int argc, char* argv[])
{
    auto k {430u};
    auto j {(k >> 4) & ~(~0u << 3)};
    std::cout << j << std::endl;

    return 0;
}