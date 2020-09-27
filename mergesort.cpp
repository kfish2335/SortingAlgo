#include <iostream>
#include"sorting.h"

using namespace std;

void Merger(int arr[], int lo, int  mi, int hi, int & count_move) {
	int *temp = new int[hi - lo + 1];
	int i = lo, j = mi + 1;
	int k = 0;
	while (i <= mi && j <= hi) {
		count_move++;
		if (arr[i] <= arr[j])
			temp[k++] = arr[i++];
		else
			temp[k++] = arr[j++];
	}
	while (i <= mi) {
		count_move++;
		temp[k++] = arr[i++];
	}
	while (j <= hi) {
		count_move++;
		temp[k++] = arr[j++];
	}
	for (k = 0, i = lo; i <= hi; ++i, ++k)
		arr[i] = temp[k];

	delete[]temp;
}
void MergeSort(int arr[], int lo, int hi, int & count_comp, int & count_move) {
	int mid;
	count_comp++;
	if (lo < hi) {
		mid = (lo + hi) >> 1;
		MergeSort(arr, lo, mid, count_comp, count_move);
		MergeSort(arr, mid + 1, hi, count_comp, count_move);
		Merger(arr, lo, mid, hi, count_move);
	}
}
void merge_sort(int arr[], int length, int & count_comp, int & count_move) {
	MergeSort(arr, 0, length - 1, count_comp, count_move);
}