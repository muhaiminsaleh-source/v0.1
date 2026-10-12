
#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person
{
private:
    string firstName;
    string surname;
    vector<int> homework;
    int exam;
    double finalGrade;

public:
    // Default constructor
    Person();

    // Copy constructor
    Person(const Person& other);

    // Assignment operator
    Person& operator=(const Person& other);

    // Destructor
    ~Person();

    // Input and output operators
    friend istream& operator>>(istream& in, Person& person);
    friend ostream& operator<<(ostream& out, const Person& person);

    // Grade calculation methods
    double calculateAverage() const;
    double calculateMedian() const;

    // Getters
    string getFirstName() const;
    string getSurname() const;
    double getFinalGrade() const;

    // Set student data when reading from a file
    void setData(const string& name,
                 const string& lastName,
                 const vector<int>& hw,
                 int examMark);
};

#endif
