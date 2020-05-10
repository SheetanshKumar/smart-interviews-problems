#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void maxSubArraySum(int* arr, int n)
{
	int max_so_far = -1000, max_ending_here = 0;
	int start = 0, end = 0, s = 0;

	for (int j = 0; j < n; j++)
	{
		max_ending_here += arr[j];

		if (max_so_far < max_ending_here)
		{
			max_so_far = max_ending_here;
			start = s;
			end = j;
		}

		if (max_ending_here < 0)
		{
			max_ending_here = 0;
			s = j + 1;
		}
	}
	cout << max_so_far << " " << start << " " << end << endl;
}
/*
int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int n;
		cin >> n;
		int arr[n];
		for (int j = 0; j < n; j++)
			cin >> arr[j];
		maxSubArraySum(arr, n);


	}
	return 0;
}
*/