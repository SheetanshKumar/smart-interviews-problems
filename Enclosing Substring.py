# https://www.hackerrank.com/contests/smart-interviews/challenges/si-enclosing-substring/copy-from/1319173048

'''Given 2 strings A and B, find the smallest substring of B having all the characters of A, in any order.

Input Format

First line of input contains T - number of test cases. Its followed by T lines, each line containing 2 space separated strings - A and B.

Constraints

20 points
1 <= T <= 100
1 <= size(A), size(B) <= 100

60 points
1 <= T <= 100
1 <= size(A), size(B) <= 1000

120 points
1 <= T <= 100
1 <= size(A), size(B) <= 10000

General Constraints
'a' <= A[i],B[i] <= 'z'

Output Format

For each test case, print the length of the smallest substring of B having all the characters of A, separated by newline. If no such substring found, print -1.

Sample Input 0

4
fkqyu frqkzkruqmfqyuzlkyg
onmwvytbytn uqhmfjaqtgngcwkuzyamnerphfmw
bloets lwbcrsfothplxseplrtbshbtstjloxsf
dzpd dclzztpjldkndgbdqqzmbp

Sample Output 0

7
-1
13
9

'''

from collections import Counter


def isMapSet(mapA, mapB):
    # print(mapA, mapB)
    for i in mapA:
        try:
            if mapA[i] > mapB[i]:
                return False
        except:
            return False
    return True


for _ in range(int(input())):
    a, b = input().split()

    mapA = dict(Counter(a))
    mapB = dict(Counter(b))
    if (isMapSet(mapA, mapB) == False):
        print(-1)
        continue
    mapB = dict()
    i = 0
    j = 0
    ans = (1 << 31) - 1
    while (i < len(b) and j < len(b)):
        while (not isMapSet(mapA, mapB) and j < len(b)):
            try:
                mapB[b[j]] += 1
            except:
                mapB[b[j]] = 1
            j += 1

        if j == len(b) and isMapSet(mapA, mapB) == False:
            break
        ans = min(j - i, ans)
        while (isMapSet(mapA, mapB) and i < len(b) - len(a) + 1):
            mapB[b[i]] -= 1
            if mapB[b[i]] == 0:
                del mapB[b[i]]
            i += 1
        ans = min(ans, j - i + 1)
    # ans=min(ans, j-i-1)
    print(ans)



