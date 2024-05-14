// Exercise 2-5. Knowing your BMI with a precision higher than one decimal digit after the
// decimal point is, well, pointless. Adjust the program of Exercise 2-4 accordingly.
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
    std::cout << std::format("Your BMI is: {:.1f}", BMI) << std::endl;

    return 0;
}