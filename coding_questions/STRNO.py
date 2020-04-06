# https://www.codechef.com/APRIL20B/problems/STRNO

import math
from collections import Counter
def primeFactors(n):
    res = []
    while n % 2 == 0:
        res.append(2)
        n = n // 2

    for i in range(3, int(math.sqrt(n)) + 1, 2):
        while n % i == 0:
            res.append(i)
            n = n // i
    if n > 2:
        res.append(n)
    return res

def getFactorsCount(pf):
    d = dict(Counter(pf))
    res = 1
    for i in list(d.values()):
        res = res * (i+1)
    return res

pf = primeFactors(5)
print(pf)
f = getFactorsCount(pf)
print(f)

def getResult(x, k):
    if ((x==2 and k == 1) or (x==1 and k ==0)):
        return 1
    for i in range()

for _ in range(int(input())):
    x, k = list(map(int, input().split()))
    if(x == 2 and k ==1):
        print(1)



