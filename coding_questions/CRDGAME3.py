# https://www.codechef.com/AUG20B/problems/CRDGAME3

def solve(pc, pr):
    ans = [1, 1]
    if pc <= 9 and pr <= 9:
        return [1, 1]
    if pc // 9 < pr // 9:
        if pc % 9 == 0:
            return [0, pc//9]
        return [0, pc//9 + 1]
    if pr % 9 == 0:
        return [1, pr // 9]
    return [1, pr//9 + 1]

for _ in range(int(input())):
    pc, pr = list(map(int, input().split()))
    print(*solve(pc, pr))