#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void printSpiral(int** arr, int n, int x, int y) {

	if (x >= n || y >= n)
		return;

	// first row
	for (int i = x; i < n; i++) {
		cout << arr[x][i] << " ";
	}
	// last col
	for (int i = x + 1; i < n; i++) {
		cout << arr[i][n - 1] << " ";
	}

	// last row
	if ((n - 1) != x)
		for (int i = n - 1; i >= y; i--) {
			cout << arr[n - 1][i] << " ";
		}

	//first col
	if ((n - 1) != y)
		for (int i = n - 2; i >= x; i--) {
			cout << arr[i][y] << " ";
		}
	printSpiral(arr, n - 1, x + 1, y + 1);
}

/*
int main() {
	int t;
	cin >> t;
	for (int x = 0; x < t; x++) {
		int n;
		cin >> n;
		int arr[n][n];
		//int** arr = (int** )malloc(sizeof(int*) * n);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> arr[i][j];
			}
		}

		printSpiral(arr, n, 0, 0);
		cout << endl;
	}
	return 0;
}
*/