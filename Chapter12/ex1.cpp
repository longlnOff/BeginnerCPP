// Exercise 12-1. Create a class called Integer that has a single, private member variable 
// of type int. Provide a class constructor that outputs a message when an object is created. 
// Define member functions to get and set the member variable and to output its value. Write 
// a test program to create and manipulate at least three Integer objects and verify that you 
// can’t assign a value directly to the member variable. Exercise all the class member functions 
// by getting, setting, and outputting the value of the member variable of each object. Make sure 
// to create at least one const Integer object and verify which operations you can and cannot 
// apply on it.

#include <iostream>

class Integer
{
private:
    int m_var1 {};
public:
    Integer(int var1);
    void SetterVar1(int var1);
    int GetterVar1() const {return m_var1;}

};

Integer::Integer(int var1)
{
    std::cout <<"Create object" << std::endl;
    m_var1 = var1;
}

void Integer::SetterVar1(int var1)
{
    m_var1 = var1;
}

int main(void)
{
    Integer var1 {34};
    const Integer var2 {23};
    std::cout << var1.GetterVar1() << std::endl;
    std::cout << var2.GetterVar1() << std::endl;

    return 0;
}
