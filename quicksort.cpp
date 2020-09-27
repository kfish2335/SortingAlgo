#include <iostream>
#include"sorting.h"

using namespace std;

void quick_sort(int arr[], int left, int right, int & count_comp, int & count_move) {

	int i = left, j = right;
	int tmp;
	int pivot = arr[(left + right) / 2];
	

	while (i <= j) {
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;
		if (i <= j) {
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i++;
			j--;
			count_move++;
		}
	};

	if (left < j)
		quick_sort(arr, left, j, count_comp, count_move);
	if (i < right)
		quick_sort(arr, i, right, count_comp, count_move);
}
void quick_sort_sort(int arr[], int length, int & count_comp, int & count_move) {
	quick_sort(arr, 0, length - 1, count_comp, count_move);
}