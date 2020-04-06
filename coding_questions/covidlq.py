def isValid(arr, n):
    c = 0
    j = 0
    while(arr[j] != 1):
        j+=1
    j+=1
    for i in range(j, n):
        if arr[i] == 1:
            if c < 5:
                return "NO"
            else:
                c = 0
        else:
            c+=1
    return "YES"



for _ in range(int(input())):
    n = int(input())
    arr = list(map(int, input().split()))
    print(isValid(arr, n))