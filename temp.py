def reverseBits(n):
    count = 31
    res = 0

    while(n):
        res<<=1
        res = res | (n&1)
        n >>= 1
        count-=1
    res<<=(count+1)
    return res
