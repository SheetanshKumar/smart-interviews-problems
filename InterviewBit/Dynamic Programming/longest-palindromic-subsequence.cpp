class Solution {
public:

    int longestCommonSubsequence(string a, string b) {
    int dp[a.size()+1][b.size()+1];

    for (int i = 0; i <= a.size(); i++){
        for (int j = 0; j <= b.size(); j++){
            if(i == 0 || j == 0)
                dp[i][j] = 0;
            else if(a[i-1] == b[j-1]){
                dp[i][j] = dp[i-1][j-1]+1;
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[a.size()][b.size()];
}
    int longestPalindromeSubseq(string s) {
        string rev =s;
        reverse(rev.begin(), rev.end());
        return longestCommonSubsequence(s, rev);
    }
};