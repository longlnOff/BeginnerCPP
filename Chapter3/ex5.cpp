
// Exercise 3-5. Write a program that defines an enumeration of type Color where the enumerators
// are red, green, yellow, purple, blue, black, and white. Define the type for enumerators as
// an unsigned integer type and arrange for the integer value of each enumerator to be the RGB
// combination of the color it represents (you can easily find the hexadecimal RGB encoding of any
// color online). Create variables of type Color initialized with enumerators for yellow, purple, and
// green. Access the enumerator value and extract and output the RGB components as separate values.
#include <iostream>
#include <format>

int main()
{
    enum class Color : unsigned
    {
        red = 0xFF0000u,
        green = 0x00FF00u,
        yellow = 0xFFFF00u,
        purple = 0x800080u,
        blue = 0x0000FFu,
        black = 0x000000u,
        white = 0xFFFFFFu
    };

    Color yellow {Color::yellow};
    Color purple {Color::purple};
    Color green {Color::green};

    std::cout << std::format("The components of {} are: red: {:3}, green: {:3}, blue: {:3}\n",
        "yellow",
        (static_cast<unsigned>(yellow) & static_cast<unsigned>(Color::red)) >> 16,
        (static_cast<unsigned>(yellow) & static_cast<unsigned>(Color::green)) >> 8,
        (static_cast<unsigned>(yellow) & static_cast<unsigned>(Color::blue))
    );

    std::cout << std::format("The components of {} are: red: {:3}, green: {:3}, blue: {:3}\n",
        "purple",
        (static_cast<unsigned>(purple) & static_cast<unsigned>(Color::red)) >> 16,
        (static_cast<unsigned>(purple) & static_cast<unsigned>(Color::green)) >> 8,
        (static_cast<unsigned>(purple) & static_cast<unsigned>(Color::blue))
    );

    std::cout << std::format("The components of {} are: red: {:3}, green: {:3}, blue: {:3}\n",
        "green",
        (static_cast<unsigned>(green) & static_cast<unsigned>(Color::red)) >> 16,
        (static_cast<unsigned>(green) & static_cast<unsigned>(Color::green)) >> 8,
        (static_cast<unsigned>(green) & static_cast<unsigned>(Color::blue))
    );
}