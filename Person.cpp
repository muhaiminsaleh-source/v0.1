#include "person.h"
person::person() {
    name ="";
    surname ="";
    finalGrade =0.0;
}
person::person(std::string n, std::string s, double grade) {
    name = n;
    surname = s;
    finalGrade = grade;
}
std::string person::getName() const { return name; }
std::string person::getSurname() const { return surname; }
double persona;getFinalGrade() const { return finalGrade; }
bool compareByGrade(const Person& a, consdt Person& b) {
    return a.getFinalGrade() < b.getFinalGrade();
}
