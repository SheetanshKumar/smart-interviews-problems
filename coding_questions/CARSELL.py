def getProfit(arr, n):
    arr.sort(reverse=True)
    for i in range(n):
        arr[i] = max(arr[i]-i, 0)
    return sum(arr)%1000000007


for _ in range(int(input())):
    n = int(input())
    arr = list(map(int, input().split()))
    print(getProfit(arr, n))