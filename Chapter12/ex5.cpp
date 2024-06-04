// Exercise 12-5. Implement a static function printCount() for the Integer class that you 
// created earlier in Exercise 12-2 that outputs the number of Integers in existence. Modify the 
// main() function such that it tests that this number correctly goes up and down when needed.

#include <iostream>
#include <format>

class Integer
{
public:
    Integer(int value = 0);
    Integer(const Integer& obj);

    ~Integer();

    int getValue() const { return m_value; }
    void setValue(int value) { m_value = value; }
    
    Integer& add(const Integer& obj);
    Integer& subtract(const Integer& obj);
    Integer& multiply(const Integer& obj);

    friend int compare(const Integer& obj1, const Integer& obj2);
    
    void show() const;

    static void printCount(){std::cout << "Count is: " << count << std::endl;};

private:
    inline static int count {0};
    int m_value;
};

// Constructor
Integer::Integer(int value) 
  : m_value{ value }
{
    ++count;
}

// Copy constructor
Integer::Integer(const Integer& obj) 
  : m_value{obj.m_value} 
{
    ++count;
}

Integer::~Integer()
{
  --count;
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

int compare(const Integer& obj1, const Integer& obj2)
{
  if (obj1.m_value < obj2.m_value)
    return -1;
  else if (obj1.m_value == obj2.m_value)
    return 0;
  else
  	return 1;
}

void Integer::show() const
{
  std::cout << "Value is " << m_value << std::endl;
}


int main()
{
    Integer four{4};
    const Integer eight{8};

    Integer::printCount();

    return 0;
}