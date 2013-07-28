#include <iostream>

template <class T>
void quickSort(T* array, int leftIdx, int rightIdx)
{
	if (!array || (rightIdx-leftIdx < 1))
	{
		return;
	}

	// partition
	int l = leftIdx, r = rightIdx;
	int pivot = l+(r-l)/2;

	// switch pivot with end element for now
	T pivotValue = array[pivot];
	array[pivot] = array[rightIdx];
	array[rightIdx] = pivotValue;
	--r;

	while (l<r)
	{
		while(array[l]<pivotValue)
			++l;
		while((l<r) && (array[r]>pivotValue))
			--r;
		if (l<r)
		{
			// swap them
			T tmp = array[l];
			array[l]=array[r];
			array[r]=tmp;
		}	

	}

	// swap back pivot (except in case there are two elements)
	if (pivotValue < array[r])
	{
		array[rightIdx] = array[r];
		array[r] = pivotValue;
	}

	quickSort(array, leftIdx, l);
	quickSort(array, l+1, rightIdx);

}

