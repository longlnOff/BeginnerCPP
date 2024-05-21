// Exercise 7-1. Write a program that reads and stores the first names of any number of students, 
// along with their grades. Calculate and output the average grade and output the names and 
// grades of all the students in a table with the name and grade for three students on each line.

#include <iostream>
#include <string>
#include <format>
#include <vector>


int main(void)
{
    std::vector<std::string> NameOfStudent {};
    std::vector<float> GradeOfStudent {};
    float AverageGrade {0};

    while (true)
    {
        std::string NameEachStudent {};
        std::string GradeEachStudent {};
        std::cout << "Enter a student's name followed by Enter (leave blank to stop): ";
        std::getline(std::cin, NameEachStudent);
        if (NameEachStudent.empty())
            break;
        NameOfStudent.push_back(NameEachStudent);
        std::cout << "Enter a student's grade: ";
        std::getline(std::cin, GradeEachStudent);
        if (GradeEachStudent.empty())
            break;
        GradeOfStudent.push_back(std::stof(GradeEachStudent));
    }

    for (float &x: GradeOfStudent)
    {
        AverageGrade += x;
    }
    AverageGrade /= GradeOfStudent.size();

    for (size_t i {}; i < GradeOfStudent.size(); ++i)
    {
        std::cout << "Name: " << NameOfStudent.at(i) << ", " 
        << "Grade: " << GradeOfStudent.at(i) << "\t\t";
        if (i % 3 == 2)
            std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << std::format("Average: {:.2f}", AverageGrade) << std::endl;

    return 0;
}