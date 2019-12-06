# https://www.hackerrank.com/contests/smart-interviews/challenges/si-distinct-elements-in-window

'''Given an array of integers and a window size K, find the number of distinct elements in every window of size K of the given array.

Input Format

First line of input contains T - number of test cases. Its followed by 2T lines. First line of each test case contains N - size of the array and K - size of the window. The second line contains N integers - elements of the array.

Constraints

1 <= T <= 1000
1 <= N <= 10000
1 <= K <= N
-100 <= ar[i] <= 100

Output Format

For each test case, print the number of distinct elements in every window of size K, separated by newline.

Sample Input 0

3
5 3
-2 -4 -2 4 -2
10 7
3 -4 -3 -4 -2 0 2 -2 6 0
17 13
-5 -1 4 8 -5 -3 -4 7 4 -4 0 8 0 -2 3 2 5

Sample Output 0

2 3 2
6 5 6 5
8 9 9 10 11

'''

_author_ = "sheetansh"

from collections import Counter

for _ in range(int(input())):
    n, k = list(map(int, input().split()))
    arr = list(map(int, input().split()))
    res = []
    i, j = 0, k-1
    m = dict(Counter(arr[i:j+1]))
    res.append(len(m))
    while(j != n-1):
        i+=1
        j+=1
        m[arr[i-1]]-=1
        if(m[arr[i-1]] == 0):
            del m[arr[i-1]]
        try:
            m[arr[j]] +=1
        except:
            m[arr[j]] = 1
        res.append(len(m))
    print(*res)