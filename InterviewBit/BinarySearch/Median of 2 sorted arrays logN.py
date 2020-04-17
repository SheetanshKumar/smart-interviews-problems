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
            maxLeftX = a[part1 - 1]
        except:
            maxLeftX = -1 << 31

        try:
            minRightX = a[part1]
        except:
            minRightX = 1 << 31

        try:
            maxLeftY = b[part2 - 1]
        except:
            maxLeftY = -1 << 31

        try:
            minRightY = b[part2]
        except:
            minRightY = 1 << 31

        if (maxLeftX <= minRightY and maxLeftY <= minRightX):
            if ((x + y) % 2 == 0):
                res = (max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2.0
            else:
                res = max(maxLeftX, maxLeftY)
            break
        elif maxLeftX > minRightY:
            high = part1 - 1
        else:
            low = part1 + 1

    return res

