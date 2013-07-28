#include <iostream>

template <class T>
void mergeSort(T* ioArray, int length)
{

	if (length <=1)
		return;

	// break array into two
	int m = length/2;

	// mergeSort two smaller lists
	mergeSort(ioArray, m);
	mergeSort(&ioArray[m], length-m);

	
	// merge the two lists
	int i=0, j=m, k=0;
	T tmpArray[length];
	while ((i<m) || (j<length))
	{
		// if i has reached the end
		if (i==m)
		{
			while(j<length)
			{
				tmpArray[k++] = ioArray[j++];
			}
		}
		// if j has reached the end
		if (j==length)
		{
			while (i<m)
			{
				tmpArray[k++] = ioArray[i++];
			}
		}

		if (ioArray[i] <= ioArray[j])
		{
			tmpArray[k++] = ioArray[i];
			++i;
		}
		else
		{
			tmpArray[k++] = ioArray[j];
			++j;
		}

	}

	// copy data from tmpArray to ioArray
	int p=0;
	while (p<length)
	{
		ioArray[p]=tmpArray[p++];
	}

}
