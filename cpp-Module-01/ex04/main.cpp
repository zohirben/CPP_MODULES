#include "Replace.hpp"

int main(int ac, char **av)
{
    if (!validateInput(ac, av))
        return (1);
    
    std::ifstream file;
    openFile(file, av[1]);
    if (!file)
        return (1);
    
    std::ofstream ReplaceFile;
    createReplaceFile(ReplaceFile, av[1]);
    if (!ReplaceFile)
        return (1);

    processFile(file, ReplaceFile, av[2], av[3]);

    return (0);
}