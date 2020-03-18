/*
https://www.hackerrank.com/contests/smart-interviews/challenges/si-min-cost-to-connect-rods/

You are given the lengths of N rods. You want to connect all the rods to form a single rod. The cost of connecting 2 rods of lengths: L1 and L2 is L1+L2. The resultant rod will also be of size L1+L2. Your task is to find the minimum cost to connect all the rods.

Input Format

First line of input contains T - number of test cases. Its followed by 2T lines, first line of each test case contains N - the number of rods. The next line contains N integers - the lengths of the rods.

Constraints

30 points
1 <= T <= 100
1 <= N <= 1000
1 <= L[i] <= 1000

70 points
1 <= T <= 500
1 <= N <= 10000
1 <= L[i] <= 1000

Output Format

For each test case, print the minimum cost to connect all the rods, separated by newline.

Sample Input 0

3
3
3 1 4
2
1 2
4
4 3 2 6

Sample Output 0

12
3
29

Explanation 0

Self Explanatory*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int connectRods(vector<int> &arr, int n){
    priority_queue <int, vector<int>, greater<int> > heap;

    for (int i =0; i < n; i++)
        heap.push(arr[i]);
    int res = 0;
    while(!heap.empty())
    {
        int temp = heap.top();
        heap.pop();
        if(heap.empty())
            return res;

        temp += heap.top();
        heap.pop();
        res+=temp;
        heap.push(temp);
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int n;
        cin >> n;
        vector<int> arr;
        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            arr.push_back(x);
        }
        cout << connectRods(arr, n) << endl;
    }
    return 0;
}
