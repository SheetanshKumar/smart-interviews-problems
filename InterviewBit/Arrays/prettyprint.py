def prettyPrint(n):
    ans = []
    for i in range(n):
        temp = []
        k = n
        for j in range(i):
            temp.append(k)
            k -= 1
        temp = temp + ([n - i] * (n - i))
        temp = temp + temp[::-1][1:]
        ans.append(temp)
    for i in range(1,n):
        ans.append(ans[n-i-1])
    return ans

a = prettyPrint(4)

for i in a:
    print(i)
