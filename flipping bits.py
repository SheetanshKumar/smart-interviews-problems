def flipBits(n):
    res = ""
    for _ in range(32):
        res = res + str((n&1)^1)
        n = n>>1
    return (int(res[::-1],2))

def flippingBits(n):
    return ((1<<32)-1)-n

def flippingBits2(n):
    return ((1<<32)-1)^n


if __name__ == '__main__':
    n = 4
    print("{:032b}".format(n))
    print(flipBits(n))

    print("{:032b}".format(flipBits(n)))
    print("{:032b}".format(flippingBits2(n)))