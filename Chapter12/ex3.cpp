// Exercise 12-3. Implement member functions add(), subtract(), and multiply() for the 
// Integer class that will add, subtract, and multiply the current object by the value represented 
// by the argument of type Integer. Demonstrate the operation of these functions in your class 
// with a version of main() that creates several Integer objects encapsulating integer values and 
// then uses these to calculate the value of 4×5^3+6×5^2+7×5+8. Implement the functions so that 
// the calculation and the output of the result can be performed in a single statement.

#include <iostream>

class Integer
{
    public:
        Integer(const int& var1);

        Integer();

        void SetterVar1(const int& var1);

        int GetterVar1() const {return m_var1;}

        // Copy constructor
        Integer(const Integer& input);

        int compare(const Integer& object);

        Integer& add(const Integer &input);
        Integer& subtract(const Integer &input);
        Integer& multiply(const Integer &input);


    private:
        int m_var1 {0};
};

Integer::Integer(const int& var1)
{
    std::cout <<"Create object" << std::endl;
    m_var1 = var1;
}

Integer::Integer() : Integer::Integer(0)
{
    std::cout << "create with no input" << std::endl;
}

void Integer::SetterVar1(const int& var1)
{
    m_var1 = var1;
}

// Copy constructor
Integer::Integer(const Integer& input):m_var1 {input.m_var1}
{
    std::cout << "Copy" << std::endl;
}

// Compare 
int Integer::compare(const Integer& object)
{
    if (m_var1 < object.GetterVar1())
        return -1;
    else if (m_var1 == object.GetterVar1())
        return 0;
    else
        return 1;
}


Integer& Integer::add(const Integer &input)
{
    m_var1 += input.GetterVar1();
    return *this;
}
Integer& Integer::subtract(const Integer &input)
{
    m_var1 -= input.GetterVar1();
    return *this;
}
Integer& Integer::multiply(const Integer &input)
{
    m_var1 *= input.GetterVar1();
    return *this;
}

int main(void)
{
    Integer four {4};
    Integer six {6};
    Integer eight {8};

    Integer result {four};

    std::cout << "Result is: " << result.multiply(5).add(six).multiply(5).add(7).multiply(5).add(8).GetterVar1() << std::endl;


    return 0;
}