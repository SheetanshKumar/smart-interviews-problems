def evaluate(st):
    st = st.replace('|', ' ').replace('^', ' ').replace('&', ' ')
    arr = st.split()
    n = len(arr)
    tdp = [[0 for i in range(n+1)] for j in range(n+1)]
    fdp = [[0 for i in range(n+1)] for j in range(n+1)]
    oper = '|&^'
    print(arr)
    for i in range(n):
        if arr[i] == 'F':
            fdp[i][i] = 1
        else:
            tdp[i][i] = 1
    for g in range(1, n):
        i = 0
        for j in range(g, n):
            # tdp[i][j] = fdp[i][j] = 0
            for x in range(g):
                k = i+x
                total_ik = tdp[i][k] + fdp[i][k]
                total_kj = tdp[k+1][j] + fdp[k+1][j]
                print(total_ik, total_kj)
                if oper[k] == '&':
                    tdp[i][j] += (tdp[i][k] * tdp[k+1][j])
                    fdp[i][j] += (total_kj*total_ik - tdp[i][k] * tdp[k+1][j])
                elif oper[k] == '|':
                    tdp[i][j] += (total_ik*total_kj - fdp[i][k]*fdp[k+1][j])
                    fdp[i][j] += (fdp[i][k]*fdp[k+1][j])
                elif oper[k] == '^':
                    tdp[i][j] += (tdp[i][k]*fdp[k+1][j] + tdp[k+1][j]*fdp[i][k])
                    fdp[i][j] += (tdp[i][k] * tdp[k+1][j] + fdp[i][k]*fdp[k+1][j])
            i+=1
    return tdp[0][n-1]

print(evaluate("T|T|F&T"))