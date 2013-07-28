#include "QuickSortTemplate.h"

int main()
{
	char myArray[] = {'e', 'm', 'p', 'a', 'r'};

	quickSort<char>(myArray, 0, 4);

	std::cout << "Sorted array is:" << std::endl;
	for (int i=0; i<5; ++i)
	{
		std::cout << myArray[i] << "  ";
	}
	std::cout << std::endl;

	return 0;
}

