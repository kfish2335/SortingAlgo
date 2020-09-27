#include <iostream>
#include"sorting.h"

using namespace std;

void MaxHeapify(int arr[], int i, int n, int & count_comp) {

	int largest = i;
	int l = 2 * i + 1; 
	int r = 2 * i + 2;
	int temp;
	
	if (r < n && arr[r] > arr[largest])
		largest = r;
	 
	if (l < n && arr[l] > arr[largest])
		largest = l;

	
	if (largest != i){
			temp = arr[i];
			arr[i] = arr[largest];
			arr[largest] = temp;
			MaxHeapify(arr, largest, n, count_comp);
		}
}

void Build_MaxHeap(int arr[], int n, int & count_comp)
{
	for (int i = n / 2 -1; i >= 0; i--) {
		MaxHeapify(arr, i, n, count_comp);
	}
}

void heap_sort(int arr[], int length, int & count_comp, int & count_move)
{
	int temp;
	Build_MaxHeap(arr, length, count_comp);
	for (int i = length-1; i >= 0; i--)
	{
		count_move++;
			
		temp = arr[i];
		arr[i] = arr[0];
		arr[0] = temp;
		
		MaxHeapify(arr, 0, i , count_comp);
	}
}

