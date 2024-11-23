#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }
    std::ifstream file("data.csv");
    std::map<std::string, double> Database;
    LoadData(file, Database);

    std::string line;
    std::ifstream inputFile;
    CheckFile(av[1], inputFile);

    std::getline(inputFile, line);
    while (std::getline(inputFile, line))
    {
        std::istringstream ss(line);
        std::string date, year, month, day;
        double value;

        std::getline(ss, year, '-');
        std::getline(ss, month, '-');
        std::getline(ss, day, '|');

        day.erase(day.find_last_not_of(" \n\r\t") + 1);
        if (!ValidateDate(year, month, day))
        {
            std::cerr << "Error: bad Input => " + year + "-" + month + "-" + day << std::endl;
            continue;
        }

        if (!(ss >> value))
        {
            std::cerr << "Error: no value detected for date " << std::endl;
            continue;
        }
        if (!ValidateValue(value))
        {
            continue;
        }

        date = year + "-" + month + "-" + day;
        // std::cout << "date: " << date << " value: " << value << std::endl;

        std::map<std::string, double>::iterator it = Database.lower_bound(date);
        if (it != Database.end() && it->first == date)
            std::cout << date << " => " << value << " = " << (value * it->second) << std::endl;
        else if (it != Database.end() && it->first != date)
        {
            --it;
            std::cout << date << " => " << value << " = " << (value * it->second) << std::endl;
        }
        else
            std::cout << "No Date Was Found!" << std::endl;
    }
}
