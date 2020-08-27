def getMaxPair(arr, n):
    mp = dict()
    for i in range(n-1):
        for j in range(i+1, n):
            try:
                mp[arr[i] + arr[j]]+=1
            except:
                mp[arr[i] + arr[j]] = 1
    ans = 0
    # print(mp)
    for k in list(mp.keys()):
        # ans = max(ans, mp[k])
        idx = set()
        temp = 0
        for i in range(n):
            if i not in idx:
                for j in range(i+1, n):
                    if ar[i] + ar[j] == k and j not in idx and i not in idx:
                        idx.add(i)
                        idx.add(j)
                        temp+=1
                        # print((i, j))
        ans = max(temp, ans)
    return ans

if __name__ == '__main__':
    for _ in range(int(input())):
        n = int(input())
        ar = list(map(int, input().split()))

        if(n == 1):
            print(0)
            continue
        if(n == 2 or n == 3):
            print(1)
            continue
        print(getMaxPair(ar, n))
