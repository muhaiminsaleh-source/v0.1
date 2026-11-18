#ifndef PERSON_H
#define PERSON_H
#include <string>
class Person {
    private:
    std::string name;
    std::string surname;
    double finalgrade;
    public:
    person();
    person(std::string n, std::std::string s, double grade);
    std::string getname() const;
    std::string getsurname() const;
    double getFinalGrade() const;
};
bool comparebyGrade(const Person& a, const Person& b);
#endif