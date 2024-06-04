// Exercise 10-4. Write your own version of the std::size() family of functions called my_size()
// that work not only for fixed-size arrays but also for std::vector<> and std::array<> objects. 
// You are not allowed to use the sizeof() operator.

#include <iostream>
#include <span>
#include <vector>
#include <array>

// for fix size array
template <typename T, size_t N>
size_t my_size(const T (&array)[N])
{
    return N;
}

// for std::array
template <typename T, size_t N>
size_t my_size(const std::array<T, N> &array)
{
    return N;
}

// for vector
template <typename T>
size_t my_size(const std::vector<T> &vector_in)
{
    return vector_in.size();
}

using namespace std;

int main()
{
    vector<int> a {1,2,3,4,5};
    array<int, 8> b {4,5,6,7,8};
    int c[] {1,2,3,4,45,5,6};
    cout << my_size(a) << endl;
    cout << my_size(b) << endl;
    cout << my_size(c) << endl;

    return 0;
}


template <typename T1>
size_t my_size(T1 container)
{

    return 1;
}