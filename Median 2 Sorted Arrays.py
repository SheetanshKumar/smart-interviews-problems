def findMedian(a, b):
    i = 0
    j = 0
    if ((len(a)+ len(b))%2 !=0):
        median = 0
        for k in range(((len(a)+ len(b))//2)+1):
            if(i != len(a) and j != len(b)):
                if (a[i] < b[j]):
                    median = a[i]
                    i+=1
                else:
                    median = b[j]
                    j+=1
            elif(i < len(a)):
                median = a[i]
                i+=1
            else:
                median = b[j]
                j+=1
        return median
    else:
        median = 0
        prev = 0
        for k in range(((len(a) + len(b)) // 2) + 1):
            prev = median
            if (i < len(a) and j < len(b)):
                if (a[i] < b[j]):
                    median = a[i]
                    i += 1
                else:
                    median = b[j]
                    j += 1
            elif (i < len(a)):
                median = a[i]
                i += 1
            else:
                median = b[j]
                j += 1
        return (prev + median)//2

a = [1, 1000]
b = [200, 2000]

print(findMedian(a, b))



