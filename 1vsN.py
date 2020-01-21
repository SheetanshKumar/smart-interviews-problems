# https://codeforces.com/contest/1293/problem/B

n = int(input())
ans = 1.0
for i in range(n):
    x = i
    y = i+1
    ans += (i/(i+1))
print(ans%(10**-4))