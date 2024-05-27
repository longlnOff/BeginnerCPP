// Exercise 8-6. Implement a program that queries the user for a number of grades. A grade is an 
// integer number between 0 and 100 (both inclusive). The user can stop at any time by entering a 
// negative number. Once all grades have been collected, your program is to output the following 
// statistics: the five highest grades, the five lowest grades, the average grade, the median grade, 
// and the standard deviation and variance of the grades. Of course, you’re to write a separate 
// function to compute each of these statistics. Also, you must write the code to print five values 
// only once. To practice, use arrays to store any five extremes and not, for instance, vectors.
// Hint: As a preprocessing step, you should first sort the grades the user enters; you’ll see that 
// this will make writing the functions to compute the statistics much easier. You can adapt the 
// quicksort algorithm from Ex8_17 to work with grade numbers.
// Caution: Make sure to do something sensible if the user enters less than five or even zero 
// grades. Anything is fine, as long as it does not crash.
// Note: The median is the value that appears in the middle position of a sorted list. If there is 
// an even number of grades, there obviously is no single middle value—the median is then 
// defined as the mean of the two middle values. The formulas to compute mean (μ) and standard 
// deviation (σ) of a series of n grades xi are as follows:

#include <iostream>
#include <string>
#include <format>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector<int> GetGrades();
void GetFiveHighestGrades(const vector<int> &grades);
void GetFiveLowestGrades(const vector<int> &grades);
int GetAverageGrade(const vector<int> &grades);
int GetMedianGrade(const vector<int> &grades);
float GetStandardDeviation(const vector<int> &grades);
float GetVariance(const vector<int> &grades);

int main(int argc, char *argv[])
{
    vector<int> grades {GetGrades()};
    vector<int> grades_copy {grades};
    sort(grades_copy.begin(), grades_copy.end(), greater<int>());
    GetFiveHighestGrades(grades_copy);
    GetFiveLowestGrades(grades_copy);
    GetAverageGrade(grades);
    GetMedianGrade(grades_copy);
    GetStandardDeviation(grades);
    GetVariance(grades);

    return 0;
}


vector<int> GetGrades()
{
    vector <int> list_grades {};
    int grade {};
    cout << "Please enter grade, grade must between 0 and 100 (-1 to interrupt): ";
    cin >> grade;
    while (grade >= 0 && grade <= 100)
    {
        list_grades.push_back(grade);
        cout << "Please enter grade, grade must between 0 and 100 (-1 to interrupt): ";
        cin >> grade;
    }

    return list_grades;
}



void GetFiveHighestGrades(const vector<int> &grades)
{
    size_t length = grades.size();
    if (length <= 5)
    {
        cout << "Number grades less than or equal 5. So here is list highest grade: " << endl;
        for (auto &i : grades)
        {
            cout << format("{:<10}", i);
        }
    }
    else
    {
        cout << "Here are five highest grades: " << endl;
        for (size_t i {0}; i < 5; ++i)
            cout << format("{:<10}", grades[i]);
    }
    cout << endl;
}
void GetFiveLowestGrades(const vector<int> &grades)
{
    size_t length = grades.size();
    cout << "length: " << length << endl;
    if (length <= 5)
    {
        cout << "Number grades less than or equal 5. So here is list lowest grade: " << endl;
        for (size_t i {length - 1}; i >= 0; --i)
            cout << format("{:<10}", grades[i]);
    }
    else
    {
        cout << "Here are five lowest grades: " << endl;
        for (size_t i {length - 1}; i >= length - 5; --i)
            cout << format("{:<10}", grades[i]);
    }
    cout << endl;
}
int GetAverageGrade(const vector<int> &grades)
{
    int sum {};
    for (auto &i : grades)
    {
        sum += i;
    }
    int average {sum / static_cast<int>(grades.size())};
    cout << format("Average value is: {}", average) << endl;

    return average;
}
int GetMedianGrade(const vector<int> &grades)
{
    size_t length {grades.size()};
    int median {-100000000};
    if (length % 2 == 0)
    {
        cout << "There is no median value." << endl;
    }
    else
    {
        median = grades[static_cast<size_t>(length / 2)];
        cout << "Median value is: " << median << endl;
    }

    return median;
}
float GetStandardDeviation(const vector<int> &grades)
{
    float sum {};
    for (auto &i : grades)
    {
        sum += static_cast<float>(i);
    }
    float mean {sum / static_cast<float>(grades.size())};

    float sum_square {};
    for (auto &i : grades)
    {   
        float a {static_cast<float>(i)};
        sum_square += (mean - a)*(mean - a);
    }
    float variance {sum_square / static_cast<float>(grades.size())};
    float deviation {sqrt(variance)};

    cout << "Deviation is: " << deviation << endl;

    return deviation;
}


float GetVariance(const vector<int> &grades)
{
    float sum {};
    for (auto &i : grades)
    {
        sum += static_cast<float>(i);
    }
    float mean {sum / static_cast<float>(grades.size())};

    float sum_square {};
    for (auto &i : grades)
    {   
        float a {static_cast<float>(i)};
        sum_square += (mean - a)*(mean - a);
    }
    float variance {sum_square / static_cast<float>(grades.size())};
    float deviation {sqrt(variance)};

    cout << "Variance is: " << variance << endl;

    return variance;
}