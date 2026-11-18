#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person {
private:
    std::string name;
    std::string surname;
    double finalGrade;

public:
    Person();
    Person(std::string n, std::string s, double grade);

    std::string getName() const;
    std::string getSurname() const;
    double getFinalGrade() const;
};

bool compareByGrade(const Person& a, const Person& b);

#endif
