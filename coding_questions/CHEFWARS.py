# https://www.codechef.com/AUG20B/problems/CHEFWARS
def solve(h, p):
    while(h >= p and p != 0):
        h = h - p
        p = p//2
    return int(h <= p)


for _ in range(int(input())):
    h, p = list(map(int, input().split()))
    print(solve(h, p))