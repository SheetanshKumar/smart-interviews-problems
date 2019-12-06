# https://www.hackerrank.com/contests/smart-interviews/challenges/si-implement-stack
'''Perform push and pop operations on stack. Implement Stacks and avoid using inbuilt library.

Input Format

First line of input contains T - number of operations. Its followed by T lines, each line contains either "push x" or "pop".

Constraints

1 <= T <= 10000
-100 <= x <= 100

Output Format

For each "pop" operation, print the popped element, separated by newline. If the stack is empty, print "Empty".

Sample Input 0

8
push 5
pop
pop
push 10
push -15
pop
push -10
pop

Sample Output 0

5
Empty
-15
-10

'''

_author_ = "sheetansh"

t = int(input())
st = []
for _ in range(t):
    cmd = input().split()
    if cmd[0] == "pop":
        if len(st) > 0:
            print(st.pop())
        else:
            print("Empty")
    elif cmd[0] == "push":
        st.append(cmd[1])