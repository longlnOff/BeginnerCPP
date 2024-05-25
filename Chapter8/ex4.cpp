// Exercise 8-4. Create a function, plus(), that adds two values and returns their sum. Provide 
// overloaded versions to work with int, double, and strings, and test that they work with the 
// following calls:
// const int n {plus(3, 4)};
// const double d {plus(3.2, 4.2)};
// const string s {plus("he", "llo")};
// const string s1 {"aaa"};
// const string s2 {"bbb"};
// const string s3 {plus(s1, s2)};
// Can you explain why the following doesn’t work?
// const auto d {plus(3, 4.2)};

#include <iostream>
#include <string>

// using namespace std;

int plus(int adden1, int adden2);
double plus(double x, double y);
std::string plus(const std::string &s1, const std::string &s2);

int main(int argc, char *argv[])
{
    const int n {plus(3, 4)};
    const double d {plus(3.2, 4.2)};
    const std::string s {plus("he", "llo")};
    const std::string s1 {"aaa"};
    const std::string s2 {"bbb"};
    const std::string s3 {plus(s1, s2)};
    // const auto d {plus(3, 4.2)}; // This doesn't work because the compiler can't determine which overloaded function to call
    std::cout << "n: " << n << std::endl;
    std::cout << "d: " << d << std::endl;
    std::cout << "s: " << s << std::endl;
    std::cout << "s3: " << s3 << std::endl;
    return 0;
}


int plus(int adden1, int adden2)
{
    return adden1 + adden2;
}
double plus(double x, double y)
{
    return x + y;
}
std::string plus(const std::string &s1, const std::string &s2)
{
    return s1 + s2;

}



