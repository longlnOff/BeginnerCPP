// Exercise 12-4. Change your solution for Exercise 12-2 so that it implements the compare()
// function as a friend of the Integer class. Afterward, ask yourself whether it was really 
// necessary for this function to be a friend.

#include <iostream>

class Integer
{
public:
  Integer(int value = 0);
  Integer(const Integer& obj);

  int getValue() const { return m_value; }
  void setValue(int value) { m_value = value; }
  
  Integer& add(const Integer& obj);
  Integer& subtract(const Integer& obj);
  Integer& multiply(const Integer& obj);

  int compare(const Integer& obj) const;
  
  void show() const;

private:
  int m_value;
};

// Constructor
Integer::Integer(int value) 
  : m_value{ value }
{
    std::cout << "Create object" << std::endl;
}

// Copy constructor
Integer::Integer(const Integer& obj) 
  : m_value{obj.m_value} 
{
}

Integer& Integer::add(const Integer& obj)
{ 
  m_value += obj.m_value;
  return *this;
}

Integer& Integer::subtract(const Integer& obj) 
{
  m_value -= obj.m_value;
  return *this;
}

Integer& Integer::multiply(const Integer& obj) 
{
  m_value *= obj.m_value;
  return *this;
}

int Integer::compare(const Integer& obj) const
{
  if (m_value < obj.m_value)
    return -1;
  else if (m_value == obj.m_value)
    return 0;
  else
  	return 1;
}

void Integer::show() const
{
  std::cout << "Value is " << m_value << std::endl;
}


// Implementing add(), subtract() and multiply() 

/***********************************************************
 By returning the dereferenced this pointer in the functions
 we can call the functions successively in a single statement.
 Note the parameter is a reference-to-const;
 const because the argument is not changed by the function
 and a reference to avoid the overhead of copying objects.
 The only other requirement for achieving the calculation
 in a single statement is figuring out how to sequence to
 operations to allow this.
 ***********************************************************/

int main()
{
  // Create the even operands as Integers, 
  // and use implicit conversions from int for the odd values
  Integer four{4};
  const Integer six{6};
  const Integer eight{8};

  std::cout << four.compare(six) << std::endl;

  return 0;
}