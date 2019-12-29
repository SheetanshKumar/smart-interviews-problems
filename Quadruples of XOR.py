# https://www.hackerrank.com/contests/smart-interviews/challenges/si-quadruples-of-xor/problem

'''You are given 4 arrays - A, B, C, D of integers. You have to find the number of quadruples (i, j, k, l) such that A[i]^B[j]^C[k]^D[l] = 0, where ^ is the bitwise XOR operator.

Input Format

First line of input contains T - number of test cases. Its followed by 5T lines, the first line contains N - the size of the array. The next 4 lines contains the elements of the arrays A, B, C and D respectively.

Constraints

10 points
1 <= T <= 100
1 <= N <= 20
1 <= A[i] <= 100

20 points
1 <= T <= 100
1 <= N <= 100
1 <= A[i] <= 100

70 points
1 <= T <= 100
1 <= N <= 500
1 <= A[i] <= 100

Output Format

For each test case, print the total number of quadruples, separated by new line.

Sample Input 0

3
4
31 8 28 10
18 7 22 5
16 25 20 14
39 9 34 19
2
27 21
39 40
64 77
36 5
8
49 73 58 30 72 44 78 23
9 40 65 92 42 87 3 27
29 40 12 3 69 9 57 60
33 99 78 16 35 97 26 12

Sample Output 0

2
0
36

Explanation 0

Test Case 1
There are only 2 quadruples with XOR=0: 28^22^25^19 and 28^5^16^9.

Test Case 2
None of the quadruples has XOR=0.'''

__author__ = "sheetansh"


def quadXor(a, b, c, d, n):
    ab = []
    cd = []
    mp = dict()
    count = 0
    for i in range(n):
        for j in range(n):
            ab.append(a[i] ^ b[j])
            cd.append(c[i] ^ d[j])
            try:
                mp[c[i] ^ d[j]] += 1
            except:
                mp[c[i] ^ d[j]] = 1
    for i in ab:
        try:
            count += mp[i]
        except:
            pass
    return count


for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    c = list(map(int, input().split()))
    d = list(map(int, input().split()))
    print(quadXor(a, b, c, d, n))
