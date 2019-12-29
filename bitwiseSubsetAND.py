def isPower(n):
    return ((n & (n - 1)) == 0)

def checkBits(a, b):
    return (a& (1<<b))

def countSubsetsBitwise(arr, n):
    if (n==1):
        return isPower(arr[0])

    ans = 0
    for i in range(32):
        ans = (1<<32) -1
        for j in range(n):
            if (checkBits(arr[j], i)):
                ans = ans & arr[j]
        if isPower(ans):
            return True
    return False

for _ in range(int(input())):
    n = int(input())
    arr = list(map(int, input().split()))
    c = countSubsetsBitwise(arr, n)
    if (c):
        print("YES")
    else:
        print("NO")