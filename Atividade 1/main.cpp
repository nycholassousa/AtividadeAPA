#include <chrono>
#include "sorts.h"

void selectionSort(std::vector<int>& vec);
void insertionSort(std::vector<int>& vec);

int main(int argc, char **argv){
	if (argc != 4){
		std::cout << "Use: ./programname number file_in file_out" << std::endl;
		std::cout << "Example: ./program 1 example.in out.txt" << std::endl;
		std::cout << "1: Selection Sort" << std::endl;
		std::cout << "2: Insertion Sort" << std::endl;

        return 1;
	}

	int value;
	bool firstEntry = true;
	std::ifstream fileIn (argv[2], std::ios::in); // ./program number example.in
	std::vector<int> vec;

	while(fileIn >> value){
		if (firstEntry == true){
			vec.reserve(value);
			firstEntry = false;
		}
		else
			vec.push_back(value);
	}
	fileIn.close();
	
	switch(atoi(argv[1])){
		case 1:{
			const auto start_time = std::chrono::steady_clock::now();
			selectionSort(vec);
			double time_in_milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>
  				(std::chrono::steady_clock::now() - start_time).count();
			std::cout << "Selection Sort Time Elapsed: " << time_in_milliseconds << " milliseconds" <<std::endl;
			break;
		}
		case 2:{
			const auto start_time = std::chrono::steady_clock::now();
			insertionSort(vec);
			double time_in_milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>
  				(std::chrono::steady_clock::now() - start_time).count();
			std::cout << "Insertion Sort Time Elapsed: " << time_in_milliseconds << " milliseconds" <<std::endl;
			break;
		}
		default:{
			return EXIT_FAILURE;
		}
	}

  	std::ofstream output_file(argv[3]);
    std::ostream_iterator<int> output_iterator(output_file, "\n");
    std::copy(vec.begin(), vec.end(), output_iterator);	

	return 0;
}