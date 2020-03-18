def dNums(A, B):
    win = dict()
    res = []
    for i in range(B):
        try:
            win[A[i]]+=1
        except:
           win[A[i]] = 1

    for i in range(len(A)-B):
        s =i
        res.append(len(win))
        win[A[i]] = win[A[i]]-1
        if(win[A[i]] == 0):
            del win[A[i]]
        try:
            win[A[s+B]] +=1
        except:
            win[A[s+B]] =1
    res.append(len(win))
    return res

print(dNums([ 1, 2, 1, 3, 4, 3 ], 3))