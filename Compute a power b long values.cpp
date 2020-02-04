// https://www.hackerrank.com/contests/smart-interviews/challenges/si-compute-a-power-b/submissions/code/1318358439

/*Given 2 numbers - a and b, evaluate ab.

Input Format

First line of input contains T - number of test cases. Its followed by T lines, each line containing 2 numbers - a and b, separated by space.

Constraints

30 points
1 <= T <= 1000
0 <= a <= 106
0 <= b <= 103

70 points
1 <= T <= 1000
0 <= a <= 106
0 <= b <= 109

Output Format

For each test case, print ab, separated by new line. Since the result can be very large, print result % 1000000007

Sample Input 0

4
5 2
1 10
2 30
10 10

Sample Output 0

25
1
73741817
999999937*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long aPowerb(long long x, long long y){
    if (y== 0)
        return 1;
    long long store = aPowerb(x, y/2);
    if(y%2 == 0)
        return ((store%1000000007)*(store)%1000000007)%1000000007;
    else
        return (x*((store%1000000007)*(store)%1000000007)%1000000007)%1000000007;
}


int main() {

    int t;
    cin >> t;
    for(int i=0 ; i < t; i++)
    {
        long long x;
        long long y;
        cin >> x >> y;
        long long result = aPowerb(x, y);
        printf("%lld\n", result%1000000007);
    }
    return 0;
}
