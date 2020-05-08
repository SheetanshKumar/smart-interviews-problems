'''Look at the following sequence:
3, 5, 6, 9, 10, 12, 17, 18, 20....

All the numbers in the series has exactly 2 bits set in their binary representation. Your task is simple, you have to find the Nth number of this sequence.

Input Format

First line of input contains T - number of test cases. Its followed by T lines, each containing a single number N.

Constraints

20 points
1 <= T, N <= 200

60 points
1 <= T, N <= 105

120 points
1 <= T <= 105
1 <= N <= 1014

Output Format

For each test case, print the Nth number of the sequence, separated by newline. Since the number can be very large, print number % 1000000007.

Sample Input 0

5
1
2
5
50
100

Sample Output 0

3
5
10
1040
16640

'''

from sys import stdin, stdout
import math

def apown(x, n):
    res = 1
    mod = 1000000007
    while n:
        if(n &1):
            res = (res*x)%mod
        x = ((x%mod)*(x%mod))%mod
        n = n >>1
    return res

for _ in range(int(input())):
    n = int(stdin.readline())
    # n = int(input())%1000000007
    i= ((int(math.sqrt((n<<3)-1))) + 1) >>1
    x = n - ((i*(i-1)) >>1)-1
    stdout.write(str((apown(2, i) + apown(2, x))%1000000007) +'\n')
    # print(((1<<i)%1000000007 + (1<<x)%1000000007)%1000000007)