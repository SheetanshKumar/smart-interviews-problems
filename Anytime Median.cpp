/*https://www.hackerrank.com/contests/smart-interviews/challenges/si-anytime-median/copy-from/1320695506
Given an integer array, print the median for the sub-array 0 to i, for every i, 0<=i<=N-1.

Input Format

First line of input contains T - number of test cases. Its followed by 2T lines - the first line contains N - the size of the array. The second line contains N integers - the elements of the array.

Constraints

30 points
1 <= T <= 100
1 <= N <= 103

70 points
1 <= T <= 100
1 <= N <= 104

General Constraints
-104 <= A[i] <= 104

Output Format

For each test case, print the median for the sub-array 0 to i, for every i, separated by space. Print new line between output of different test cases.
Note: In case of even length sub-array, print the smaller element as the median.

Sample Input 0

2
5
-10 14 11 -5 7
3
2 -5 14

Sample Output 0

-10 -10 11 -5 7
2 -5 2


*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;


void printMedian(int * arr, int n){
    priority_queue <int, vector<int>, greater<int>> minHeap;
    priority_queue <int> maxHeap;
    maxHeap.push(arr[0]);
    cout << maxHeap.top()<< " ";
    for (int i = 1; i<n; i++){
        if (arr[i] <= maxHeap.top()){
            maxHeap.push(arr[i]);
            if(maxHeap.size() - minHeap.size() >1){
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }
        }
     else if(arr[i] > maxHeap.top()){
         minHeap.push(arr[i]);
         if(minHeap.size() > maxHeap.size())
         {
             maxHeap.push(minHeap.top());
             minHeap.pop();
         }
     }
    cout << maxHeap.top() << " ";
    }
}

int main() {
    int t;
    cin >> t;

    for(int i = 0 ; i < t; i++){
        int n;
        cin >> n;
        int arr[n];
        for(int j = 0; j < n; j++)
            cin>>arr[j];
        printMedian(arr, n);
        cout << endl;
    }
}
