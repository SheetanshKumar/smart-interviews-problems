def findMinXor():
    arr = list(map(int, input().split()))
    arr.sort()
    minXor = arr[0] ^ arr[1]
    for i in range(len(arr) - 1):
        minXor = min(minXor, arr[i] ^ arr[i + 1])
    return minXor

if __name__ == '__main__':
    print(findMinXor())