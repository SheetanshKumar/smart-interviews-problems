# https://www.hackerrank.com/contests/smart-interviews/challenges/si-binary-strings-with-no-adjacent-1s/copy-from/1320024156

'''Find of number of binary strings of length N, such that there are no adjacent 1s in that string.

Input Format

First line of input contains T - number of test cases. Its followed by T lines, each line contains N - length of the binary string.

Constraints

1 <= T <= 100000
1 <= N <= 100000

Output Format

For each test case, print the number of binary strings of length N, separated by newline. Since the answer can be very large, print answer % 1e9+7.

Sample Input 0

5
3
11
7
5
500

Sample Output 0

5
233
34
13
73724597

Explanation 0

Test Case 1
You can construct the following binary strings of length 3 with no adjacent 1s:
000, 001, 010, 100, 101'''

_author_ = "sheetansh"

'''
for 4 ans is ansOf(3) + ansOf(2)
for 2 : 00, 10, 01 : ans->3
for 1 : 0, 1 : ans-> 2

for 3 : 000, 001, 100, 101,010 ->ansOf(2) + ans(1)

there will be 2 cases either append 0 at front or append 1
0 is valid for all so curnum + check where you can append 1 in front i.e where 
only 0 is there in front.
so here 0 can be appended to all i.e 5
1 can be appended to only 000, 001,010 i.e 3
so ans = 5+3.

Now check the series
'''

def getAll(n):
    res = [0, 2, 3]
    for i in range(3, n+1):
        res.append((res[i-1] + res[i-2])%1000000007)
    return res

res = getAll(10**5)

for _ in range(int(input())):
    print(res[int(input())])