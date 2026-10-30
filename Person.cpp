#include "Person.h"
#include <algorithm>
#include <iomanip>
#include <random>
#include <sstream>

using namespace std;

Person::Person() : name(""), surname(""), exam(0) {}

Person::Person(const Person& other) : name(other.name), surname(other.surname), hw(other.hw), exam(other.exam) {}

Person& Person::operator=(const Person& other) {
    if (this != &other) {
        name = other.name;
        surname = other.surname;
        hw = other.hw;
        exam = other.exam;
    }
    return *this;
}

Person::~Person() {
    hw.clear();
}

double Person::calculateFinalAverage() const {
    if (hw.empty()) return 0.6 * exam;
    double sum = 0;
    for (int mark : hw) sum += mark;
    double avg = sum / hw.size();
    return (0.4 * avg) + (0.6 * exam);
}

double Person::calculateFinalMedian() const {
    if (hw.empty()) return 0.6 * exam;
    vector<int> tempHw = hw;
    sort(tempHw.begin(), tempHw.end());
    double median;
    size_t size = tempHw.size();
    if (size % 2 == 0) {
        median = (tempHw[size / 2 - 1] + tempHw[size / 2]) / 2.0;
    } else {
        median = tempHw[size / 2];
    }
    return (0.4 * median) + (0.6 * exam);
}

void Person::generateRandomScores(int numHw) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 10);

    hw.clear();
    for (int i = 0; i < numHw; ++i) {
        hw.push_back(dist(gen));
    }
    exam = dist(gen);
}

istream& operator>>(istream& is, Person& p) {
    is >> p.name >> p.surname;
    string line;
    getline(is, line);
    stringstream ss(line);
    int mark;
    vector<int> tempMarks;
    while (ss >> mark) {
        tempMarks.push_back(mark);
    }
    if (!tempMarks.empty()) {
        p.exam = tempMarks.back();
        tempMarks.pop_back();
        p.hw = tempMarks;
    }
    return is;
}

ostream& operator<<(ostream& os, const Person& p) {
    os << left << setw(15) << p.name 
       << setw(15) << p.surname 
       << fixed << setprecision(2) << p.calculateFinalAverage() << " | "
       << setw(15) << p.calculateFinalMedian();
    return os;
}
