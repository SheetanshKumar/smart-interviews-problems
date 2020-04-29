const int MOD = 1003;
vector<char> oprator, operand;
vector<vector<int> > T, F;
int solve() {
    int n = operand.size();
    for(int i = 0; i < n; ++i) {
        if(operand[i] == 'T')
            T[i][i] = 1;
        else
            F[i][i] = 1;
    }
    for (int l = 2; l <= n; ++l) {
        for (int i = 0; i < n-l+1; ++i) {
            int j = i+l-1;
            for (int k = i; k < j; ++k) {
                if(oprator[k] == '&') {
                    T[i][j] += T[i][k] * T[k+1][j];
                    T[i][j] %= MOD;
                    F[i][j] += ((T[i][k]+F[i][k])*(T[k+1][j]+F[k+1][j]))
                                -T[i][k] * T[k+1][j];
                    F[i][j] %= MOD;
                }
                else if(oprator[k] == '|') {
                    F[i][j] += F[i][k] * F[k+1][j];
                    F[i][j] %= MOD;
                    T[i][j] += ((T[i][k]+F[i][k])*(T[k+1][j]+F[k+1][j]))
                                -F[i][k] * F[k+1][j];
                    T[i][j] %= MOD;
                }
                else {
                    T[i][j] += (T[i][k] * F[k+1][j]) + (F[i][k] * T[k+1][j]);
                    T[i][j] %= MOD;
                    F[i][j] += ((T[i][k]+F[i][k])*(T[k+1][j]+F[k+1][j]))
                                -((T[i][k] * F[k+1][j]) + (F[i][k] * T[k+1][j]));
                    F[i][j] %= MOD;
                }
            }
        }
    }
    return T[0][n-1];
}
int Solution::cnttrue(string str) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n = str.size();
    if(n <= 0) return 0;
    oprator.clear();
    operand.clear();
    for (int i = 0; i < n; i+=2) {
        operand.push_back(str[i]);
    }
    for (int j = 1; j < n; j+=2) {
        oprator.push_back(str[j]);
    }
    T.clear(); F.clear();
    T.resize(operand.size()+1, vector<int>(operand.size()+1, 0));
    F.resize(operand.size()+1, vector<int>(operand.size()+1, 0));
    return solve();
}

