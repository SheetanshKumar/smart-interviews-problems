for _ in range(int(input())):
    n = int(input())
    ar = list(map(int, input().split()))
    br = list(map(int, input().split()))

    amin = min(ar)
    bmin = min(br)
    ans = 0
    for i in range(n):
        ans = ans + max(ar[i] - amin, br[i] - bmin)
    print(ans)