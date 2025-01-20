#include <iostream>
#include <vector>

void    insertionSort(std::vector<int> &arr, int size)
{
    for (int i = 1; i < size; i++)
    {
        int key = arr[i];
        int j = i - 1; // start with element before key element to compare all the previous with key

        // arr[0 -1.. 1 -1.. 1-2....] while the previous elements are bigger than the current key keep moving them forward in the array
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        // if the array moved forward its going to put the element in its correct place
        // if not it will maintain the element in its origin place
        arr[j + 1] = key;
    }
}

int main()
{
    std::vector<int> numbers = {8, 3, 10, 2, 1, 9};
    int size = numbers.size();

    std::cout << "unsorted array: ";
	for (int i = 0; i < size; i++)
	{
		std::cout << numbers[i] << " ";
	}
    
    insertionSort(numbers, size);

    std::cout << std::endl;
    std::cout << "sorted array: ";
	for (int i = 0; i < size; i++)
	{
		std::cout << numbers[i] << " ";
	}
}