// Exercise 2-4. Your body mass index (BMI) is your weight, w, in kilograms divided by the square
// of your height, h, in meters (w/(h*h)). Write a program to calculate the BMI from a weight
// entered in pounds and a height entered in feet and inches. A kilogram is 2.2 pounds, and a foot
// is 0.3048 meters.
#include <iostream>
#include <format>


int main(void)
{
    float weight {};
    float height {};
    float BMI {};
    const float kiloToPounds {2.2f};
    const float footToMeters {0.3048f};
    std::cout << "Entering you weight in pounds: ";
    std::cin >> weight;
    std::cout << "Entering you height in feet: ";
    std::cin >> height;
    BMI = (weight * kiloToPounds) / ((height / footToMeters) * (height / footToMeters));
    std::cout << "Your BMI is: " << BMI << std::endl;

    return 0;
}