/* https://www.hackerrank.com/contests/smart-interviews/challenges/si-string-modulo

'''You are given 2 numbers N & P. Print N % P.

Input Format

First line of input contains T - number of test cases. Its followed by T lines, each line contains 2 numbers N and P, separated by space.

Constraints

20 points
1 <= T <= 100
1 <= N <= 1018
1 <= P <= 108

80 points
1 <= T <= 100
1 <= N <= 1010000
1 <= P <= 1015

Output Format

For each test case, print the value of N % P, separated by new line.

Sample Input 0

4
5 2
4 10
1085377843 81765943
8290826691135830692772803 95972011

Sample Output 0

1
4
22420584
60316167
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


unsigned long long mod(string s, unsigned long long b){
    unsigned long long res =0;
    for (long long i = 0; i <s.length(); i++ ){
        res = (res *10 + (int)s[i] - '0')%b;
    }
    return res;
}

int main() {
    int t ;
    cin >> t;
    for(int i =0; i < t; i++){
        string a;
        unsigned long long b;
        cin >> a >> b;
        cout <<mod(a, b) << endl;
    }
    return 0;
}

