# https://www.hackerrank.com/contests/smart-interviews/challenges/si-reverse-the-sentence

'''Given a sentence, reverse the entire sentence word-by-word.

Input Format

First line of input contains T - number of test cases. Its followed by T lines, each contains a sentence S of space separated words of lowercase english alphabet. All the words are separated by a single space.

Constraints

1 <= T <= 1000
1 <= len(S) <= 1000

Output Format

For each test case, print the reversed sentence, separated by newline.

Sample Input 0

3
hello world
a b c d
data structures and algorithms

Sample Output 0

world hello
d c b a
algorithms and structures data
'''

_author_ = "sheetansh"

t = int(input())
for _ in range(t):
    print(*input().split()[::-1])