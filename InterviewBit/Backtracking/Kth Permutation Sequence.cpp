void permute(vector<int> &num, int start) {
    if (start == num.size() - 1) {
        for(int i = 0 ; i < num.size(); i++){
                cout<<to_string(num[i]);
            }
        cout<<endl;
        return;
    }
    for (int i = start; i < num.size(); i++) {
        swap(num[start], num[i]);
        permute(num, start + 1);
        swap(num[start], num[i]);
    }
}


void getPUtil(vector<int> &arr, vector<vector<int>> &ans, int idx, int &k, string &mainans){
    // if(k==0)
    //     return;
    if(idx == arr.size()-1){
        for(int i = 0 ; i < arr.size(); i++){
               // cout<<to_string(arr[i]);
            }
        cout<<endl;
        if(k==1){
            for(int i = 0 ; i < arr.size(); i++){
                mainans.append(to_string(arr[i]));
            }
        }
        k--;
        return;
    }
    for(int i = idx; i < arr.size(); i++){
        swap(arr[idx], arr[i]);
        getPUtil(arr, ans, idx+1, k, mainans);
        swap(arr[idx], arr[i]);
    }
}

string getP(vector<int> arr, int k){
    vector<vector<int>> ans;
    permute(arr, 0);
    string mainans="";
    getPUtil(arr, ans, 0, k, mainans);
    return mainans;
}

string Solution::getPermutation(int n, int k) {
    vector<int> arr;
    for(int i = 1; i <= n; i++)
        arr.push_back(i);
    return getP(arr, k);
}
