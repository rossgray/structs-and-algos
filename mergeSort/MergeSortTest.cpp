#include "MergeSortTemplate.h"
#include "../quickSort/QuickSortTemplate.h"

int main()
{
	const int length = 9;
	int myArray[length] = {6, 5, 9, 12, 1, 4, 14, 7, 3};
	int myArray2[length];
	// copy array
	int p=0;
	while (p<length)
	{
		myArray2[p++] = myArray[p];
	}


	quickSort<int>(myArray, 0, length-1);
	mergeSort<int>(myArray2, length);

	std::cout << "quickSorted array is:" << std::endl;
	for (int i=0; i<length; ++i)
	{
		std::cout << myArray[i] << "  ";
	}
	std::cout << std::endl;

        std::cout << "mergeSorted array is:" << std::endl;
	for (int i=0; i<length; ++i)
	{
		std::cout << myArray2[i] << "  ";
	}
	std::cout << std::endl;

	return 0;
}

