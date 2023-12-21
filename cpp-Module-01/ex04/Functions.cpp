#include "Replace.hpp"

bool validateInput(int ac, char **av)
{
    if (ac != 4)
    {
        std::cout << "Usage: ./replace filename string1 string2\n";
        return false;
    }

    const std::string str1 = av[2];
    const std::string str2 = av[3];

    if (str1.empty() && str2.empty())
    {
        std::cout << "\033[31m" << "Both Empty String! Please Enter A Valid Input!" << "\033[0m" << std::endl;
        return false;
    }
    if (str1.empty())
    {
        std::cout << "\033[31m" << "The first string is empty! Please enter a non-empty string." << "\033[0m" << std::endl;
        return false;
    }

    return true;
}

void openFile(std::ifstream &file, const std::string &filename)
{
    file.open(filename);
    if (!file)
    {
        std::cout << "Unable To Open File";
    }
}

void createReplaceFile(std::ofstream &ReplaceFile, const std::string &filename)
{

    std::string replaceFileName = std::string(filename) + ".replace";
    ReplaceFile.open(replaceFileName);
    if (!ReplaceFile)
    {
        std::cout << "\033[31m" << "Unable To Open " << filename << ".replace File!" << "\033[0m" << std::endl;
    }
}

void processFile(std::ifstream &file, std::ofstream &ReplaceFile, const std::string &str1, const std::string &str2)
{
    if (file.peek() == EOF)
    {
        std::cout << "\033[33m" << "This File Is Empty!" << "\033[0m" << std::endl;
        exit(1);
    }
    bool replacement = false;
    std::string line;
    while (std::getline(file, line))
    {
        size_t position = 0;
        while ((position = line.find(str1, position)) != std::string::npos)
        {
            line.erase(position, str1.length());
            if (str2.empty())
                line.erase(position, 1);
            line.insert(position, str2);
            position += str2.length();
            replacement = true;
        }

        if (file.peek() != EOF)
            ReplaceFile << line << '\n';
        else
            ReplaceFile << line;
        if (file.peek() == EOF && replacement)
            std::cout << "\033[32m" << "Operation completed successfully." << "\033[0m" << std::endl;
        else if (file.peek() == EOF && !replacement)
            std::cout << "\033[36m" << "No Changes Has Been Made." << "\033[0m" << std::endl;
    }
    file.close();
    ReplaceFile.close();
}
