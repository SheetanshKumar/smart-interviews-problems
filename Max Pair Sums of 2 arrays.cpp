/*
https://www.hackerrank.com/contests/smart-interviews/challenges/si-max-pair-sums-of-2-arrays/copy-from/1321920476
Given 2 integer arrays - A & B, you can create new elements of the form : A[i] + B[j] where 0<=i,j<=N-1. You have to print the highest K elements of the newly created elements.

Input Format

First line of input contains T - number of test cases. Its followed by 3T lines -
1. The first line contains N: the size of the arrays and K: the number of elements to print.
2. The second line contains N integers - the elements of A.
3. The third line contains N integers - the elements of B.

Constraints

40 points
1 <= T <= 100
1 <= N <= 102
1 <= K <= min(102, N*N)
-104 <= A[i],B[i] <= 104

60 points
1 <= T <= 100
1 <= N <= 103
1 <= K <= min(103, N*N)
-104 <= A[i],B[i] <= 104

100 points
1 <= T <= 100
1 <= N <= 104
1 <= K <= min(104, N*N)
-104 <= A[i],B[i] <= 104

Output Format

For each test case, print the highest K elements separated by space in a sorted order. Print new line between output of different test cases.

Sample Input 0

2
3 2
2 -5 14
-12 5 -3
5 5
-10 14 11 -5 12
16 -10 -3 13 11

Sample Output 0

19 11
30 28 27 27 25

Explanation 0

Test Case 1
You can form the following new elements:
2+(-12) = -10, 2+5 = 7, 2+(-3) = -1
(-5)+(-12) = -17, (-5)+5 = 0, (-5)+(-3) = -8
14+(-12) = 2, 14+5 = 19, 14+(-3) = 11
Top 2 elements = 19, 11*/

#include <bits/stdc++.h>
using namespace std;


void printKmaxSum( vector<int> &ar1, vector<int> &ar2, int n, int k){
    priority_queue<pair<int, pair<int, int>>> heap;

    heap.push(make_pair(ar1[n-1]+ar2[n-1], make_pair(n-1, n-1)));
    set<pair<int, int>> st;
    st.insert(make_pair(n-1, n-1));
    int i = n -1, j = n-1;
    while(k--){
        pair<int, pair<int, int>> obj = heap.top();
        cout << obj.first << " ";
        heap.pop();
        if(k==0)
            break;
        i = obj.second.first;
        j = obj.second.second;

        if(i-1 < 0 && j-1 < 0)
            break;
        if (i-1 >= 0 && st.find(make_pair(i-1, j)) == st.end())
        {
            heap.push(make_pair(ar1[i-1]+ar2[j], make_pair(i-1, j)));
            st.insert(make_pair(i-1, j));
        }
        if (j-1 >= 0 && st.find(make_pair(i, j-1)) == st.end())
        {
            heap.push(make_pair(ar1[i]+ar2[j-1], make_pair(i, j-1)));
            st.insert(make_pair(i, j-1));

        }

    }
    cout << endl;
}

int main() {

    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int n, k;
        cin >> n >>k;

        vector<int> ar1;
        vector<int> ar2;
        for(int j = 0; j<n ; j++)
        {
            int x;
            cin >> x;
            ar1.push_back(x);
        }
        for(int j = 0; j<n ; j++)
        {
            int x;
            cin >> x;
            ar2.push_back(x);
        }
        sort(ar1.begin(), ar1.begin()+n);
        sort(ar2.begin(), ar2.begin()+n);
        printKmaxSum(ar1, ar2, n, k);
    }
    return 0;
}
