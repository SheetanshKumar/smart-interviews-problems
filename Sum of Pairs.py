# https://www.hackerrank.com/contests/smart-interviews/challenges/si-sum-of-pairs

'''
Given an array of integers and a number K, check if there exist a pair of indices i,j s.t. a[i] + a[j] = K and i!=j.

Input Format

First line of input contains T - number of test cases. Its followed by 2T lines, first line of each test case contains N - size of the array and K, and the next line contains N integers - the elements of the array.

Constraints

30 points
1 <= T <= 100
2 <= N <= 1000

70 points
1 <= T <= 300
2 <= N <= 10000

General Constraints
-108 <= K <= 108
-108 <= ar[i] <= 108

Output Format

For each test case, print "True" if such a pair exists, "False" otherwise, separated by newline.

Sample Input 0

3
5 -15
-30 15 20 10 -10
2 20
10 10
4 7
-4 0 10 -7

Sample Output 0

True
True
False


'''

_author_ = "sheetansh"

t = int(input())
for _ in range(t):
    n, k = list(map(int, input().split()))
    arr = list(map(int, input().split()))
    arr.sort()
    i, j = 0, n-1
    flag = False
    while(i != j):
        if(arr[i] + arr[j] == k):
            flag = True
            break
        if(arr[i] + arr[j] < k):
            i+=1
        elif(arr[i] + arr[j] > k):
            j-=1
    print(flag)