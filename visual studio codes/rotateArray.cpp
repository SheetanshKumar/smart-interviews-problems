#include <iostream>
using namespace std;


void swap(int* a, int* b) {
	int temp = *a;
	*b = *a;
	*a = temp;
}

void reverse(int* arr, int low, int high) {
	while (low <= high) {
		cout << arr[low] << " " << arr[high] << endl;
		swap(arr[low], arr[high]);
		low++; high--;
	}
}

void rotate(int* arr, int n, int k) {
	k = k % n;
	if (k == 0)
		return;
	reverse(arr, 0, n - 1);
	reverse(arr, 0, k-1);
	reverse(arr, k, n - 1);
}

/*
int main()
{
	int n = 6;
	int arr[] = {1,2,3,4,5,6};
	int k = 1;
	rotate(arr, n, k);
	//reverse(arr, 0, n - 1);
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
}*/