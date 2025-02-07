#pragma once

#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <vector>
#include <utility>
#include <list>

void ford_johnson_list(std::list<int>& lst);
void ford_johnson_vector(std::vector<int>& vector);
void loadData(std::vector<int>& vec, std::list<int>& lst, char** av, int ac);