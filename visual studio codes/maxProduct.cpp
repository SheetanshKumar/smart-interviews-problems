// C++ program to find Maximum Product Subarray 
#include <iostream> 
#include <algorithm>
using namespace std;

/* Returns the product of max product subarray.
Assumes that the given array always has a subarray
with product more than 1 */
int maxSubarrayProduct(int arr[], int n)
{
	int max_ending_here = 1;
	int start = 0;
	int end = 0;
	int ans = 0;
	int min_ending_here = 1;

	int max_so_far = 1;
	int flag = 0;

	for (int i = 0; i < n; i++) {
		if (arr[i] > 0) {
			max_ending_here = max_ending_here * arr[i];
			min_ending_here = min(min_ending_here * arr[i], 1);
			flag = 1;
			end = i;
		}

		else if (arr[i] == 0) {
			start = i;
			end = i;
			max_ending_here = 1;
			min_ending_here = 1;
		}

		else {
			int temp = max_ending_here;
			if (min_ending_here * arr[i] > 1) {
				max_ending_here = min_ending_here * arr[i];
			} 
			else{
				max_ending_here = 1;
			}
			//max_ending_here = max(min_ending_here * arr[i], 1);
			min_ending_here = temp * arr[i];
		}
		if (max_so_far < max_ending_here)
		{
			max_so_far = max_ending_here;
			ans = max(end - start, ans);
		}
			
	}
	if (flag == 0 && max_so_far == 1)
		return 0;
	return ans;
}

// Driver code 
/*
int main()
{
	int arr[] = { 2, -3, 5};
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "Maximum Sub array product is "
		<< maxSubarrayProduct(arr, n);
	return 0;
}
*/
// This is code is contributed by rathbhupendra 
