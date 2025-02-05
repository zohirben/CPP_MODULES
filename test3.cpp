#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <vector>
#include <utility>
#include <cmath>

int partition(std::vector<std::pair<int, int> > &pairs, int low, int high) {
    int pivot = pairs[high].first;
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (pairs[j].first <= pivot) {
            ++i;
            std::swap(pairs[i], pairs[j]);
        }
    }
    std::swap(pairs[i + 1], pairs[high]);
    return i + 1;
}

void quicksort(std::vector<std::pair<int, int> > &pairs, int low, int high) {
    if (low < high) {
        int pi = partition(pairs, low, high);
        quicksort(pairs, low, pi - 1);
        quicksort(pairs, pi + 1, high);
    }
}

std::vector<int> generate_jacobsthal(int length) {
    std::vector<int> jacobsthal;
    if (length > 0) jacobsthal.push_back(0);
    if (length > 1) jacobsthal.push_back(1);
    std::cout << "jacobsthal: ";
    // we gonna start from 3 since we already pushed the first pend 
    // this will cause the duplicate problem if we didnt handle it
    for (int i = 3; i < length; i++) {
        int NewJacobsthal = jacobsthal[i - 1] + 2 * jacobsthal[i - 2];
        std::cout << NewJacobsthal << ", ";
        jacobsthal.push_back(NewJacobsthal);
    }
    std::cout << std::endl;
    return jacobsthal;
}

std::vector<int> insert_order_jaco(int length) {
    std::vector<int> jacob_sequence = generate_jacobsthal(length);
    std::vector<int> insertion_order;

    // Start from the largest Jacobsthal number <= length and work backward
    for (int i = jacob_sequence.size() - 1; i > 0; --i) {
        int j = jacob_sequence[i];
        if (j <= length && j > 0) {
            insertion_order.push_back(j - 1);
        }
    }

    // Add remaining indices in reverse order
    for (int i = length - 1; i >= 0; --i) {
        bool exists = false;
        for (int k = 0; k < insertion_order.size(); ++k) {
            if (insertion_order[k] == i) {
                exists = true;
                break;
            }
        }
        if (!exists) {
            insertion_order.push_back(i);
        }
    }

    std::cout << "insertion order: ";
    for (int i = 0; i < insertion_order.size(); i++) {
       std::cout << insertion_order[i] << " ";
    }
    std::cout << std::endl;
    return insertion_order;
}

int binary_search(const std::vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return low;
}

void insert_pend(std::vector<int>& main_chain, const std::vector<int>& pend, const std::vector<int>& insertion_order) {
    for (std::vector<int>::const_iterator it = insertion_order.begin(); it != insertion_order.end(); ++it) {
        int index = *it;
        if (index >= 0 && index < (int)pend.size()) {
            int element = pend[index];
            std::cout << "element: " << element << std::endl;

            int pos = binary_search(main_chain, element);
            std::cout << "pos: " << pos << std::endl;
            main_chain.insert(main_chain.begin() + pos, element);
            std::cout << "main chain array: ";
    for (int i = 0; i < main_chain.size(); i++) {
       std::cout << main_chain[i] << " ";
    }
    std::cout << std::endl;
        }
    }
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
	

    // create a struggler so that we store the last element in it if the array size is odd
    // so we can make sorting easier
    int struggler = -1;
    if (size % 2 != 0)
    {
        struggler = numbers[size - 1];
        numbers.pop_back();
        size--;
    }

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
    // The Jacobsthal sequence is used to determine the optimal order for inserting pend elements into the main chain
    // J(n)=J(n−1)+2⋅J(n−2)
    // then use that sequence to determine the shortest order to sort the pend into main chain using binary searchd
    std::vector<int> insertion_order = insert_order_jaco(Pend.size());
    
    // insert pend elements into main chain using insertion order + binary search
    insert_pend(MainChain, Pend, insertion_order);

	std::cout << "insertion order array: ";
	for (int i = 0; i < insertion_order.size(); i++)
	{
		std::cout << insertion_order[i] << " ";
	}
    std::cout << std::endl;

    std::cout << "sorted array: ";
    for (int i = 0; i < MainChain.size(); i++) {
       std::cout << MainChain[i] << " ";
    }
    std::cout << std::endl;
}
