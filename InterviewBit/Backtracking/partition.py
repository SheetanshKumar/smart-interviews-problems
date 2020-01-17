def partition(arr, idx):

    if idx == len(arr):
        return
    # print("recursion called {} time", idx)
    for i in range(idx, len(arr)):
        print(arr[i], end=' ')
        partition(arr, i+1)
        print()


arr = [1, 2, 3, 4, 5]
partition(arr, 0)