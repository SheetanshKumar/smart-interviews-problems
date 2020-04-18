def checkPL(arr, n):
    ans = 0
    st = ""
    for i in range(n):
        c1 = i
        k = 1
        while ((c1 - k) >= 0 and (c1 + k) < n and arr[c1 - k] == arr[c1 + k]):
            k += 1
        if (2 * k - 1 > ans):
            st = arr[c1 - k+1: c1 + k]
            # print("first")
            # print(st, c1 - k+1, c1 + k)
        ans = max(ans, 2 * k - 1)
        c2 = i + 1
        c1 = i
        if (i + 1 < n and arr[c1] == arr[c2]):
            k = 1
        else:
            continue
        while (c1 - k >= 0 and c2 + k < n and arr[c1 - k] == arr[c2 + k]):
            k += 1
        if (2 * k  > ans):
            st = arr[c1 - (k)+1 : c2 + (k)]
            # print("second")
            # print(st,  c1 - (k)+1 , c2 + (k))
        ans = max(ans, 2 * k)

        # print(arr[c1+1:c2+1])
    return st


a = "abb"
print(checkPL(a, len(a)))