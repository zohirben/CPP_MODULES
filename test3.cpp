#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <vector>
#include <utility>
#include <cmath>







int main(int ac, char **av)
{
    // std::vector<int> numbers = {7, 8, 27, 100, 11, 46, 2, 53, 1};
    std::vector<int> numbers = {7, 8, 27, 100, 11, 46, 2, 53, 1, 300, 50, 95 , 102, 19};

    int size = numbers.size();
    std::cout << "Before:  ";
    for (int i = 0; i < size; i++)
    {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;

    if (vector.size() <= 1) return;

    // create a struggler so that we store the last element in it if the array size is odd
    // so we can make sorting easier
    int struggler = -1;
    if (size % 2 != 0)
    {
        struggler = vector[size - 1];
        vector.pop_back();
        size--;
    }

    // Elements are grouped into pairs, and the larger element in each pair is moved to the first position.
    // so we can sort them easier
    std::vector<std::pair<int, int>> pairs;
    for (int i = 0; i < size - 1; i += 2)
    {
        std::pair<int, int> pair = std::make_pair(vector[i], vector[i + 1]);
        if (pair.second > pair.first)
        {
            int temp = pair.first;
            pair.first = pair.second;
            pair.second = temp;
        }
        pairs.push_back(pair);
    }
    // Recursively sort the elements based on larger elements

    quicksort(pairs, 0, pairs.size() - 1);

    // build main chain and pend

    std::vector<int> MainChain;
    std::vector<int> Pend;
    for (std::vector<std::pair<int, int>>::iterator it = pairs.begin(); it != pairs.end(); ++it)
    {
        MainChain.push_back(it->first);
        Pend.push_back(it->second);
    }

    if (Pend[0] < MainChain[0])
    {
        int pos = binary_search(MainChain, Pend[0]);
        MainChain.insert(MainChain.begin() + pos, Pend[0]);
        Pend.erase(Pend.begin());
    }

    // Generates a sequence of numbers used to determine the optimal insertion order for pend elements
    // The Jacobsthal sequence is used to determine the optimal order for inserting pend elements into the main chain
    // J(n)=J(n−1)+2⋅J(n−2)
    // then use that sequence to determine the shortest order to sort the pend into main chain using binary searchd
    std::vector<int> insertion_order = insert_order_jaco(Pend.size());

    // inesrt first pend element into main chain
    // insert pend elements into main chain using insertion order + binary search
    insert_pend(MainChain, Pend, insertion_order);

    if (struggler != -1)
    {
        int pos = binary_search(MainChain, struggler);
        MainChain.insert(MainChain.begin() + pos, struggler);
    }

    std::cout << "After:   ";
    for (int i = 0; i < MainChain.size(); i++)
    {
        std::cout << MainChain[i] << " ";
    }
    std::cout << std::endl;
}
