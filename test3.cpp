#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <vector>
#include <utility>

int partition(std::vector<std::pair<int, int> > &pairs, int low, int high)
{
    int pivot = pairs[high].first;
    int i = low - 1;

    for (int j = low; j < high; ++j)
    {
        if (pairs[j].first <= pivot)
        {
            ++i;
            std::swap(pairs[i], pairs[j]);
        }
    }
    std::swap(pairs[i + 1], pairs[high]);
    return i + 1;
}

// Recursive quicksort function
void quicksort(std::vector<std::pair<int, int> > &pairs, int low, int high)
{
    if (low < high)
    {
        int pi = partition(pairs, low, high);
        quicksort(pairs, low, pi - 1);
        quicksort(pairs, pi + 1, high);
    }
}

std::vector<int> generate_jacobsthal(int length)
{
    std::vector<int> jacobsthal = {0, 1};
    for (int i = 2; i < length; i++)
    {
        int NewJacobsthal = jacobsthal[i - 1] + 2 * jacobsthal[i - 2];
        jacobsthal.push_back(NewJacobsthal);
    }
    return jacobsthal;
}

int main(int ac, char **av)
{
	std::vector<int> numbers = {7, 8, 27, 100, 11, 46, 2, 53};
	int size = numbers.size();

	std::cout << "unsorted array: ";
	for (int i = 0; i < size; i++)
	{
		std::cout << numbers[i] << " ";
	}
	std::cout << std::endl;
	
    // Elements are grouped into pairs, and the larger element in each pair is moved to the first position.
    // so we can sort them easier
    std::vector<std::pair<int, int> > pairs;
    for(int i = 0; i < size - 1; i +=2)
    {
        std::pair<int, int> pair = std::make_pair(numbers[i], numbers[i + 1]);
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
    for (std::vector<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it)
    {
        MainChain.push_back(it->first);
        Pend.push_back(it->second);
    }
    std::cout << std::endl;

    std::cout << "pairs of consecutive elements: ";
    for (std::vector<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it)
    {
        std::cout << "(" << it->first << ", " << it->second << ") ";
    }
    std::cout << std::endl;

    std::cout << "Main Chain: ";
	for (int i = 0; i < MainChain.size(); i++)
	{
		std::cout << MainChain[i] << " ";
	}
    std::cout << std::endl;

    std::cout << "Pend: ";
	for (int i = 0; i < Pend.size(); i++)
	{
		std::cout << Pend[i] << ", ";
	}
    std::cout << std::endl;
    std::cout << std::endl;



    // Generates a sequence of numbers used to determine the optimal insertion order for pend elements
    // J(n)=J(n−1)+2⋅J(n−2)
    std::vector<int> jacobsthal = generate_jacobsthal(Pend.size());

    



	std::cout << "sorted array: ";
	for (int i = 0; i < size; i++)
	{
		std::cout << numbers[i] << " ";
	}
}
