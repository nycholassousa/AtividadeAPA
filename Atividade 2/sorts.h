#include <iostream>
#include <iterator>
#include <fstream>
#include <vector>
#include <stdlib.h>

// Selection Sort
/* How it works:
** The algorithm divides the input list longo two parts: the sublist of items already sorted, 
** which is built up from left to right at the front (left) of the list, and the sublist of 
** items remaining to be sorted that occupy the rest of the list. Initially, the sorted sublist 
** is empty and the unsorted sublist is the entire input list. The algorithm proceeds by finding 
** the smallest (or largest, depending on sorting order) element in the unsorted sublist, 
** exchanging (swapping) it with the leftmost unsorted element (putting it in sorted order), 
** and moving the sublist boundaries one element to the right.
*/
void selectionSort(std::vector<long> &vec)
{
	long i, j, min;
	long unsorted;

	for (i = 0; i < vec.size() - 1; i++)
	{
		// choose the first value
		min = i;
		for (j = i + 1; j < vec.size() - 1; j++)
		{
			//if the next value is smaller than the previous value
			if (vec[j] < vec[min])
			{
				//choose new position
				min = j;
			}
		}
		//swap values
		std::swap(vec[min], vec[i]);
	}
}

// Insertion Sort
/* How it works:
** Insertion sort iterates, consuming one input element each repetition, 
** and growing a sorted output list. At each iteration, insertion sort removes one element from the input data, 
** finds the location it belongs within the sorted list, and inserts it there. 
** It repeats until no input elements remain.
*/
void insertionSort(std::vector<long> &vec)
{
	long i, j, unsorted;
	for (j = 1; j < vec.size(); ++j)
	{
		//starting with second value of the vector
		unsorted = vec[j];
		//compare the previous value if it is not in the first position
		//and if the non-ordered value is less than the same
		for (i = j - 1; i >= 0 && vec[i] > unsorted; --i)
			vec[i + 1] = vec[i];
		vec[i + 1] = unsorted;
	}
}

void merge(std::vector<long>& vec, std::vector<long>& tmpArray, long leftPos, long rightPos, long rightEnd){
	long leftEnd = rightPos - 1;
	long tmpPos = leftPos;
	long numElements = rightEnd - leftPos + 1;

	while(leftPos <= leftEnd && rightPos <= rightEnd)
		if(vec[leftPos] <= vec[rightPos])
    		tmpArray[tmpPos++] = vec[leftPos++];
		else
    		tmpArray[tmpPos++] = vec[rightPos++];

	while(leftPos <= leftEnd)    // Copy rest of first half
		tmpArray[tmpPos++] = vec[leftPos++];

	while(rightPos <= rightEnd)  // Copy rest of right half
		tmpArray[tmpPos++] = vec[rightPos++];

	for(int i = 0; i < numElements; i++, rightEnd--)
		vec[rightEnd] = tmpArray[rightEnd];
}

void sort(std::vector<long>& vec, std::vector<long>& tmpArray, long left, long right ){
	if( left < right ){
		long center = ( left + right ) / 2;
		sort( vec, tmpArray, left, center );
		sort( vec, tmpArray, center + 1, right );
		merge( vec, tmpArray, left, center + 1, right );
	}
}

void mergeSort(std::vector<long>& vec){
	long size = vec.size();
	std::vector<long> tmpArray(size);
	sort(vec, tmpArray, 0, size - 1);
}

int partition(std::vector<long>& vec, int begin, int end, int who){
	for (int i = begin; i < end; ++i){
		if (vec[i] <= who){
			std::swap(vec[i], vec[begin]);
			begin++;
		}
	}
	return begin - 1;
}

void quicksort(std::vector<long>& vec, int begin, int end){
	if (begin >= end)
		return;

	int middle = begin + (end - begin)/2;
	std::swap(vec[middle], vec[begin]);

	int midpoint = partition(vec, begin + 1, end, vec[begin]);
	std::swap(vec[begin], vec[midpoint]);
	quicksort(vec, begin, midpoint);
	quicksort(vec, midpoint + 1, end);
}