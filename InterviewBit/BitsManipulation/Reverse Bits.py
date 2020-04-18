def reverse(self, n):
    res = 0
    count = 31

    while (n):
        res <<= 1
        res = res | (n & 1)
        n >>= 1
        count -= 1
    res <<= (count + 1)
    return count