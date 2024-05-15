
// Exercise 5-6. Create a vector<> container with elements containing the integers from 1 to an
// arbitrary upper bound entered by the user. Output the elements from the vector that contain
// values that are not multiples of 7 or 13. Output them ten on a line, aligned in columns.

#include <iostream>
#include <vector>

int main()
{
    int upper_bound {};
    std::cout << "Enter an upper bound: ";
    std::cin >> upper_bound;
    std::vector<int> numbers;
    for (int i {1}; i <= upper_bound; ++i) {
        numbers.push_back(i);
    }
    int count {};
    for (int i {}; i < numbers.size(); ++i) {
        if (numbers[i] % 7 != 0 && numbers[i] % 13 != 0) {
            std::cout << numbers[i] << '\t';
            ++count;
            if (count % 10 == 0) {
                std::cout << std::endl;
            }
        }
    }
    std::cout << std::endl;
    return 0;
}