def findMedian(a, b):
    if (len(a) > len(b)):
        return findMedian(b, a)

    low, high = 0, len(a)
    x = len(a)
    y = len(b)
    while (low <= high):
        part1 = (low + high) // 2
        part2 = ((x + y +1) // 2) - part1

        if part1 != 0:
            maxLeftX = a[part1 - 1]
        else:
            maxLeftX = -1 << 31

        if part1 != x:
            minRightX = a[part1]
        else:
            minRightX = 1 << 31

        if part2 != 0:
            maxLeftY = b[part2 - 1]
        else:
            maxLeftY = -1 << 31

        if part2 != y:
            minRightY = b[part2]
        else:
            minRightY = 1 << 31

        if (maxLeftX <= minRightY and maxLeftY <= minRightX):
            if ((x + y) %2 == 0):
                return (max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2.0
            else:
                return max(maxLeftX, maxLeftY)
            break
        elif maxLeftX > minRightY:
            high = part1 - 1
        else:
            low = part1 + 1

    return 0