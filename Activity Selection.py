'''Given a set of activities with start time and finish time,
find the maximum number of non-overlapping activities.

Input Format

First line of input contains T - number of test cases. Its followed by 3T lines.
First line of each test case contains N - number of activities.
The second line contains N integers - start time of the activities,
ith element denotes start time of ith activity.
The third line contains N integers - finish time of the activities,
ith element denotes finish time of ith activity.

Constraints

1 <= T <= 1000
1 <= N <= 1000
0 <= S[i] < F[i] <= 86400

Output Format

For each test case, print the maximum number of non-overlapping activities, separated by newline.

Sample Input 0

3
8
49 20 44 23 9 65 42 3
73 38 52 38 40 92 57 17
5
1 25 33 0 17
79 89 58 89 70
6
10 40 15 1 5 20
20 91 75 36 90 40

Sample Output 0

4
1
3

'''


def activitySelection(pairs):
    if (len(pairs) == 0):
        return 0
    c = 1
    prev = pairs[0][1]
    for i in range(len(pairs)):
        if pairs[i][0] >= prev:
            c += 1
            prev = pairs[i][1]
    return c


def makePair(start, end):
    res = []
    for i in range(len(start)):
        res.append((start[i], end[i]))
    res.sort(key=lambda x: x[1])
    return res


for _ in range(int(input())):
    n = int(input())
    start = list(map(int, input().split()))
    end = list(map(int, input().split()))
    pairs = makePair(start, end)
    print(activitySelection(pairs))
