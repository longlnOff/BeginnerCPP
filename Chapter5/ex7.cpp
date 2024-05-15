
// Exercise 5-7. Write a program that will read and store an arbitrary sequence of records
// relating to products. Each record includes three items of data—an integer product number,
// a quantity, and a unit price. For product number 1001, the quantity is 25 and the unit price is
// $9.95. Because you do not know yet how to create compound types, simply use three different
// array-like sequences to represent these records. The program should output each product
// on a separate line and include the total cost. The last line should output the total cost for all
// products. Columns should align, so the output should be something like this:
// Product  Quantity    Unit    PriceCost
// 1001         25      $9.95   $248.75
// 1003         10      $15.50  $155.00
//                              $403.75

// Exercise 5-7. Outputting product records & cost
// Getting the alignment right is tricky.
// You have to adjust the field widths until it looks OK.
#include <iostream>
#include <format>
#include <cctype>
#include <vector>

int main()
{
  std::vector<size_t> product_id;
  std::vector<size_t> quantity;
  std::vector<double> unit_cost;

  // Read the records
  while (true)
  {
    std::cout << "Enter a record - product number, quantity, unit cost separated by spaces: ";
    size_t id {};
    size_t n {};
    double cost {};
    std::cin >> id >> n >> cost;

    product_id.push_back(id);
    quantity.push_back(n);
    unit_cost.push_back(cost);
    
    std::cout << "Do you want to enter another record (Y or N): ";
    char answer {};
    std::cin >> answer;
    if (std::toupper(answer) == 'N') break;
  }
  
  // Column headings
  std::cout << std::format("{:20} {:20} {:20} {:10}\n", 
    "Product", "Quantity", "Unit Price", "Cost");
  
  double total_cost {};
  for (size_t i {}; i < product_id.size(); ++i)
  {
    const auto cost{ quantity[i] * unit_cost[i] };
    
    std::cout <<
      std::format("{:<20} {:<20} ${:<19.2f} ${:<9.2f}\n",
        product_id[i], quantity[i], unit_cost[i], cost);
    
    total_cost += cost;
  }
  // Note the little trick to add empty space...
  std::cout << std::format("{:63}${:<9.2f}\n", "", total_cost);
}