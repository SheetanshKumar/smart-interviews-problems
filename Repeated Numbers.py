# https://www.hackerrank.com/contests/smart-interviews/challenges/si-repeated-numbers

'''
You are given an array of n+2 elements. All elements of the array are in range 1 to n. All elements occur once except two numbers, which occur twice. Your task is to find the two repeating numbers.

Input Format

First line of input contains T - number of test cases. Its followed by 2T lines, the first line contains N - the size of the array and second line contains the elements of the array.

Constraints

30 points
1 <= T <= 100
4 <= N <= 103

70 points
1 <= T <= 100
4 <= N <= 106

Output Format

Print the 2 repeated numbers in sorted manner, for each test case, separated by new line.

Sample Input 0

2
8
1 3 2 3 4 6 5 5
10
1 5 2 8 1 4 7 4 3 6

Sample Output 0

3 5
1 4


'''

_author_ = "sheetansh"

t = int(input())
for _ in range(t):
    n = int(input())
    arr = list(map(int, input().split()))
    arr.sort()
    res = []
    for i in range(len(arr) - 1):
        if arr[i] == arr[i+1]:
            res.append(arr[i])
    print(*res)