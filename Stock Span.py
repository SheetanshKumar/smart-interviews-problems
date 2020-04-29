# https://www.hackerrank.com/contests/smart-interviews/challenges/si-stock-span/copy-from/1320297474

'''You are given a series of daily price quotes for a stock and you need to calculate span of stock’s price for each day.
 The span Si of the stock’s price on current day i is defined as the maximum number of consecutive days just before the
 current day[including the current day],
 on which the price of the stock is less than or equal to its price on the current day.

Input Format

First line of input contains T - number of test cases. Its followed by 2T lines, the first line contains N -
the size of the array.
The second line contains N integers - the elements of the array, ith element denotes the stock price on ith day.

Constraints

1 <= T <= 200
1 <= N <= 104
0 <= A[i] <= 104

Output Format

For each test case, print space-separated Stock Span Array, separated by new line.

Sample Input 0

2
7
100 80 60 70 60 75 85
10
0 7 3 6 6 9 18 0 16 0

Sample Output 0

1 1 1 2 1 4 6
1 2 1 2 3 6 7 1 2 1

'''

__author__ = "sheetansh"


def stockspan(arr, n):
    res = [1] * n
    st = []
    for i in range(len(arr) - 1, -1, -1):
        while (st != [] and arr[i] > arr[st[-1]]):
            x = st.pop()
            res[x] = x - i
        st.append(i)
    # print(st)
    while (st != []):
        x = st.pop()
        res[x] = x + 1
    return res


for _ in range(int(input())):
    n = int(input())
    arr = list(map(int, input().split()))
    print(*stockspan(arr, n))
