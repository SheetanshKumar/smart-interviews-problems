/*Given n and r, compute nCr.
Do not use BigInteger class, it defeats the purpose of the problem statement.

Input Format

First line of input contains T - number of test cases. Its followed by T lines, each line contains 2 integers - N and R.

Constraints

20 points
1 <= T <= 100
0 <= N, R <= 30

80 points
1 <= T <= 500000
0 <= N, R <= 2000

Output Format

For each test case, print the value of nCr, separated by newline. Since the number can be very large, print result % 1000000007.

Sample Input 0

5
4 2
3 1
25 12
30 14
6 4

Sample Output 0

6
3
5200300
145422675
15

*/

#include <bits/stdc++.h>
using namespace std;

long long nCr(int n, int r){
    long long dp[r+1];
    memset(dp, 0, sizeof(dp));

    dp[0] =1;
    for(int i =0; i <= n; i++){
        for(int j = min(i, r); j > 0; j--)
            dp[j] = (dp[j] + dp[j-1]) % 1000000007;
    }
    return dp[r] % 1000000007;
}

int main() {
    int t;
    scanf("%d", &t);
    for(int i = 0 ; i < t; i++){
        int n, r;
        scanf("%d", &n);
        scanf("%d", &r);
        cout << nCr(n, r) << endl;
    }
}