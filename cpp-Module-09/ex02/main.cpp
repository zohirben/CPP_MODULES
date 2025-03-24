#include "PmergeMe.hpp"
#include <chrono>
#include <ctime>

#include "PmergeMe.hpp"
#include <ctime>

int main(int ac, char **av) {
    // Vector version
    std::list<int> lst;
    std::vector<int> vec;
    loadData(vec, lst, av, ac);

    std::cout << "Before: ";
    for (int i = 1; i < ac; ++i) std::cout << av[i] << " ";
    std::cout << std::endl;

    clock_t start_vec = clock();
    ford_johnson_vector(vec);
    clock_t end_vec = clock();
    double duration_vec = static_cast<double>(end_vec - start_vec) / CLOCKS_PER_SEC * 1e6;

    std::cout << "After: ";
    for (size_t i = 0; i < vec.size(); ++i) std::cout << vec[i] << " ";
    std::cout << std::endl;

    std::cout << "Time to process a range of " << vec.size() << " elements with std::vector: " 
              << duration_vec << " us" << std::endl;

    // List version
    clock_t start_lst = clock();
    ford_johnson_list(lst);
    clock_t end_lst = clock();
    double duration_lst = static_cast<double>(end_lst - start_lst) / CLOCKS_PER_SEC * 1e6;

    std::cout << "List sorted:   ";
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "Time to process a range of " << lst.size() << " elements with std::list: " 
              << duration_lst << " us" << std::endl;

    return 0;
}