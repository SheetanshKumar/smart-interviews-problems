# https://www.hackerrank.com/contests/smart-interviews/challenges/si-interleavings/copy-from/1321284252

'''Given 2 strings A and B, print all the interleavings of the 2 strings. An interleaved string of given two strings preserves the order of characters in individual strings and uses all the characters of both the strings. For simplicity, you can assume that the strings have unique characters.

Input Format

First line of input contains T - number of test cases. Its followed by T lines, each contains 2 space separated strings A and B.

Constraints

1 <= T <= 100
'a' <= A[i], B[i] <= 'z'
1 <= len(A), len(B) <= 10

Output Format

For each test case, print the test case number, followed by the interleavings of the 2 strings in a sorted order, separated by newline.

Sample Input 0

2
nkb gl
bn zh

Sample Output 0

Case #1:
glnkb
gnkbl
gnklb
gnlkb
ngkbl
ngklb
nglkb
nkbgl
nkgbl
nkglb
Case #2:
bnzh
bzhn
bznh
zbhn
zbnh
zhbn

'''


def getinterleavings(a, b, idx1, idx2, res, i):
    if idx1 == 0 and idx2 == 0:
        result.append(''.join(res))

    if idx1 != 0:
        res[i] = a[0]
        getinterleavings(a[1:], b, idx1 - 1, idx2, res, i + 1)
    if idx2 != 0:
        res[i] = b[0]
        getinterleavings(a, b[1:], idx1, idx2 - 1, res, i + 1)


for i in range(int(input())):
    st1, st2 = input().split()
    global result
    result = []
    getinterleavings(st1, st2, len(st1), len(st2), [''] * (len(st1) + len(st2)), 0)
    print("Case #{}:".format(i + 1))
    for i in sorted(result):
        print(i)

