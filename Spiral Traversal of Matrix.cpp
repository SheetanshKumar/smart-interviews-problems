//https://www.hackerrank.com/contests/smart-interviews/challenges/si-spiral-traversal-of-matrix/problem

/*
Given a 2D square matrix, print the matrix in a spiral order. Refer examples for more details. From interviews point of view, after you scan the matrix in a 2D array, try to print the matrix in a spiral order without using any extra space.

Input Format

First line of input contains T - number of test cases. First line of each test case contains N - size of the matrix [NxN]. Its followed by N lines each containing N integers - elements of the matrix.

Constraints

1 <= T <= 100
1 <= N <= 100
-100 <= ar[i][j] <= 100

Output Format

For each test case, print the matrix in a spiral order, separated by newline.

Sample Input 0

4
1
1
2
1 2
4 3
3
1 2 3
8 9 4
7 6 5
5
-44 25 -52 69 -5
17 22 51 27 -44
-79 28 -78 1 -47
65 -77 -14 -21 -6
-96 43 -21 -20 90

Sample Output 0

1
1 2 3 4
1 2 3 4 5 6 7 8 9
-44 25 -52 69 -5 -44 -47 -6 90 -20 -21 43 -96 65 -79 17 22 51 27 1 -21 -14 -77 28 -78


*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void printSpiral(int **arr, int n, int x, int y){

    if(x>=n || y>=n)
        return;

    // first row
    for(int i = x; i < n; i++){
        cout << arr[x][i] << " ";
    }
    // last col
    for(int i = x+1; i < n; i++){
        cout << arr[i][n-1] << " ";
    }

    // last row
    if((n-1) != x)
        for(int i = n-2; i >= y; i--){
            cout << arr[n-1][i] << " ";
        }

    //first col
    if((n-1) != y)
        for(int i = n-2; i> x; i-- ){
            cout << arr[i][y] << " ";
        }
    printSpiral(arr, n-1, x+1, y+1);
}

int main() {
    int t;
    cin >> t;
    for(int x = 0; x < t; x++){
        int n;
        cin >> n;
        int **arr=new int*[n];
        for (int i = 0; i < n; ++i)
        {
            arr[i] = new int[n];
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> arr[i][j];
            }
        }

        printSpiral(arr,n, 0,0);
        cout << endl;
    }
    return 0;
}