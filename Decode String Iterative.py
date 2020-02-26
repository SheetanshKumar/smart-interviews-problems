def isValid(st):
    # print(st)
    if(len(st)<1) or st[0] == '0':
        return False
    return int(st) <= 25 and int(st) >= 0


def decodeString(arr, n, idx, dp):
    if idx == n:
        return 1
    if (dp[idx] > -1):
        return dp[idx]%1000000007
    count = 0
    count += decodeString(arr, n, idx+1, dp)%1000000007
    if (idx+1 < n):
        if(isValid(arr[idx: idx+2])):
            count+=decodeString(arr, n, idx+2, dp)%1000000007
    count = count%1000000007
    dp[idx] = count
    return count


def decode(arr, n):


    dp = [-1]*(n+1)
    count = 0
    for i in range(len(arr) - 1):
        dp[i] = dp[i+1]
        if i+2 < n:
            dp[i] = dp[i+2]


for _ in range(int(input())):
    n = int(input())
    arr = input()
    dp = [-1]*(n+1)
    print(decodeString(arr, n, 0,dp))