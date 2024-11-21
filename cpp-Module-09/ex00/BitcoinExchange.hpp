#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <cctype> // for ::isdigit
#include <algorithm> // for std::all_of
#include <cstdlib>
#include <limits> // for std::numeric_limits

bool ValidateDate(const std::string& year, const std::string& month, const std::string& day);
void LoadData(std::ifstream &file, std::map<std::string, double> &Database);
void CheckFile(const std::string &name, std::ifstream &file);
bool ValidateValue(double value);