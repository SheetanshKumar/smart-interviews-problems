'''
https://www.hackerrank.com/contests/smart-interviews-16b/challenges/si-pattern-representation

Given a pattern consisting only of 'I' and 'S', where I represents descending and S represents ascending, you need to display a sequence of numbers describing the ascending or descending order. Each character should be represented by 2 digits (between 1-9) - denoting the character's ascending or descending nature.

The second character in the pattern takes the last digit from the first character to build the sequence. The third character in the pattern takes the last digit from the second character to build the sequence and so on. The sequence cannot have repeated digits. Find the smallest such sequence which represents the given pattern.

Input Format

First line of input contains T - number of test cases. Its followed by T lines, each containing a pattern, consisting only of 'S' and 'I'.

Constraints

1 <= T <= 500
1 <= len(str) <= 8

Output Format

For each test case, print the smallest sequence which represents the given pattern, separated by newline.

Sample Input 0

4
S
I
SIS
IISS

Sample Output 0

12
21
1324
32145

Explanation 0

Test Case 1
The given pattern has a single character 'S', which denotes ascending nature. There are multiple ways to represent it - 12, 47, 28, 34 etc. However, "12" is the smallest of them.

Test Case 2
The given pattern has a single character 'I', which denotes descending nature. There are multiple ways to represent it - 21, 41, 75, 96 etc. However, "21" is the smallest of them.

Test Case 3
The given pattern has 3 characters 'S' (ascending), 'I' (descending) and 'S' (ascending). There are multiple ways to represent it - 1324, 1634, 1435, 4812, 3748 etc. However, "1324" is the smallest of them.

Contest ends in 3 hours

Submissions: 0

Max Score:

100

Difficulty:

Medium

Rate This Challenge:
More
'''