#include "PmergeMe.hpp"

void loadData(std::vector<int>& vec, std::list<int>& lst, char** av, int ac) 
{
    if (ac == 1)
    {
        exit(1);
    }
    // easier reading and parsing using strstream
    std::stringstream ss;
    for (int i = 1; i < ac; i++)
        ss << av[i] << " ";

    std::string token;
    while (ss >> token)
    {
        try 
        {
            // stoi automaticly throws exceptions for invalid non numeric numbers and out of range
            // so all we gotta do is catch them ;)
            int number = std::stoi(token);
            if (number < 0)
            {
                std::cerr << "Error" << std::endl;
                exit(1);
            }
            vec.push_back(number);
            lst.push_back(number);
            
        } 
        catch (const std::invalid_argument& e) 
        {
            std::cerr << "Error" << std::endl;
            exit(1);
        } 
        catch (const std::out_of_range& e)
        {
            std::cerr << "Error" << std::endl;
            exit(1);
        }
    }
}

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

void quicksort(std::vector<std::pair<int, int> > &pairs, int low, int high)
{
    if (low < high)
    {
        int pi = partition(pairs, low, high);
        quicksort(pairs, low, pi - 1);
        quicksort(pairs, pi + 1, high);
    }
}

std::vector<int> generate_jacobsthal(int max_needed)
{
    std::vector<int> jacobsthal;

    // jacobsthal[0, 1]
    jacobsthal.push_back(0);
    jacobsthal.push_back(1);

    // Generate until the last term exceeds max_needed
    while ((int)jacobsthal.back() <= max_needed && (int)jacobsthal.size() < max_needed)
    {
        int next = jacobsthal[jacobsthal.size() - 1] + 2 * jacobsthal[jacobsthal.size() - 2];
        jacobsthal.push_back(next);
    }

    return jacobsthal;
}

std::vector<int> insert_order_jaco(int pend_size) {
    std::vector<int> jacob_sequence = generate_jacobsthal(pend_size);
    std::vector<int> insertion_order;

    // Step 1: Add Jacobsthal-derived indices (largest first)
    for (int i = jacob_sequence.size() - 1; i >= 0; --i) {
        int j = jacob_sequence[i];
        if (j <= pend_size && j > 0) {
            int index = j - 1;
            if (std::find(insertion_order.begin(), insertion_order.end(), index) == insertion_order.end()) {
                insertion_order.push_back(index);
            }
        }
    }
    // Step 2: Add remaining indices in reverse order
    for (int i = pend_size - 1; i >= 0; --i) {
        if (std::find(insertion_order.begin(), insertion_order.end(), i) == insertion_order.end()) {
            insertion_order.push_back(i);
        }
    }

    return insertion_order;
}

int binary_search(const std::vector<int> &arr, int target)
{
    int low = 0, high = arr.size() - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] < target)
        {
            low = mid + 1;
        }
        else 
        {
            high = mid - 1;
        }
    }
    return low;
}

void insert_pend(std::vector<int> &main_chain, const std::vector<int> &pend, const std::vector<int> &insertion_order)
{
    for (std::vector<int>::const_iterator it = insertion_order.begin(); it != insertion_order.end(); ++it)
    {
        int index = *it;
        if (index >= 0 && index < (int)pend.size())
        {
            int element = pend[index];

            // insert elements based on insertion order using binary search to minimize comparisions
            int pos = binary_search(main_chain, element);
            main_chain.insert(main_chain.begin() + pos, element);
        }
    }
}

void ford_johnson_vector(std::vector<int>& vector) {

    int size = vector.size();
    if (size <= 1) return;

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
    std::vector<std::pair<int, int> > pairs;
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
    for (std::vector<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it)
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
    for (size_t i = 0; i < vector.size(); ++i) std::cout << vector[i] << " ";
    std::cout << std::endl;

    // inesrt first pend element into main chain
    // insert pend elements into main chain using insertion order + binary search
    insert_pend(MainChain, Pend, insertion_order);

    if (struggler != -1)
    {
        int pos = binary_search(MainChain, struggler);
        MainChain.insert(MainChain.begin() + pos, struggler);
    }
    vector = MainChain;
}

void ford_johnson_list(std::list<int>& lst) {
    if (lst.size() <= 1) return;

    // struggler typeshit
    std::list<int>::iterator it = lst.begin();
    int struggler = -1;
    if (lst.size() % 2 != 0) {
        std::advance(it, lst.size() - 1);
        struggler = *it;
        lst.erase(it);
    }

    //  pairs typeshit
    std::list<std::pair<int, int> > pairs;
    for (it = lst.begin(); it != lst.end();) {
        int a = *it++;
        int b = *it++;
        if (a < b) std::swap(a, b);
        pairs.push_back(std::make_pair(a, b));
    }

    // sort pairs by first element
    pairs.sort();

    // Build main chain and pend
    std::list<int> main_chain, pend;
    for (std::list<std::pair<int, int> >::iterator pit = pairs.begin(); pit != pairs.end(); ++pit) {
        main_chain.push_back(pit->first);
        pend.push_back(pit->second);
    }

    // Insert first pend element if needed
    if (!pend.empty() && pend.front() <= main_chain.front()) {
        main_chain.push_front(pend.front());
        pend.pop_front();
    }

    // generate insertion order
    std::vector<int> order = insert_order_jaco(pend.size());

    // insert pend elements
    std::list<int>::iterator pend_it = pend.begin();
    for (size_t i = 0; i < order.size(); ++i) {
        // Move pend_it to the correct position
        std::advance(pend_it, order[i] - (i > 0 ? order[i - 1] + 1 : 0));
        int element = *pend_it;

        // find insertion position in main_chain using binary search.
        // i used lower_bound cuz i dont want to implement binary search using linked list cuz am lazy and most important
        // cuz lower_bound undercover already is using binary search
        std::list<int>::iterator pos = std::lower_bound(main_chain.begin(), main_chain.end(), element);

        // insert the element
        main_chain.insert(pos, element);
    }

    // insert struggler
    if (struggler != -1) {
        std::list<int>::iterator pos = std::lower_bound(main_chain.begin(), main_chain.end(), struggler);
        main_chain.insert(pos, struggler);
    }

    lst = main_chain;
}
