// Exercise 2-3. For your birthday you’ve been given a long tape measure and an instrument that
// measures angles (the angle between the horizontal and a line to the top of a tree, for instance).
// If you know the distance, d, you are from a tree, and the height, h, of your eye when peering
// into your angle-measuring device, you can calculate the height of the tree with the formula
// h + d*tan(angle). Create a program to read h in inches, d in feet and inches, and angle in
// degrees from the keyboard, and output the height of the tree in feet.

#include <iostream>
#include <format>
#include <numbers>
#include <cmath>

int main(void)
{
    float height {};
    float distance {};
    float angle {};
    const size_t inchesToFoot {12};
    const float degreesToRadians {std::numbers::pi / 180};
    std::cout << "Enter the height of your eye in inches: ";
    std::cin >> height;
    std::cout << "Enter the distance to the tree in feet: ";
    std::cin >> distance;
    std::cout << "Enter the angle in degrees: ";
    std::cin >> angle;
    float treeHeight {height + distance * std::tan(angle * degreesToRadians)};
    int feet {static_cast<int>(treeHeight / inchesToFoot)};
    float remainingInches {treeHeight - feet * inchesToFoot};
    std::cout << std::format("The height of the tree is {} feet and {:.2f} inches", feet, remainingInches) << std::endl;
    return 0;
}