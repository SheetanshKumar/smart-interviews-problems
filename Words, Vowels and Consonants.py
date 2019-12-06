# https://www.hackerrank.com/contests/smart-interviews/challenges/si-words-vowels-and-consonants

'''Given a sentence containing only uppercase/lowercase english alphabets and spaces, you have to count the number of words, vowels and consonants.

Input Format

First line of input contains T - number of test cases. Its followed by T lines, each line contains a single sentence.

Constraints

1 <= T <= 1000
1 <= len(sentence) <= 104

Output Format

For each test case, print the number of words, vowels and consonants, separated by newline.

Sample Input 0

4
Hi
Hello World
  Exception
Hi there

Sample Output 0

1 1 1
2 3 7
1 4 5
2 3 4

'''

_author_ = "sheetansh"

t = int(input())
vowels = "aeiou"

for _ in range(t):
    a = {'w':0, 'v': 0, 'c':0}
    st = input().strip().split()
    a['w'] = len(st)
    for word in st:
        for j in word:
            if j.lower() in vowels:
                a['v']+=1
            else:
                a['c']+=1
    print(a['w'], a['v'], a['c'])