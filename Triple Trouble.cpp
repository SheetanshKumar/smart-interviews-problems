//https://www.hackerrank.com/contests/smart-interviews/challenges/si-triple-trouble/submissions/code/1318473932

/*
Given an array of size 3X+1, where every element occurs three times, except one element, which occurs only once. Find the element that occurs only once.

Input Format

First line of input contains T - number of test cases. Its followed by 2T lines, the first line contains N - the size of the array (of the form 3X + 1) and second line contains the elements of the array.

Constraints

1 <= T <= 300
1 <= N <= 104
1 <= A[i] <= 109

Output Format

For each test case, print the number which occurs only once, separated by new line.

Sample Input 0

2
10
5 7 8 7 7 5 5 9 8 8
7
10 20 20 30 20 10 10

Sample Output 0

9
30

*/


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool checkBits(int n, int b){
    return ((1<<b)&n) != 0;
}

int tripleTrouble(int * arr, int n){
    int ans = 0;

    for(int b = 0; b <= 30; b++){
        int count = 0;
        for (int i = 0; i < n; i++){
            if(checkBits(arr[i], b))
               count++;
        }
        if(count % 3 != 0)
               ans += (1<<b);
    }
    return ans;
}

int main() {
   int t ;
    cin >> t;

    for (int i =0; i < t; i++)
    {
        int n;
        cin >> n;
        int arr[n];
        for(int j = 0; j < n; j++){
            cin >> arr[j];
        }
        cout << tripleTrouble(arr, n) << endl;
    }
    return 0;
}
