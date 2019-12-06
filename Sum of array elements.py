# https://www.hackerrank.com/contests/smart-interviews/challenges/si-sum-of-array-elements/

# Given an array of integers, find the sum of the elements of the given array.
#
# Input Format
#
# First line of input contains T - number of test cases. Its followed by 2T lines, the first line contains N - the size of the array and second line contains the elements of the array.
#
# Constraints
#
# 1 <= T <= 100
# 1 <= N <= 1000
# 1 <= ar[i] <= 1e15
#
# Output Format
#
# For each test case, print the sum of the elements of the array, separated by new line.
#
# Sample Input 0
#
# 2
# 3
# 5 15 3
# 2
# 70 100
#
# Sample Output 0
#
# 23
# 170

# solution:

_author_ = "sheetansh"


t = int(input())
for _ in range(t):
    n = int(input())
    l = list(map(int, input().split()))
    print(sum(l))