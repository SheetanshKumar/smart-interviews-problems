"""
https://www.hackerrank.com/contests/smart-interviews-16b/challenges/si-light-man
One fine evening, Light Man was walking down the streets of Hogwarts. Light Man is a new hero in the wizarding community with the power to manipulate light. Now, he decided to test his super powers on the street lights. His power allows him to chose a single light at a time and change its state: ON<->OFF. As he is running late for his next adventure, he can only use his power for a maximum of M times.

Now, given the initial state of the street lights:
1 - ON
0 - OFF

You have to find the maximum continuous series of street lights in ON state after Light Man has performed a maximum of M spells.

Input Format

First line of input contains T - number of test cases. Its followed by 2T lines, the first line of each test case contains N, M - the total number of street lights and the maximum number of spells, the second line contains the state of the lights.

Constraints

10 points
1 <= T <= 100
1 <= N <= 100

20 points
1 <= T <= 100
1 <= N <= 1000

70 points
1 <= T <= 100
1 <= N <= 100000

Output Format

For each test case, print the length of the maximum continuous series of lights in ON state after Light Man performs a maximum of M spells, separated by newline.

Sample Input 0

5
8 1
1 0 0 0 0 0 1 1
2 1
1 0
8 7
1 1 0 1 1 0 1 0
17 4
0 1 1 0 0 0 1 1 0 1 1 0 1 0 1 0 1
35 13
1 0 1 1 1 1 1 1 1 0 0 1 0 0 0 1 0 0 0 0 0 1 1 0 0 0 1 0 1 1 1 0 1 0 0

Sample Output 0

3
2
8
11
25

"""

for _ in range(int(input())):
    n, k = list(map(int, input().split()))
    arr = list(map(int, input().split()))
    c, low = 0,0
    ans = 0
    for high in range(n):
        if arr[high] == 0:
            c+=1
        while(c > k):
            if(arr[low] == 0):
                c-=1
            low+=1
        ans = max(ans, high - low+1)
    print(ans)