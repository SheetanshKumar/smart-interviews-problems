# https://www.hackerrank.com/contests/smart-interviews/challenges/si-finding-the-floor

'''Given an array, you have to find the floor of a number x. The floor of a number x is nothing but the largest number in the array less than or equal to x.

Input Format

First line of input contains N - size of the array. The next line contains N integers, the elements of the array. The next line contains Q - number of queries. Each of the next Q lines contains a single integer X, for which you have to find the floor of X in the given array.

Constraints

30 points
1 <= N <= 105
1 <= Q <= 102
-108 <= ar[i] <= 108

70 points
1 <= N <= 105
1 <= Q <= 105
-108 <= ar[i] <= 108

Output Format

For each query, print the floor of X, separated by newline. If floor not found, print the value of "INT_MIN"

Sample Input 0

6
-6 10 -1 20 15 5
5
-1
10
8
-10
-4

Sample Output 0

-1
10
5
-2147483648
-6

'''

_author_ = "sheetansh"

n = int(input())
arr = list(map(int, input().split()))
arr.sort()
for _ in range(int(input())):
    q = int(input())
    floor = -2147483648
    low, high = 0, n - 1
    mid = 0
    while (low <= high):
        mid = (low + high) // 2
        if (arr[mid] == q):
            floor = q
            break
        elif (arr[mid] > q):
            high = mid - 1
        else:
            floor = arr[mid]
            low = mid + 1
    print(floor)
