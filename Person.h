#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
#include <vector>

class Person {
private:
    std::string name;
    std::string surname;
    std::vector<int> hw;
    int exam;

public:
    Person();

    Person(const Person& other);

    Person& operator=(const Person& other);

    ~Person();

    void setName(std::string n) { name = n; }
    void setSurname(std::string s) { surname = s; }
    std::string getName() const { return name; }
    std::string getSurname() const { return surname; }
    
    void generateRandomScores(int numHw);

    double calculateFinalAverage() const;
    double calculateFinalMedian() const;

    friend std::istream& operator>>(std::istream& is, Person& p);
    friend std::ostream& operator<<(std::ostream& os, const Person& p);
};

#endif
