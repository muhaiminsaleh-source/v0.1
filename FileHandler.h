#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <string>
#include <vector>
#include "Person.h"

void generateFile(std::string filename, int count);
void readFile(std::string filename, std::vector<Person>& students);
void writeFile(std::string filename, const std::vector<Person>& students);

#endif
