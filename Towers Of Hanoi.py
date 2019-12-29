# https://www.hackerrank.com/contests/smart-interviews/challenges/si-tower-of-hanoi/problem

''''The Tower of Hanoi (also called the Tower of Brahma or Lucas') is a mathematical game or puzzle. It consists of three rods, and a number of disks of different sizes which can slide onto any rod. The puzzle starts with the disks in a neat stack in ascending order of size on one rod, the smallest at the top, thus making a conical shape.

The objective of the puzzle is to move the entire stack to another rod, obeying the following simple rules:

    Only one disk can be moved at a time.
    Each move consists of taking the upper disk from one of the stacks and placing it on top of another stack i.e. a disk can only be moved if it is the uppermost disk on a stack.
    No disk may be placed on top of a smaller disk.

Your task is that given N disks, print the minimum number of moves required in order to solve the problem, followed by the actual moves.

Assumptions
1. The rods are named A, B and C.
2. All the disks are initially placed on rod A.
3. You have to move all the disks from rod A to rod C.

Input Format

First line of input contains T - number of test cases. Its followed by T lines, each line containing a single number denoting the number of disks.

Constraints

1 <= T <= 10
1 <= N <= 15

Output Format

For each test case, print the minimum number of moves required in order to solve the problem, followed by the actual moves, separated by newline. Refer sample output for more details.

Sample Input 0

2
1
3

Sample Output 0

1
Move 1 from A to C
7
Move 1 from A to C
Move 2 from A to B
Move 1 from C to B
Move 3 from A to C
Move 1 from B to A
Move 2 from B to C
Move 1 from A to C

'''

res = []


def TowersOfHanoi(n, A, B, C):
    if (n == 1):
        res.append("Move 1 from {} to {}".format(A, B))
        return

    TowersOfHanoi(n - 1, A, C, B)
    res.append("Move {} from {} to {}".format(n, A, B))
    TowersOfHanoi(n - 1, C, B, A)


for _ in range(int(input())):
    n = int(input())
    res = []
    TowersOfHanoi(n, "A", "C", "B")
    print(len(res))
    for i in res:
        print(i)
