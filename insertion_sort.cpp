#include <iostream>
#include"sorting.h"

using namespace std;

void insertion_sort(int arr[], int length, int & count_comp, int & count_move) {

	int i, j, tmp;

	for (i = 1; i < length; i++) {
		j = i;
		count_comp++;
		while (j > 0 && arr[j - 1] > arr[j]) {
			tmp = arr[j];
			arr[j] = arr[j - 1];
			arr[j - 1] = tmp;
			j--;
			count_move++;
		}
	}
}