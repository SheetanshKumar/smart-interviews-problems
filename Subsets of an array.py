# https://www.hackerrank.com/contests/smart-interviews/challenges/si-subsets-of-an-array/problem

'''Given an array of unique integer elements, print all the subsets of the given array in lexicographical order.

Input Format

First line of input contains T - number of test cases. Its followed by 2T lines, the first line contains N - the size of the array and second line contains the elements of the array.

Constraints

1 <= T <= 100
1 <= N <= 10
0 <= A[i] <= 100

Output Format

For each test case, print the subsets of the given array in lexicographical order, separated by new line. Print an extra newline between output of different test cases.

Sample Input 0

3
3
5 15 3
2
57 96
4
3 15 8 23

Sample Output 0

3
3 5
3 5 15
3 15
5
5 15
15

57
57 96
96

3
3 8
3 8 15
3 8 15 23
3 8 23
3 15
3 15 23
3 23
8
8 15
8 15 23
8 23
15
15 23
23

'''

_author_ = "sheetansh"


def subsetUtil(arr, tempres, idx):
    # res.append(tempres)
    # print(res)
    if (tempres != None and tempres != []):
        print(*tempres)
    for i in range(idx, len(arr)):
        tempres.append(arr[i])
        subsetUtil(arr, tempres, i + 1)
        tempres.pop()
    return


def subset(A):
    tempres = []
    subsetUtil(A, tempres, 0)




for _ in range(int(input())):
    # n = int(input())
    # arr = list(map(int, input().split()))
    # arr.sort()
    subset([1,2,3])
    print()