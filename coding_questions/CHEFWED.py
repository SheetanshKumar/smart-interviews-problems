def solve(arr, n, k):
    ans = []
    temp = set()
    for i in arr:
        if i not in temp:
            temp.add(i)
        else:
            ans.append(temp)
            temp = set()
            temp.add(i)
    return len(ans)+1


# def solve2(arr, n, k):
#     dp = [0]*(n+1)
#     dp[0] = k
#     mp = dict()
#     for i in range(1, n+1):
#         # dp[i] = min(dp[i-1]+k, arr[i-1]*mp[i-1])
#         if arr[i-1] not in mp:
#             mp[arr[i-1]] = 1
#             dp[i] = dp[i-1]
#         elif arr[i-1] in mp and  k < mp[arr[i-1]]:
#             dp[i] = dp[i-1]+k
#             mp = dict()
#             mp[arr[i-1]] = 1
#         else:
#             mp[arr[i-1]] += 1
#             dp[i] = dp[i-1] + 1
#     # print(dp)
#     return dp[n]

def solve3(arr, n, k):
    mp = dict()
    for i in arr:
        try:
            mp[i]+=1
        except:
            mp[i] = 1
    totalcost = k

    for i in list(mp.keys()):
        if mp[i] >1:
            totalcost+=mp[i]
    # print(totalcost)
    table = 1
    for j in range(1, 1+max(list(mp.values()))):
        temp = 0
        flag = 0
        mainflag = True
        for i in list(mp.keys()):
            if mp[i] - table > 1:
                temp += mp[i]-table
                flag = 1
            elif flag == 1 and mp[i] <= 0:
                if (table+1)*k + temp < totalcost:
                    totalcost = (table+1)*k + temp
                    table += 1
                    temp = 0
                    flag = 0
                else:
                    mainflag = False
        if (table+1)*k + temp < totalcost and mainflag:
            totalcost = (table+1)*k + temp
            table+=1
        else:
            break

    return totalcost


for _ in range(int(input())):
    n, k = list(map(int, input().split()))
    arr = list(map(int, input().split()))
    if (k == 1):
        print(solve(arr, n, k))
    else:
        print(solve3(arr, n, k))