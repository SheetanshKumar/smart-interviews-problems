def permutations(st, l, r, all):
    if l == r:
        all.append(''.join(st))


    for i in range(l, r+1):
        st[l], st[i] = st[i], st[l]
        permutations(st, l+1,r, all)
        st[l], st[i] = st[i], st[l]
    return all

def permute(st):
    def permutations(st, l, r, all):
        if l == r:
            all.append(st)

        for i in range(l, r + 1):
            st[l], st[i] = st[i], st[l]
            permutations(st, l + 1, r, all)
            st[l], st[i] = st[i], st[l]
        return all
    return permutations(st, 0, len(st)-1, [])

if __name__ == '__main__':
    st = list("123")
    print([list(i) for i in list(permutations(st, 0, len(st)-1, []))])
    print(permute([1,2,3]))
