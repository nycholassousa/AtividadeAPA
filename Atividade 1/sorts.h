#include <iostream>
#include <iterator>
#include <fstream>
#include <vector>
#include <stdlib.h>

void selectionSort(std::vector<int>& vec){
	int i, j, min;
	int unsorted;

	for (i = 0; i < vec.size() - 1; i++){
		min = i;
		for (j = i + 1; j < vec.size(); j++)
			if (vec[j] < vec[min])
				min = j;
		std::swap(vec[min], vec[i]);
	}
}

void insertionSort(std::vector<int>& vec){
	int i, j, unsorted;
	for (j = 1; j < vec.size(); ++j){
		unsorted = vec[j];
		for (i = j - 1; i >= 0 && vec[i] > unsorted; --i)
			vec[i + 1] = vec[i];
		vec[i + 1] =  unsorted;
	}
}