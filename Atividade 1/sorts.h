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