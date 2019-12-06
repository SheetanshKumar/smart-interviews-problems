# https://www.hackerrank.com/contests/smart-interviews/challenges/si-rhymes

'''Given is a wordlist L, and a word w. Your task is to find the length of the longest word in L having the longest common suffix with w.

Input Format

First line of input contains N - length of the list of words. The next N lines contains a single word having lowercase english alphabets. The next line contains Q - number of queries. Each of the next Q lines contains a single word w having lowercase english alphabets.

Constraints

50 points
1 <= N, Q <= 1000
1 <= len(word) <= 100

150 points
1 <= N, Q <= 10000
1 <= len(word) <= 500

Output Format

For each query w, print the length of the longest word having the longest common suffix with w, separated by newline.

Sample Input 0

4
crime
fast
time
cast
3
dime
gist
algorithm

Sample Output 0

5
4
0

Explanation 0

Test Case 1
Both the words crime and time have the longest common suffix with dime. Hence, length of the longest word is 5.

Test Case 2
Both the words fast and cast have the longest common suffix with gist. Hence, length of the longest word is 4.

Test Case 3
There is no word in L having a common suffix with algorithm. Hence, length of the longest word is 0.'''

_author_ = "sheetansh"

n = int(input())
words = []
for _ in range(n):
    words.append(input())
q = int(input())
for _ in range(q):
    query = list(input())
    max_len = 0
    curr_len = 0
    max_suff_len = 0
    for i in words:
        if(i[-1] == query[-1]):
            curr_len = len(i)
            k = -1
            while(abs(k) <= len(query)and abs(k) < len(i) and i[k] == query[k]):
                k-=1
            if abs(k) > max_suff_len or ((abs(k) == max_suff_len) and curr_len > max_len):
                max_len = curr_len
                max_suff_len = abs(k)
    print(max_len)