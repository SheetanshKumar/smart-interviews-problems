def maxProduct(arr):
    n = len(arr)
    maxp = arr[0]
    minp = arr[0]
    ans = -1<<31
    for i in range(1, n):
        if(arr[i] > 0):
            maxp = maxp*arr[i]
            minp = min(1, minp*arr[i])
        elif arr[i] == 0:
            minp = 1
            maxp = 0
        else:
            prev = maxp
            maxp = minp*arr[i]
            minp = prev*arr[i]
        ans = max(ans, maxp)
        if maxp <= 0:
            maxp = 1
    return maxp

def maxProduct2(A):
    assert len(A) > 0
    ans = A[0]
    ma, mi = 1, 1
    for a in A:
        ma, mi = max(a, a * ma, a * mi), min(a, a * ma, a * mi)
        ans = max(ans, ma, mi)
    return ans

print(maxProduct2([-2,-1,-4, -5]))


