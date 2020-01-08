def generatePrimes(n):
    all = [True]*(n+1)
    all[0] = False
    all[1] = False

    for i in range(2,int(n**(0.5))+1):
        if (all[i] == True):
            pr = i+i
            while(pr <= n):
                all[pr] = False
                pr += i
    res = [i for i in range(len(all)) if all[i]]
    print(res)
    # for i in range(len(all)):
    #     if all[i]:
    #         res.append()

if __name__ == '__main__':
    generatePrimes(1000000)