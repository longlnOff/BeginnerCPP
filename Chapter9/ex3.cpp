// Exercise 9-3. Adjust Ex8_13 to use vocabulary types.


#include <iostream>
#include <string>
#include <string_view>
#include <span>
#include <format>

using namespace std;

void show_data(span<const double> data, 
                size_t count = 1,
                string_view title = "Data Values",
                size_t width = 10, 
                size_t perLine = 5);

std::optional<double> largest(span<const double> data, 
                        size_t count);

std::optional<double> smallest(span<const double> data, 
                        size_t count);

span<double> shift_range(span<double> data, 
                    size_t count, 
                    double delta);

span<double> scale_range(span<double> data, 
                    size_t count, 
                    double divisor);

span<double> normalize_range(span<double> data, 
                        size_t count);

int main()
{
    double samples[] {11.0, 23.0, 13.0, 4.0, 57.0, 36.0, 317.0, 88.0, 9.0, 100.0, 121.0, 12.0};
    const size_t count{std::size(samples)};                                     // Number of samples
    show_data(span<const double> {samples}, count, "Original Values");                // Output original values
    normalize_range(span<double> {samples}, count);                             // Normalize the values
    show_data(span<const double> {samples}, count, "Normalized Values", 12);          // Output normalized values
}


// Outputs an array of double values
void show_data(span<const double> data, 
                size_t count,
                string_view title, 
                size_t width, 
                size_t perLine)
{
    std::cout << title << std::endl; // Display the title
    // Output the data values
    for (size_t i {}; i < count; ++i)
    {
        // Display a data item (uses a dynamic field width: see Chapter 7)
        std::cout << std::format("{:{}.6g}", data[i], width);
        if ((i + 1) % perLine == 0) // Newline after perLine values
            std::cout << '\n';
    }
    std::cout << std::endl;
}


std::optional<double> smallest(span<const double> data, size_t count)
{
    if (!count) return {};     // There is no smallest in an empty array

    size_t index_min {};
    for (size_t i {1}; i < count; ++i)
        if (data[index_min] > data[i])
        index_min = i;

    return data[index_min];
}


span<double> shift_range(span<double> data, size_t count, double delta)
{
    for (size_t i {}; i < count; ++i)
        data[i] += delta;
    return data;
}

std::optional<double> largest(span<const double> data, size_t count)
{
    if (!count) return {};    // There is no largest in an empty array

    size_t index_max {};
    for (size_t i {1}; i < count; ++i)
        if (data[index_max] < data[i])
        index_max = i;

    return data[index_max];
}

span<double> scale_range(span<double> data, size_t count, double divisor)
{
    if (!divisor) return data;     // Do nothing for a zero divisor

    for (size_t i{}; i < count; ++i)
        data[i] /= divisor;
    return data;
}

span<double> normalize_range(span<double> data, size_t count)
{
    shift_range(data, count, -(smallest(data, count).value()));
    return scale_range(data, count, largest(data, count).value());
}