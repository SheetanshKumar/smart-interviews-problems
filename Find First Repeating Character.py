# https://www.hackerrank.com/contests/smart-interviews/challenges/si-find-first-repeating-character

'''Given a string of characters, find the first repeating character.

Input Format

First line of input contains T - number of test cases. Its followed by T lines, each line contains a single string of characters.

Constraints

1 <= T <= 1000
'a' <= str[i] <= 'z'
1 <= len(str) <= 104

Output Format

For each test case, print the first repeating character, separated by newline. If there are none, print '.'.

Sample Input 0

3
smartinterviews
algorithms
datastructures

Sample Output 0

s
.
a

'''

_author_ = "sheetansh"

from collections import Counter

t = int(input())

for _ in range(t):
    st = Counter(input())
    flag = 1
    for i in st.keys():
        if st[i] >1:
            print(i)
            flag = 0
            break
    if flag:
        print(".")