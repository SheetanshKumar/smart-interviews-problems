# https://www.codechef.com/APRIL20B/problems/STRNO

import math
def primeFactors(n):
    c = 0
    while (n % 2 == 0):
        c+=1
        n = int(n / 2)

    for i in range(3, int(math.sqrt(n)) + 1, 2):
        while (n % i == 0):
            c+=1
            n = int(n / i)
    if n > 2:
        c+=1
    return c

def getResult(x, k):
    res = primeFactors(x)
    if(res < k):
        return 0
    return 1

for _ in range(int(input())):
    x, k = list(map(int, input().split()))
    print(getResult(x, k))

