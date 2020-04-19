# res = []
# def subsetUtil(arr,tempres, idx):
#     # res.append(tempres)
#     # print(res)
#     print(tempres)
#     for i in range(idx, len(arr)):
#         tempres.append(arr[i])
#         subsetUtil(arr,tempres, i+1)
#         tempres.pop()
#     return
#
# def subset(A):
#     tempres = []
#     subsetUtil(A,tempres,0)



def subsetUtil(arr,tempres, idx):
    res.append(tempres)
    # print(res)
    # print(tempres)
    for i in range(idx, len(arr)):
        tempres.append(arr[i])
        subsetUtil(arr,tempres, i+1)
        tempres.pop()
    return

def subset(A):
    global res
    res = []
    tempres = []
    subsetUtil(A,tempres,0)
    temp = res
    return temp

subset([1])
print(res)
