#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <vector>

void merge(std::vector<int> &arr, int left, int mid, int right)
{
	// Correct calculation
    int len1 = mid - left + 1;
	int len2 = right - mid;

	std::vector<int> L(len1), R(len2);

	for (int i = 0; i < len1; i++)
	{
		L[i] = arr[left + i];
		std::cout <<"element " << i << " in left subarray: " << L[i] << std::endl;
	}
	std::cout << "------------------\n";
	for (int i = 0; i < len2; i++)
	{
		R[i] = arr[mid + 1 + i];
		std::cout <<"element " << i << " in right subarray: " << R[i] << std::endl;
	}
	std::cout << ">>>>>>>>>>>>>>>>>>>\n";

	// comparing both lists
	int i = 0;
	int j = 0;
	int k = left; // starting point of sorting
	while (i < len1 && j < len2)
	{
		// we can add = to make sure it puts repititive numbers together
		if (L[i] < R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else if (R[j] < L[i])
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	// put the remaining in the arr
	while (i < len1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}
	
	while (j < len2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}

}

void	mergeSort(std::vector<int> &arr, int left, int right)
{
	if (left >= right)
		return;

	int mid = left + (right - left) / 2;
	
	mergeSort(arr, left, mid);
	mergeSort(arr, mid + 1, right);
	merge(arr, left, mid, right);
}

int main(int ac, char **av)
{
	std::vector<int> numbers = {4, 2, 10, 6, 3, 15, 92, 100};
	int size = numbers.size();

	std::cout << "unsorted array: ";
	for (int i = 0; i < size; i++)
	{
		std::cout << numbers[i] << " ";
	}
	std::cout << std::endl;
	mergeSort(numbers, 0, size - 1);

	std::cout << "sorted array: ";
	for (int i = 0; i < size; i++)
	{
		std::cout << numbers[i] << " ";
	}
}


/* merge sort logic:
	if the size of array is 0 or 1 return else continue splitting the array into two halves
	find middle index of an array
	recursively apply merge sort function to the first half of the array (0 - middle)
	recursively apply merge sort function to the second half of the array (middle - end)
	merge:
		place the the two halves into two temporary arrays
		compare the two halves and place the lower element into the original array and keep doing so by order
			while comparing between the two halves whenever an element is placed into og array move forward the index of the choosen from array
		put the rest into the original array(the rest always going to be sorted)
*/ 
