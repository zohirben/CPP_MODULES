#include "PmergeMe.hpp"

int main(int ac, char **av) {
    // Vector version
    std::list<int> lst;
    std::vector<int> vec;
    loadData(vec, lst, av, ac);
    //  = {7, 8, 27, 100, 11, 46, 2, 53, 1};
    
    ford_johnson_vector(vec);
    std::cout << "Vector sorted: ";
    for (size_t i = 0; i < vec.size(); ++i) std::cout << vec[i] << " ";
    std::cout << std::endl;

    // List version
    ford_johnson_list(lst);
    std::cout << "List sorted:   ";
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}