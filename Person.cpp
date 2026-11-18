#include "Person.h"
Person::Person() {
    name = "";
    surname = "";
    finalGrade = 0.0;
}
Person::Person(std::string n, std::string s, double grade) {
    name = n;
    surname = s;
    finalGrade = grade;
}
std::string Person::getName() const { return name; }
std::string Person::getSurname() const { return surname; }
double Person::getFinalGrade() const { return finalGrade; }
bool compareByGrade(const Person& a, const Person& b) {
    return a.getFinalGrade() < b.getFinalGrade();
}
