// Exercise 8-9. Modify the solution of Exercise 8-8 such that it counts the number of times 
// the call power(1.5,1000) performs a multiplication. Do so by replacing each multiplication 
// with a helper function mult() that takes two arguments, prints a message of how many 
// multiplications have been performed thus far, and then simply returns the product of both 
// arguments. Use at least one static variable.

#include <iostream>
#include <format>
#include <format>

using namespace std;

double power(const double &x, const int &n);
double multi_count(const double &x, const double &y);

int main()
{
  for (int i{0}; i <= 9; ++i)      // Calculate powers of 8 from -3 to +3
    std::cout << std::format("{:10g}", power(8.0, i)) << endl;

  std::cout << std::endl;
}
double multi_count(const double &x, const double &y)
{
    static uint count {0};
    count += 1;
    cout << format("Multiplication times: {}", count) << endl;
    return x * y;
}


// Recursive function to calculate x to the power n
double power(const double &x, const int &n)
{
    if (n == 0)      
        return 1.0;
    else if (n > 0)  
    {
        if (n % 2 == 0)
        {
            const auto y {power(x, n / 2)};
            return  multi_count(y, y);
        }
        else
            return multi_count(x, power(x, n - 1));
    }

    else /* n < 0 */ 
        return 1.0 / power(x, -n);
}