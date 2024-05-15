
// Exercise 3-4. Write a program to read four characters from the keyboard and pack them into a
// single integer variable. Display the value of this variable as hexadecimal. Unpack the four bytes
// of the variable and output them in reverse order, with the low-order byte first.

#include <iostream>
#include <format>
#include <vector>
#include <bitset>

int main(int argc, char* argv[])
{
    char char0 {'a'}, char1{'b'}, char2{'c'}, char3{'d'};
    const int BitPerByte {8};
    int packed_char {};
    packed_char = packed_char 
                | char0 << BitPerByte * 0 
                | char1 << BitPerByte * 1 
                | char2 << BitPerByte * 2
                | char3 << BitPerByte * 3;
    std::cout << "Hexa format: " << std::hex << packed_char << std::endl;
    std::cout << std::format("The word containing 4 packed characters is {:#0x}", packed_char) << std::endl;
    // Unpack 4 bytes and output them in reverse order, with the low-order byte first.
    std::cout << char3 << ": " << std::bitset<sizeof(char) * 8>(packed_char >> (BitPerByte * 3) & 0b11111111) << std::endl;
    std::cout << char2 << ": " << std::bitset<sizeof(char) * 8>(packed_char >> (BitPerByte * 2) & 0b11111111) << std::endl;
    std::cout << char1 << ": " << std::bitset<sizeof(char) * 8>(packed_char >> (BitPerByte * 1) & 0b11111111) << std::endl;
    std::cout << char0 << ": " << std::bitset<sizeof(char) * 8>(packed_char >> (BitPerByte * 0) & 0b11111111) << std::endl;

    return 0;
}