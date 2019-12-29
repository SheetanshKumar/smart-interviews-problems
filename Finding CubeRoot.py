# https://www.hackerrank.com/contests/smart-interviews/challenges/si-finding-cuberoot/problem

'''Find the cube root of the given number. Assume that all the input test cases will be a perfect cube.

Input Format

First line of input contains T - number of test cases. Its followed by T lines, each containing a single integer.

Constraints

30 points
1 <= T <= 103
-109 <= N <= 109

70 points
1 <= T <= 106
-1018 <= N <= 1018

Output Format

For each test case, print the cube root of the number, separated by newline.

Sample Input 0

5
-27
-125
1000
6859
-19683

Sample Output 0

-3
-5
10
19
-27

'''

__author__ = "sheetansh"

def cubeRoot(n, flag):
    low, high = 0, n
    mid =0
    while(low<=high):
        mid = (low+high)//2
        temp = mid*mid*mid
        if(temp == n):
            return mid
        elif(temp > n):
            high = mid -1
        else:
            low = mid +1

if __name__ == '__main__':
    for _ in range(int(input())):
        n = int(input())
        flag=1
        if n < 0:
            flag = -1
        print(flag*cubeRoot(abs(n), flag))