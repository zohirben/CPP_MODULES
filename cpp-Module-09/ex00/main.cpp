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
    while(std::getline(inputFile, line))
    {   
        std::istringstream ss(line);
        std::string date, year, month, day;
        double value;

        std::getline(ss, year, '-');
        std::getline(ss, month, '-');
        std::getline(ss, day, '|');

        day.erase(day.find_last_not_of(" \n\r\t")+1);
        if (!ValidateDate(year, month, day)) {
            std::cerr << "Error: invalid date format." << std::endl;
            continue;
        }
        
        ss >> value;
        if (!ValidateValue(value)) {
            std::cerr << "Error: invalid value." << std::endl;
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

// Todo: list
// check file input.txt if you were able to open it and other errors related to it
// seperate each date month , day , year and check each one of them, probably make function including them all
// check value next to them if its max int or negative 
// for each error displayed just display the first error you encounter and use (continue;) to go to the next iteration
// ez pz you can do all that in one day alright?