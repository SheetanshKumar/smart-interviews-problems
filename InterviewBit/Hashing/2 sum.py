# https://www.interviewbit.com/problems/2-sum/

def twoSum(A, k):
    mp = dict()
    mainres = []
    for i in range(len(A)):
        res = k - A[i]
        if res in mp:
            mainres.append(mp[res]+1)
            mainres.append(i+1)
            break
        if A[i] not in mp:
            mp[A[i]] = i
    return list(mainres)

# A = [2, 7, 11, 15]
# B = 9
A = [ 4, 7, -4, 2, 2, 2, 3, -5, -3, 9, -4, 9, -7, 7, -1, 9, 9, 4, 1, -4, -2, 3, -3, -5, 4, -7, 7, 9, -4, 4, -8 ]
B = -3

result =twoSum(A, B)
print(result)

