
// Exercise 4-4. It’s time to make good on a promise. Somewhere in this chapter we said we’d
// look for someone “who is older than 21, younger than 35, is female, has a bachelor’s or
// master’s degree, is unmarried, and speaks Hindi or Urdu.” Write a program that prompts the
// user for these qualifications and then outputs whether they qualify for these very specific
// requirements. To this end, you should define an integer variable age, a character variable
// gender (to hold 'm' for male, 'f' for female, etc.), a variable degree of an enumeration type
// AcademicDegree (possible values: none, associate, bachelor, professional, master,
// doctor), and three Boolean variables: married, speaksHindi, and speaksUrdu. Emulate a
// trivial online job interview and query your applicant for input on all these variables. People who
// enter invalid values do not qualify, of course, and should be ruled out as early as possible (that
// is, immediately after entering any invalid value; ruling them out precognitively prior to entering
// invalid values, sadly, is not possible yet in Standard C++).

#include <iostream>
#include <format>

int main(int argc, char* argv[])
{
    int age {};
    char gender {};
    enum class AcademicDegree { none, associate, bachelor, professional, master, doctor };
    bool married {}, speaksHindi {}, speaksUrdu {};
    std::cout << "Enter your age: ";
    std::cin >> age;
    if (age <= 21 || age >= 35) {
        std::cout << "You do not qualify." << std::endl;
        return 1;
    }

    std::cout << "Enter your gender (m/f - male/female):";
    std::cin >> gender;
    if (gender != 'f' and gender != 'm') {
        std::cout << "You do not qualify." << std::endl;
        std::cout << "Please enter m or f." << std::endl;
        return 1;
    }

    std::cout << "Enter your degree (none, associate, bachelor, professional, master, doctor): ";
    std::string degree;
    std::cin >> degree;
    if (degree != "none" and degree != "associate" and degree != "bachelor" and degree != "professional" and degree != "master" and degree != "doctor") {
        std::cout << "You do not qualify." << std::endl;
        std::cout << "Please enter a valid degree." << std::endl;
        return 1;
    }

    std::cout << "Are you married? (1 for yes, 0 for no): ";
    std::cin >> married;
    if (married != 0 and married != 1) {
        std::cout << "You do not qualify." << std::endl;
        std::cout << "Please enter 1 or 0." << std::endl;
        return 1;
    }

    std::cout << "Do you speak Hindi? (1 for yes, 0 for no): ";
    std::cin >> speaksHindi;
    if (speaksHindi != 0 and speaksHindi != 1) {
        std::cout << "You do not qualify." << std::endl;
        std::cout << "Please enter 1 or 0." << std::endl;
        return 1;
    }

    std::cout << "Do you speak Urdu? (1 for yes, 0 for no): ";
    std::cin >> speaksUrdu;
    if (speaksUrdu != 0 and speaksUrdu != 1) {
        std::cout << "You do not qualify." << std::endl;
        std::cout << "Please enter 1 or 0." << std::endl;
        return 1;
    }

    std::cout << "You qualify!" << std::endl;

    return 0;
}