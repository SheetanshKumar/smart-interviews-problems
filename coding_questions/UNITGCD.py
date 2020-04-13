# https://www.codechef.com/APRIL20B/problems/UNITGCD

def unitgcd(n):
    if(n == 1):
        print(1)
    else:
        print(n//2)
    if(n == 1):
        return print(1, *[1])
    if(n == 2):
        print(2, *[1,2])
        return
    if(n==3):
        print(3, *[1,2,3])
        return
    print(3, *[1, 2, 3])
    temp =list()
    for i in range(4, n+1):
        temp.append(i)
        if(len(temp) == 2):
            print(2, *temp)
            temp = list()
    if(len(temp)>0):
        print(len(temp), *temp)

for _ in range(int(input())):
    n = int(input())
    unitgcd(n)
