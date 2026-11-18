#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <string>
#include <vector>
#include <deque>
#include <list>
#include "Person.h"

void generateFile(std::string filename, int count);

void readFile(std::string filename, std::vector<Person>& students);
void writeFile(std::string filename, const std::vector<Person>& students);

void readFileDeque(std::string filename, std::deque<Person>& students);
void writeFileDeque(std::string filename, const std::deque<Person>& students);

void readFileList(std::string filename, std::list<Person>& students);
void writeFileList(std::string filename, const std::list<Person>& students);

#endif
