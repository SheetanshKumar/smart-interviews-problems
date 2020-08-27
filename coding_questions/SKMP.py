# https://www.codechef.com/AUG20B/problems/SKMP/

from collections import Counter

def solve(a, b):
    mapa = dict(Counter(a))
    mapb = dict(Counter(b))
    for i in list(mapb.keys()):
        mapa[i] = mapa[i] - mapb[i]

    ans2 = [b]
    for i in list(mapa.keys()):
        ans2.append(i * mapa[i])
    ans2 = ''.join(sorted(ans2))

    ans = []
    for i in list(sorted(mapa.keys())):
        ans = ans + list(i*mapa[i])
    i = 0
    while(i < len(ans)):
        if ord(ans[i]) < ord(b[0]):
            i+=1
        else:
            break
    ans = ans[:i] + list(b) + ans[i:]

    return sorted([ans2, ''.join(ans)])[0]


for _ in range(int(input())):
    a = input()
    b = input()
    print(solve(a, b))
