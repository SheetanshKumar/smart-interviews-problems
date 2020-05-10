#include <iostream>
using namespace std;

void merge(int arr[] , int low, int mid, int high) {
	int * temp = (int *) malloc(sizeof(int)*(high-low+1));
	int pt1 = low, pt2 = mid+1, i = 0;
	while (pt1 <= mid && pt2 <= high) {
		if (arr[pt1] < arr[pt2])
			temp[i++] = arr[pt1++];
		else
			temp[i++] = arr[pt2++];
	}
	while (pt1 <= mid) {
		temp[i++] = arr[pt1++];
	}
	while (pt2 <= high) {
		temp[i++] = arr[pt2++];
	}
	for (i = low; i <= high; i++) {
		arr[i] = temp[i - low];
	}

}

void mergeSort(int arr[], int low, int high) {
	if (low < high)
	{
		int mid = (low + high) / 2;
		mergeSort(arr, low, mid);
		mergeSort(arr, mid + 1, high);
		merge(arr, low, mid, high);
	}
}
/*
int main() {
	int arr[] = { 4, 5, 1, 1, 0, 510 };
	int n = sizeof(arr) / sizeof(int);
	mergeSort(arr, 0, n-1);
	for (int i = 0; i < n; i++)
		cout << arr[i] << "\t";
}
*/