#include<iostream>
#include<algorithm>
using namespace std;

string subsetSumProblem(int * arr, int n, int sum){
    bool dp[n+1][sum+1];
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= sum; j++){
            if(j==0)
                dp[i][j] = true;
            else
                dp[i][j] = false;
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= sum; j++){
            if(j < arr[i-1])
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j] | dp[i-1][j-arr[i-1]];
        }
    }
    if(dp[n][sum])
        return "YES";
    else
        return "NO";
}

string subsetPartitionSum(int * arr, int n){
    int sum = 0;
    for(int i = 0; i < n; i++)
        sum+=arr[i];
    if(sum&1 == 1)
        return "NO";
    sum = sum/2;
    return subsetSumProblem(arr, n, sum);
}

void solve(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    cout << subsetPartitionSum(arr, n) << endl;

}

bool isSum(int arr[],int i,int n, int total){
	if(i>=n)
		return false;
	if(arr[i]==total)
		return true;
	if(arr[i]>total)
		return false;
	return isSum(arr,i+1,n,total-arr[i]) || isSum(arr,i+1,n,total);
}

int main()
 {
	int t;
	cin >> t;
	while(t--)
	    solve();
	return 0;
}