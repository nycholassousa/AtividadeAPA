#include <stdlib.h>
#include <climits>
#include <iostream>
#include <iterator>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>

/*************************************************/
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
/*************************************************/
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
/*************************************************/
// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(std::vector<long> &vec, std::vector<long> &tmpArray, long leftPos, long rightPos, long rightEnd)
{
	long leftEnd = rightPos - 1; //Initial index of first subarray
	long tmpPos = leftPos;		 //Initial index of second subarray
	long numElements = rightEnd - leftPos + 1;

	/* Merge the temp arrays back into arr[l..r]*/
	while (leftPos <= leftEnd && rightPos <= rightEnd)
		if (vec[leftPos] <= vec[rightPos])
			tmpArray[tmpPos++] = vec[leftPos++];
		else
			tmpArray[tmpPos++] = vec[rightPos++];

	/* Copy the remaining elements of L[], if there are any */
	while (leftPos <= leftEnd) // Copy rest of first half
		tmpArray[tmpPos++] = vec[leftPos++];

	/* Copy the remaining elements of R[], if there are any */
	while (rightPos <= rightEnd) // Copy rest of right half
		tmpArray[tmpPos++] = vec[rightPos++];

	for (int i = 0; i < numElements; i++, rightEnd--)
		vec[rightEnd] = tmpArray[rightEnd];
}

/*
If r > l
     1. Find the middle point to divide the array into two halves:  
             middle m = (l+r)/2
     2. Call mergeSort for first half:   
             Call mergeSort(arr, l, m)
     3. Call mergeSort for second half:
             Call mergeSort(arr, m+1, r)
     4. Merge the two halves sorted in step 2 and 3:
             Call merge(arr, l, m, r)
*/

void sort(std::vector<long> &vec, std::vector<long> &tmpArray, long left, long right)
{
	if (left < right)
	{
		long center = (left + right) / 2;

		// Sort first and second halves
		sort(vec, tmpArray, left, center);
		sort(vec, tmpArray, center + 1, right);

		merge(vec, tmpArray, left, center + 1, right);
	}
}

//Call merge sort using vector
void mergeSort(std::vector<long> &vec)
{
	long size = vec.size();
	std::vector<long> tmpArray(size);
	sort(vec, tmpArray, 0, size - 1);
}

/*************************************************/
//partition
int partition(std::vector<long> &vec, int begin, int end, int who)
{
	for (int i = begin; i < end; ++i)
	{
		// If current element is smaller than or equal to pivot
		if (vec[i] <= who)
		{ //who == pivot
			std::swap(vec[i], vec[begin]);
			begin++; // increment index of smaller element, to not test with him again
		}
	}
	return begin - 1;
}

void quicksort(std::vector<long> &vec, int begin, int end)
{
	if (begin >= end)
		return;

	int middle = begin + (end - begin) / 2;
	std::swap(vec[middle], vec[begin]); //send pivot to begin

	int midpoint = partition(vec, begin + 1, end, vec[begin]); //set midpoint
	std::swap(vec[begin], vec[midpoint]);					   //send pivot to correct location after tests
	quicksort(vec, begin, midpoint);
	quicksort(vec, midpoint + 1, end);
}

/*************************************************/
void maxHeapify(std::vector<long> &vec, long pos, long n)
{
	long right = 2 * pos + 1;

	if (right < n)
	{
		if ((right + 1) < n && vec[right] < vec[right + 1])
			++right;
		if (vec[right] > vec[pos])
		{
			std::swap(vec[right], vec[pos]);
			maxHeapify(vec, right, n);
		}
	}
}

void heapsort(std::vector<long> &vec)
{
	long size = vec.size();

	for (long i = size / 2 - 1; i >= 0; --i)
		maxHeapify(vec, i, size);

	std::vector<long>::reverse_iterator elem;

	for (elem = vec.rbegin(); elem != vec.rend(); elem++)
	{
		std::iter_swap(elem, vec.begin());
		maxHeapify(vec, 0, --size);
	}
}

/*************************************************/
void countsort(std::vector<long> &vec)
{
	int max = vec[0];
	int min = vec[0];

	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i] > max)
			max = vec[i];
		if (vec[i] < min)
			min = vec[i];
	}

	std::vector<long> aux(max - min + 1);
	std::fill(aux.begin(), aux.end(), 0);

	for (int i = 0; i < vec.size(); i++)
	{
		aux[vec[i] - min]++;
	}
	for (int i = 1; i < aux.size(); i++)
	{
		aux[i] = aux[i] + aux[i - 1];
	}

	std::vector<long> temp(vec.size());
	for (int i = vec.size() - 1; i >= 0; i--)
	{
		temp[aux[vec[i] - min] - 1] = vec[i];
		aux[vec[i] - min]--;
	}

	vec.assign(temp.begin(), temp.end());
}