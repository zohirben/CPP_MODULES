#include "BitcoinExchange.hpp"

/*load the cvs's data into a container which will be used later for comparing*/
void LoadData(std::ifstream &file, std::map<std::string, double> &Database)
{
    std::string line;
    std::getline(file, line); // skip the first line


    while(std::getline(file, line))
    {
        std::istringstream ss(line);
        std::string date;
        double rate;

        std::getline(ss, date, ',');
        ss >> rate;
        Database[date] = rate;
        // std::cout << "date: " << date << " rate: " << rate << std::endl;
    }
}

void CheckFile(const std::string &name, std::ifstream &file)
{
    file.open(name.c_str()); // i had to turn std::string into c style string cuz the function requires a const char pointer
    if (!file.is_open()) {
        std::cerr << "Error: could not open file " << name << std::endl;
        exit(1);
    }
}

bool isNumber(const std::string &str)
{
    if (str.empty()) return false;
    for (std::string::const_iterator it = str.begin(); it != str.end(); ++it) {
        if (!std::isdigit(*it)) return false;
    }
    return true;
}

int ft_atoi(const std::string &str)
{
    std::istringstream iss(str);
    int num;
    iss >> num;
    return num;
}

bool ValidateDate(const std::string& year, const std::string& month, const std::string& day) 
{
    if (year.size() == 4 && ft_atoi(year) > 0 && isNumber(year))
        if (month.size() == 2 && ft_atoi(month) && isNumber(month) && (ft_atoi(month) >= 1 && ft_atoi(month) <= 12))
            if (day.size() == 2 && ft_atoi(day) && isNumber(day) && (ft_atoi(day) >= 1 && ft_atoi(day) <= 31))
                return true;

    return false;
}

bool ValidateValue(double value) 
{
    if (!value)
    {
        std::cerr << "Error: no value detected." << std::endl;
        return false;
    }
    else if (value < 0)
    {
        std::cerr << "Error: not a positive number." << std::endl;
        return false;
    }
    else if (value > 1000)
    {
        std::cerr << "Error: too large a number." << std::endl;
        return false;
    }
    
    return true;
}