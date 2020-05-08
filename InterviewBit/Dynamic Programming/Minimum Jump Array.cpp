#include<iostream>
using namespace std;

int minimumJumps(int *arr, int n){
    int dp[n];
    for(int i = 0; i < n; i++)
        dp[i] = 1<<31-1;
    if(arr[0] == 0)
        return -1;
    dp[0] = 0;
    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            if(j+arr[j] >= i && dp[j]+1 < dp[i]){
                dp[i] = dp[j]+1;
            }
        }
    }
    if(dp[n-1] == 1<<31-1)
        return -1;
    return dp[n-1];
}

void solve(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    cout << minimumJumps(arr, n) << endl;
}

int main()
 {
	int t;
	cin >> t;
	while(t--)
	    solve();
	return 0;
}