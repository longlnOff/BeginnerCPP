// Exercise 12-2. Modify the Integer class in the previous exercise so that an Integer object 
// can be created without an argument. The member value should then be initialized to zero. Can 
// you think of two ways to do this? Also, implement a copy constructor that prints a message 
// when called.
// Next, add a member function that compares the current object with an Integer object passed 
// as an argument. The function should return –1 if the current object is less than the argument, 
// 0 if the objects are equal, and +1 if the current object is greater than the argument. Try two 
// versions of the Integer class, one where the compare() function argument is passed by value 
// and the other where it is passed by reference. What do you see output from the constructors 
// when the function is called? Make sure you understand why this is so. You can’t have both 
// functions present in the class as overloaded functions. Why not?


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

/*****************************************************************\
 Using the version of compare() with the pass-by-value parameter,
 the copy constructor is called because a copy of the argument
 is passed to the function.

 Using the version with the reference parameter a reference
 to the object is passed to the function so no constructor call
 is necessary.

 You cannot overload a function with a reference parameter with
 a function that has a non-reference parameter because the
 compiler cannot tell which function should be called in any
 particular instance.
\*****************************************************************/

int main(void)
{
    Integer var1 {34};
    Integer var3;
    const Integer var2 {23};
    std::cout << var1.GetterVar1() << std::endl;
    std::cout << var2.GetterVar1() << std::endl;

    Integer var4 {var1};
    std::cout << var4.GetterVar1() << std::endl;

    std::cout << var1.compare(var4) << std::endl;
    std::cout << var1.compare(var1) << std::endl;
    std::cout << var1.compare(var2) << std::endl;

    return 0;
}