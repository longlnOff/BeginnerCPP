// Exercise 10-6. In Chapter 8, you studied a quicksort algorithm that worked for pointers-to strings. 
// Generalize the implementation of Ex8_18.cpp so that it works for vectors of any 
// type (any type for which the < operator exists, that is). Write a main() function that uses this to 
// sort some vectors with different element types and outputs both the unsorted and unsorted 
// element lists. Naturally, you should do this by also creating a function template that streams 
// vectors with arbitrary element types to std::cout.

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <format>

template <typename T>
void QuickSort(std::vector<T> &object, size_t start, size_t end);

template <typename T>
void QuickSort(std::vector<T> &object);


template <typename T>
void swap_object(std::vector<T> &object, size_t position1, size_t position2);

template <typename T>
void show(const std::vector<T>& data, size_t width = 5);

int main()
{
  std::vector<int> numbers{ -2, 4, -5, 6, 10, -40, 56, 4, 67, 45 };
  show(numbers);
  QuickSort(numbers);
  std::cout << "\nSorted integers:\n";
  show(numbers);

  std::cout << "\nCharacters to be sorted:\n";
  std::vector<char> letters{ 'C', 'd', 'a', 'z', 't', 'S', 'p', 'm', 'D', 'f' };
  show(letters, 2);
  QuickSort(letters);
  std::cout << "\nSorted characters:\n";
  show(letters, 2);

  std::cout << "\nFloating-point values to be sorted:\n";
  std::vector<double> values{ -2.5, 1.4, -2.55, 6.3, 10.1, -40.5, 56.0, 4.7, 67.3, 45.0 };
  show(values, 10);
  QuickSort(values);
  std::cout << "\nSorted floaating-point values:\n";
  show(values, 10);

}

template <typename T>
void QuickSort(std::vector<T> &object)
{
    if (!object.empty())
        QuickSort(object, 0, object.size()-1);
}

template <typename T>
void show(const std::vector<T>& data, size_t width)
{
  const size_t data_per_line{ 80 / width - 1};
  std::cout << std::format("{:{}}", data[0], width); // Output first element

  size_t data_in_line {};         // Number of data in current line
  for (size_t i {1}; i < data.size(); ++i)
  {
    if (++data_in_line == data_per_line)
    {
      data_in_line = 0;
      std::cout << std::endl;
    }
    std::cout << std::format("{:{}}", data[i], width); // Output an element
  }
  std::cout << std::endl;
}

template <typename T>
void swap_object(std::vector<T> &object, size_t position1, size_t position2)
{
    auto temp = object[position2];
    object[position2] = object[position1];
    object[position1] = temp;

}

template <typename T>
void QuickSort(std::vector<T> &object, size_t start, size_t end)
{
    if (end < start)
        return ;
    
    // Chose middle as a pivot
    size_t pivot {(start + end)/2};

    // Swap midle position and start position
    swap_object(object, start, pivot);
    // Now pivot lies at beginning position

    // Move element smaller than pivot to the left, greater than pivot to the right
    size_t current_index {start};

    // After that, current index is the last element that smaller than pivot, now swap it
    for (size_t i {start}; i <= end; ++i)
    {
        if (object[i] < object[start])
            swap_object(object, i, ++current_index);
    }

    // Now, current index is the last element which smaller than pivot, we need to swap pivot with current
    // remember, pivot is positioning at the beginning position
    swap_object(object, start, current_index);

    if (current_index > start)
        QuickSort(object, start, current_index-1);
    if (end > current_index)
        QuickSort(object, current_index+1, end);

}