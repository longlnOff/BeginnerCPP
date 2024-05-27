// Exercise 9-1. Adjust Ex9_01 to use std::string_view.

#include <iostream>
#include <string>
#include <string_view>
#include <optional>

using namespace std;

optional<size_t> find_last_function(string_view string_seach, char to_find, optional<size_t> start_index = nullopt);

int main(int argc, char *argv[])
{
    const auto string = "Growing old is mandatory; growing up is optional.";
    const std::optional<size_t> found_a{ find_last_function(string, 'a') };
    if (found_a)
        std::cout << "Found the last a at index " << *found_a << std::endl;
    const auto found_b{ find_last_function(string, 'b') };
    if (found_b.has_value())
        std::cout << "Found the last b at index " << found_b.value() << std::endl;
    // following line gives an error (cannot convert std::optional<size_t> to size_t)
    // const size_t found_c{ find_last(string, 'c') };
    const auto found_early_i{ find_last_function(string, 'i', 10) };
    if (found_early_i != std::nullopt)
        std::cout << "Found an early i at index " << *found_early_i << std::endl;
}

optional<size_t> find_last_function(string_view string_seach, char to_find, optional<size_t> start_index)
{
    if (string_seach.empty())
        return nullopt;
    // determine the starting index for the loop that follows:
    size_t index {start_index.value_or(string_seach.size() - 1)};

    while (true) // never use while (index >= 0) here, as size_t is always >= 0!
    {
        if (string_seach[index] == to_find) 
            return index;
        if (index == 0) 
            return std::nullopt;
        --index;
    }
}