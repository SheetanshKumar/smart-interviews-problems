from sys import stdin, stdout

# import operator as op
# from functools import reduce

# def getNCR(n, r):
#     r = min(r, n-r)
#     numer = reduce(op.mul, range(n, n-r, -1), 1)
#     denom = reduce(op.mul, range(1, r+1), 1)
#     return numer // denom
#
# def solve(arr, n):
#     carr = [0]*(n+1)
#     parr = [0]*(n+1)
#     ans = dict()
#     for i in range(1, n+1):
#         carr[arr[i-1]]+=1
#     for i in range(1, n+1):
#         parr[i] = carr[i]+parr[i-1]
#     # print(parr)
#     for j in range(1, n+1):
#         temp = 0
#         c = parr[j]
#         p = parr[n] - parr[j]
#         for i in range(1, c+1):
#             a = c - i + p
#             print("p = {}".format(parr[n]-parr[i]))
#             print(a)
#             ncr = getNCR(c, i)
#             if(a%2 ==0):
#                 temp += ncr * (1<<a)
#             else:
#                 temp -= ncr * (1<<a)
#         ans[c] = temp
#         print()
#     return ans


# def checkbits(i, b):
#     return i>>b&1
#
# def solve(arr, n):
#     ans = dict()
#     for i in range(1, 1<<n):
#         temp = dict()
#         for j in range(n):
#             if checkbits(i, j):
#                 try:
#                     temp[arr[j]]+=1
#                 except:
#                     temp[arr[j]] = 1
#         # print(temp)
#         try:
#             ans[max(temp, key=temp.get)] += 1
#         except:
#             ans[max(temp, key=temp.get)] = 1
#     return ans

final = dict()
def solvesubsets(arr, n, idx, temp):
    if idx == n:
        try:
            final[max(temp, key=temp.get)] += 1
        except:
            final[max(temp, key=temp.get)] = 1
        return
    elif idx > n:
        return
    temp[arr[idx]]+=1
    solvesubsets(arr, n, idx+1, temp)
    temp[arr[idx]] -= 1
    solvesubsets(arr, n, idx + 1, temp)

def aPowerb(a, b):
    if (b==0):
        return 1
    store = aPowerb(a, b//2)
    if(b %2 == 0):
        return ((store%1000000007)*(store%1000000007))%1000000007
    else:
        return (a*((store%1000000007)*(store%1000000007))%1000000007)%1000000007

def solvepower(arr, n):
    for i in range(1, n+1):
        final[i] = aPowerb(2, n-i)

t = int(stdin.readline())

for _ in range(t):
    n = int(stdin.readline())
    arr = [int(x) for x in stdin.readline().split()]
    # ans = solve(arr, n)
    temp = dict()
    final = dict()
    for i in range(n+1):
        temp[i] = 0
    # solvesubsets(arr, n, 0, temp)
    solvepower(arr, n)
    ans = final
    for i in range(1, n+1):
        try:
            stdout.write(str(ans[i])+' ')
            # print(ans[i], end = ' ')
        except:
            stdout.write('0 ')
            # print(0, end=' ')
    stdout.write('\n')

#
# solvesubsets([1,2,3], 3, 0, temp,final)
# temp =[ 12,3,4]
# print(final)