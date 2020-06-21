'''
Check Subsequence
https://www.hackerrank.com/contests/smart-interviews-16b/challenges/si-check-subsequence/submissions/code/1324385337
Given 2 strings A and B, check if A is present as a subsequence in B.

Input Format

First line of input contains T - number of test cases. Its followed by T lines, each line contains 2 space separated strings - A and B.

Constraints

1 <= T <= 1000
1 <= len(A), len(B) <= 1000
'a' <= A[i],B[i] <= 'z'

Output Format

For each test case, print "Yes" if A is a subsequence of B, "No" otherwise, separated by new line.

Sample Input 0

2
data gojdaoncptdhzay
algo plabhagqogxt

Sample Output 0

Yes
No


'''

for _ in range(int(input())):
    a, b = list(input().split())
    x = 0
    for i in b:
        if x < len(a) and a[x] == i:
            x+=1
    if(x == len(a)):
        print("Yes")
    else:
        print("No")
