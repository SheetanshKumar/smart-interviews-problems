for _ in range(int(input())):
    n = int(input())
    ar = list(input())
    # print(ar)
    st = [ar[0]]
    mp = dict()
    mp[0] = 1
    for i in range(1, n):
        # print(ar[i])
        if(ar[i] != ar[i-1]):
            st[-1] = st[-1]+ar[i]
            mp[i] = len(st)
        else:
            flag = 0
            for j in range(len(st)):
                if st[j][-1] != ar[i]:
                    st[j] = st[j]+ar[i]
                    mp[i] = j+1
                    flag =1
                    break;
            if flag == 0:
                st.append(ar[i])
                mp[i] = len(st)
    print(len(st))
    # print(mp)
    for i in list(sorted(mp.keys())):
        print(mp[i], end=' ')
    print("")



