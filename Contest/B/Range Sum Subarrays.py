'''
https://www.hackerrank.com/contests/smart-interviews-16b/challenges/si-range-sum-subarrays
Given an array of integers and a range [A,B], you have to find the number of subarrays whose sum lies in the given range inclusive.

Input Format

First line of input contains T - number of test cases. Its followed by 2T lines, the first line of each test case contains N, A, B - size of the array and the range separated by space, the second line contains the elements of the array.

Constraints

30 points
1 <= T <= 100
1 <= N <= 100
-106 <= A <= B <= 106
-104 <= ar[i] <= 104

70 points
1 <= T <= 100
1 <= N <= 1000
-107 <= A <= B <= 107
-104 <= ar[i] <= 104

Output Format

For each test case, print the number of subarrays whose sum lies in the given range, separated by newline.

Sample Input 0

4
3 -10 5
-5 10 -3
4 -10000 1000
929 -4041 -2470 -6445
9 -36116 6820
4605 -626 -3454 -2532 -91 3010 -3557 5552 4055
6 392 5416
-4905 -2388 5352 -3231 4902 -7485

Sample Output 0

4
8
41
6

Explanation 0

Test Case 1:
The subarrays are:
-5 [Sum = -5]
-5 10 [Sum = 5]
-5 10 -3 [Sum = 2]
10 [Sum = 10]
10 -3 [Sum = 7]
-3 [Sum = -3]
Hence, there are 4 subarrays whose sum lie in the range [-10,5]
Contest ends in 3 hours

Submissions: 21

Max Score:

100

Difficulty:

Easy

Rate This Challenge:
More
'''