#include <vector>
#include <fstream>
#include<time.h>
#include"sorting.h"

typedef void(*sort_algo_type)(int array[], int length, int& count_comp, int & count_move);

void run_sort_algo(int array[], int length, sort_algo_type sorting, const char* algo_name, const char* data_file_name)
{
	int count_comparison = 0;
	int count_move = 0;
	clock_t start, end;
	start = clock();
	sorting(array, length, count_comparison, count_move);
	end = clock();
	//double duration = (double)(end - start) *1000 / CLOCKS_PER_SEC;
	long duration = end - start; // Just use clock cycles
	printf("Sorting algo summary, %s, %s, data size %d, count_comp %d, count_move %d, time %ld cycles\n", algo_name, data_file_name, length, count_comparison, count_move, duration);
	printf("Showing sorted result");
	for (int i = 0; i < length; i++)
		printf(", %d", array[i]);
	printf("\n");
}

int main(int argc, char** argv)
{
	// read the data
	if (argc < 2) //
	{
		printf("Usage: %s data_file_1 data_file_2 ...\n", argv[0]);
		exit(1);
	}

	const int num_files = argc - 1;
	std::vector<int> raw_data;

	for (int i = 0; i < num_files; i++)
	{
		const char* data_filename = argv[i + 1];
		std::ifstream infile(data_filename);
		// clear raw_data
		raw_data.clear();
		// assume one number per line
		int d;
		while (infile.good())
		{
			infile >> d;
			raw_data.push_back(d);
		}
		// Now run different sorting algos
		std::vector<int> tmp_data(raw_data.begin(), raw_data.end());
		run_sort_algo(&tmp_data[0], raw_data.size(), insertion_sort, "InsertionSort", data_filename);
		//overwrite tmp_data for another sorting
		tmp_data.assign(raw_data.begin(), raw_data.end());
		run_sort_algo(&tmp_data[0], raw_data.size(), merge_sort, "MergeSort", data_filename);
		// overwrite tmp_data for another sorting
		tmp_data.assign(raw_data.begin(), raw_data.end());
		run_sort_algo(&tmp_data[0], raw_data.size(), heap_sort, "HeapSort", data_filename);
		// overwrite tmp_data for another sorting
		tmp_data.assign(raw_data.begin(), raw_data.end());
		run_sort_algo(&tmp_data[0], raw_data.size(), quick_sort_sort, "QuickSort", data_filename);
	}
	system("pause");
	return 0;
}