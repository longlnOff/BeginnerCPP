// Adjust Ex8_11 to use std:;string_view and std::span()

#include <iostream>
#include <string_view>
#include <span>
#include <format>

using namespace std;

void show_data(span<int> data, 
                size_t count = 1,
                string_view title = "Data VAlues",
                size_t width = 10, size_t perline = 5);

int main()
{
    int samples[] {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    span<int> samples_span {samples};
    // int dataItem {-99};
    // show_data(dataItem);
    // dataItem = 13;
    show_data(samples_span, 1, "Unlucky for some!");
    show_data(samples_span, std::size(samples_span));
    show_data(samples_span, std::size(samples_span), "Samples");
    show_data(samples_span, std::size(samples_span), "Samples", 6);
    show_data(samples_span, std::size(samples_span), "Samples", 8, 4);
}

void show_data(span<int> data, 
                size_t count,
                string_view title,
                size_t width, 
                size_t perline)
{
    cout << title << endl;
    // Output the data values
    for (size_t i {0}; i < count; ++i)
    {
        cout << format("{:{}}", data[i], width);
        if ((i+1) % perline == 0)
            cout << '\n';
    }
    cout << endl;
}