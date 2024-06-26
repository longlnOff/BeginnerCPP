
// Exercise 5-8. The famous Fibonacci series is a sequence of integers with the first two values as
// 1 and the subsequent values as the sum of the two preceding values. So, it begins 1, 1, 2, 3, 5,
// 8, 13, and so on. This is not just a mathematical curiosity. The sequence also regularly appears
// in biological settings, for instance. It relates to the way shells grow in a spiral, and the number
// of petals on many flowers is a number from this sequence. Create an array<> container with
// 93 elements. Store the first 93 numbers in the Fibonacci series in the array and then output
// them one per line. Any idea why we’d be asking you to generate 93 Fibonacci numbers and
// not, say, 100?

#include <iostream>
#include <array>

int main()
{
    std::array<unsigned long long, 93> fibonacci {};
    fibonacci[0] = 1;
    fibonacci[1] = 1;
    for (int i {2}; i < 93; ++i) {
        fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
    }
    for (int i {}; i < 93; ++i) {
        std::cout << fibonacci[i] << std::endl;
    }
    return 0;
}