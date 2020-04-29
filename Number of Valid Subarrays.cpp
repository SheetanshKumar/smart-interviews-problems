/*
https://www.hackerrank.com/contests/smart-interviews/challenges/si-number-of-valid-subarrays
You are given a array containing only 0s and 1s . You have to tell the number of subarrays which has equal number of 0s and 1s.

Input Format

First line of input contains T - number of test cases. Its followed by 2T lines - the first line contains N - the size of the array. The second line contains the elements of the array.

Constraints

40 points
1 <= T <= 100
1 <= N <= 100

60 points
1 <= T <= 100
1 <= N <= 1000

100 points
1 <= T <= 100
1 <= N <= 50000

Output Format

For each test case, output the number of subarrays having equal numer of 0s and 1s, separated by new line.

Sample Input 0

3
4
1 0 1 0
10
1 0 1 0 0 1 0 0 1 1
4
1 1 1 1

Sample Output 0

4
14
0

*/


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int countSubarr(int arr[], int n){
  map<int,int> mp;
  int sum=0;
  int count=0;
  for (int i = 0; i < n; i++) {
            if (arr[i] == 0)
                arr[i] = -1;

            sum += arr[i];
            if (sum == 0)
                count++;

            if (mp[sum])
                count += mp[sum];
            if(mp[sum]==0)
                mp[sum]=1;
            else
                mp[sum]++;

        }
  return count;
}

int main()
{
    int t = 0;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        int arr[n];
        for(int j = 0; j < n; j++){
            cin >> arr[j];
        }
        cout << countSubarr(arr, n) << endl;
    }
    return 0;
}
