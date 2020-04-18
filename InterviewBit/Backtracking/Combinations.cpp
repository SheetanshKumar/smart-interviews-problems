void getCombinations(vector<vector<int>> &ans, int start, int k, int curlen,
 vector<bool> &used, vector<int> &arr){
    if(curlen == k){
        vector<int> temp;
        for(int i = 0; i < arr.size(); i++){
            if(used[i]){
                temp.push_back(arr[i]);
            }
        }
        if(temp.size() == k)
                ans.push_back(temp);
        return;
    }
    if(start == arr.size())
            return;
    used[start] = true;
    getCombinations(ans, start+1, k, curlen+1, used, arr);
    used[start] = false;
    getCombinations(ans, start+1, k, curlen, used, arr);
}

vector<vector<int> > Solution::combine(int n, int k) {
    vector<int> arr;
    vector<vector<int>> ans;
    vector<bool> used(n, false);
    for(int i = 1; i <=n; i++){
        arr.push_back(i);
    }
    getCombinations(ans, 0, k, 0, used, arr);
    return ans;
}
