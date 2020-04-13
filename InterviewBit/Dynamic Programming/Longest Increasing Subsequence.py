def lis(arr):
    n = len(arr)
    dp = [0]*n
    dp[0] = 1
    for i in range(n):
        m = 0
        for j in range(i):
            if(arr[i] > arr[j]):
                m = max(m, dp[j])
        dp[i] = m+1
    return max(dp)

print(lis([0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15]))
