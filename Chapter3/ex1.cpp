// Exercise 3-1. Create a program that prompts for input of an integer and store it as an int.
// Invert all the bits in this value and store the result as an int. Next, convert this inverted value
// to an unsigned int, and store it. Output the original value, the unsigned value with the bits
// inverted, and that same inverted value plus 1, each in binary representation and on one line. On
// the next line, output the original value, the signed inverted value, and the signed inverted value
// plus 1, each in decimal representation. These two lines should be formatted such that they look
// like a table, where the values in the same column are centered. You can add column headers
// as well if you like. All binary values should have leading zeros so they are all 32 bits long
// (assuming int values are 32 bits, which they usually are).
// Note: Flipping all bits and adding one—ring any bells? Can you perhaps already deduce what
// the decimal output will be before you run the program?


#include <iostream>
#include <format>
#include <bitset>

int main()
{
    int num_signed {};
    std::cout << "Please enter signed integer number: ";
    std::cin >> num_signed;
    int invert_num_signed {~num_signed};
    uint invert_num_unsigned {static_cast<uint>(invert_num_signed)};
    
    std::cout 
    << std::bitset<sizeof(int)*8>(num_signed)
    << std::format("{:2}", " ")
    << std::bitset<sizeof(uint)*8>(invert_num_unsigned)
    << std::format("{:2}", " ")
    << std::bitset<sizeof(uint)*8>(invert_num_unsigned + 1) << std::endl;


    std::cout 
    << std::format("{:^32}", num_signed)
    << std::format("{:^32}", invert_num_signed)
    << std::format("{:^32}", invert_num_signed + 1)
    << std::endl;

    return 0;
}