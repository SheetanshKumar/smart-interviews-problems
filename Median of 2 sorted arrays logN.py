# verify this solution

def findMedian(a, b):
    if (len(a) > len(b)):
        return findMedian(b, a)

    low, high = 0, len(a)
    x = len(a)
    y = len(b)
    res = 0
    while (low <= high):
        part1 = (low + high) // 2
        part2 = (x + y + 1) // 2 - part1

        try:
            maxXleft = a[part1 - 1]
        except:
            maxXleft = -1 << 31
        try:
            minXright = a[part1]
        except:
            minXright = 1 << 31
        try:
            maxYleft = b[part2 - 1]
        except:
            maxYleft = -1 << 31
        try:
            minYright = b[part2]
        except:
            minYright = 1 << 31

        if (maxXleft <= minYright and maxYleft <= minXright):
            if ((x + y) % 2 == 0):
                res = (max(maxXleft, maxYleft) + min(minXright, minYright)) / 2.0
            else:
                res = max(maxXleft, maxYleft)
            break
        elif maxXleft > minYright:
            high = part1 - 1
        else:
            low = part1 + 1

    return res