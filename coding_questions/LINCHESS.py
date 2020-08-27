# https://www.codechef.com/AUG20B/problems/LINCHESS
def solve(n, k, arr):
    ans = -1
    for i in arr:
        if i < k and k % i == 0:
            if ans != -1:
                if k // i < k // ans:
                    ans = i
            else:
                ans = i
    return ans


for _ in range(int(input())):
    n, k = list(map(int, input().split()))
    arr = list(map(int, input().split()))
    print(solve(n, k, arr))