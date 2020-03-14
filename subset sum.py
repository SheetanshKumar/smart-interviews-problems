def subsetsum(arr, idx, res, s):
    if(idx == len(arr) and res!=s):
        return False
    if(res > s):
        return False
    print(res==s)
    if(res == s):
        return True



    for i in range(idx, len(arr)):
        print(idx, res)
        if(subsetsum(arr, idx+1, res+arr[i], s) == True):
            return True
    # print()
    return False
print(subsetsum([1,2,3,4], 0,0, 12))