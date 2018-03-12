#include <chrono>
#include "sorts.h"

int main(int argc, char **argv)
{
	// If the parameter size does not match what is expected, the following message is displayed:
	if (argc != 4)
	{
		std::cout << "Use: ./programname number file_in file_out" << std::endl;
		std::cout << "Example: ./program 1 example.in out.txt" << std::endl;
		std::cout << "1: Selection Sort" << std::endl;
		std::cout << "2: Insertion Sort" << std::endl;
		std::cout << "3: Merge Sort" << std::endl;

		return 1;
	}

	// value of the vector/array
	long value;
	bool firstEntry = true;
	std::ifstream fileIn(argv[2], std::ios::in); // ./program number example.in
	std::vector<long> vec;

	// read the file
	while (fileIn >> value)
	{
		// firstentry/firstvalue = size of the vector
		if (firstEntry == true)
		{
			vec.reserve(value);
			firstEntry = false;
		}
		// insert the other values in the vector
		else
			vec.push_back(value);
	}
	fileIn.close();

	switch (atoi(argv[1]))
	{ //convert number string in long
	case 1:
	{ //Selection Sort

		std::cout << "Selection Sort selected, please wait a moment" << std::endl;

		// Start counting Time
		const auto start_time = std::chrono::steady_clock::now();
		selectionSort(vec);
		double time_in_milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start_time).count();
		// End counting Time

		std::cout << "Selection Sort Time Elapsed: " << time_in_milliseconds << " milliseconds" << std::endl;
		break;
	}
	case 2:
	{ //Insertion Sort

		std::cout << "Insertion Sort selected, please wait a moment" << std::endl;

		// Start counting Time
		const auto start_time = std::chrono::steady_clock::now();
		insertionSort(vec);
		double time_in_milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start_time).count();
		// End counting Time

		std::cout << "Insertion Sort Time Elapsed: " << time_in_milliseconds << " milliseconds" << std::endl;
		break;
	}
	case 3:
	{ //Merge Sort

		std::cout << "Merge Sort selected, please wait a moment" << std::endl;

		//Start counting Time
		const auto start_time = std::chrono::steady_clock::now();
		mergeSort(vec);
		double time_in_milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start_time).count();
		//End counting Time

		std::cout << "Merge Sort Time Elapsed: " << time_in_milliseconds << " milliseconds" << std::endl;
		break;
	}
	case 4:
	{ //Quick Sort

		std::cout << "Quick Sort selected, please wait a moment" << std::endl;

		//Start counting Time
		const auto start_time = std::chrono::steady_clock::now();
		quicksort(vec, 0, vec.size());
		double time_in_milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start_time).count();
		//End counting Time

		std::cout << "Quick Sort Time Elapsed: " << time_in_milliseconds << " milliseconds" << std::endl;
		break;
	}
	default:
	{
		return EXIT_FAILURE;
	}
	}

	std::ofstream output_file(argv[3]); //create an output file
	std::ostream_iterator<long> output_iterator(output_file, "\n");
	std::copy(vec.begin(), vec.end(), output_iterator); //copy the ordered values of the vector in the file

	return 0;
}