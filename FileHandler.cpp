#include "FileHandler.h"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include <iomanip>

void generateFile(std::string filename, int count) {
    std::ofstream out(filename);
    if (!out.is_open()) {
        throw std::runtime_error("File create kora jayni: " + filename);
    }

    out << "Name Surname HW1 HW2 HW3 HW4 HW5 Exam\n";
    for (int i = 1; i <= count; i++) {
        out << "Name" << i << " Surname" << i;
        for (int j = 0; j < 6; j++) {
            int mark = (rand() % 10) + 1;
            out << " " << mark;
        }
        out << "\n";
    }
    out.close();
}

void readFile(std::string filename, std::vector<Person>& students) {
    std::ifstream in(filename);
    if (!in.is_open()) {
        throw std::runtime_error("File khuje pawa jayni: " + filename);
    }

    std::string header;
    std::getline(in, header);

    std::string name, surname;
    int hw1, hw2, hw3, hw4, hw5, exam;

    while (in >> name >> surname >> hw1 >> hw2 >> hw3 >> hw4 >> hw5 >> exam) {
        double avg = (hw1 + hw2 + hw3 + hw4 + hw5) / 5.0;
        double finalGrade = 0.4 * avg + 0.6 * exam;
        students.push_back(Person(name, surname, finalGrade));
    }
    in.close();
}

void writeFile(std::string filename, const std::vector<Person>& students) {
    std::ofstream out(filename);
    if (!out.is_open()) {
        throw std::runtime_error("Output file open kora jayni: " + filename);
    }

    out << std::fixed << std::setprecision(2);
    for (size_t i = 0; i < students.size(); i++) {
        out << students[i].getName() << " "
            << students[i].getSurname() << " "
            << students[i].getFinalGrade() << "\n";
    }
    out.close();
}
