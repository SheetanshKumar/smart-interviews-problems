# https://www.hackerrank.com/contests/smart-interviews/challenges/si-decode-strings

def isValid(st):
    # print(st)
    try:
        return int(st) <= 25 and int(st) >=10
    except:
        return False


def decodeString(arr, n, idx, dp):
    if idx == n:
        return 1
    if (dp[idx] > -1):
        return dp[idx]
    count = 0
    count += decodeString(arr, n, idx+1, dp)%1000000007
    if (idx+1 < n):
        if(isValid(arr[idx: idx+2])):
            count+=decodeString(arr, n, idx+2, dp)%1000000007

    count = count%1000000007
    dp[idx] = count
    return count

if __name__ == '__main__':
    st = "00"
    dp = [-1]*len(st)
    print(decodeString(st, len(st), 0, dp))


