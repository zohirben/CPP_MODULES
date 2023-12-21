#pragma once

#include <iostream>
#include <string>
#include <fstream>

// checks the command line arguments
bool validateInput(int ac, char **av);
// opens the input file
void openFile(std::ifstream &file, const std::string &filename);
// creates the copy output file
void createReplaceFile(std::ofstream &ReplaceFile, const std::string &filename);
// processes each line of the file replacing occurrences of a string (str1) with another string (str2)
void processFile(std::ifstream &file, std::ofstream &ReplaceFile, const std::string &str1, const std::string &str2);
