for _ in range(int(input())):
    n = int(input())
    ar = list(map(int, input().split()))

    if n ==1:
        print("YES")
        continue
    ar.sort()
    flag = 1
    for i in range(n-1):
        if abs(ar[i]-ar[i+1]) >1:
            flag = 0
            break
    if(flag):
        print("YES")
    else:
        print("NO")

