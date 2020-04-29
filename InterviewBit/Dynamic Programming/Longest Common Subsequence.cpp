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

   int index = dp[a.size()][b.size()];
   char lcs[index+1];
   lcs[index] = '\0';

   int i = a.size(), j = b.size();
   while (i > 0 && j > 0)
   {

      if (a[i-1] == b[j-1])
      {
          lcs[index-1] = a[i-1];
          i--; j--; index--;
      }
      else if (dp[i-1][j] > dp[i][j-1])
         i--;
      else
         j--;
   }


    return dp[a.size()][b.size()];
}