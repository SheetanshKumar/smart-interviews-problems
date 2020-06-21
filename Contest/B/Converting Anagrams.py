'''
https://www.hackerrank.com/contests/smart-interviews-16b/challenges/si-converting-anagrams/copy-from/1324385251
Given two strings A and B, find the minimum number of characters that needs to be deleted from these 2 strings to make them anagrams of each other. An anagram is a rearrangement of the letters of one word to form another word. In other words, some permutation of string A must be same as string B.

Input Format

First line of input contains T - number of test cases. Its followed by T lines, each line contains 2 space separated strings - A and B.

Constraints

1 <= T <= 1000
1 <= len(A), len(B) <= 1000
'a' <= A[i],B[i] <= 'z'

Output Format

For each test case, print the minimum number of deletions required, separated by new line.

Sample Input 0

2
smart interviews
data structures

Sample Output 0

9
12

'''


from collections import Counter

for _ in range(int(input())):
    a, b = list(input().split())
    a = dict(Counter(a))
    b = dict(Counter(b))
    ans = 0
    for i in list(a.keys()):
        if i in b:
            ans = ans + abs(a[i]-b[i])
        else:
            ans += a[i]
    for i in list(b.keys()):
        if i not in a:
            ans+=b[i]
    print(ans)