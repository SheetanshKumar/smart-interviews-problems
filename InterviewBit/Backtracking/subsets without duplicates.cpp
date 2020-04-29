void subset(vector<int> &A,vector<vector<int>> &ans,vector<int> temp,int index)
{
    if (find(ans.begin(), ans.end(), temp) == ans.end())
        ans.push_back(temp);

    for(int i=index;i<A.size();i++)
    {
        temp.push_back(A[i]);
        subset(A,ans,temp,i+1);
        temp.pop_back();
    }
    return;
}
vector<vector<int> > Solution::subsetsWithDup(vector<int> &A) {
vector<vector<int> > ans;
   sort(A.begin(), A.end());
   vector<int> temp;
   subset(A, ans, temp ,0);
return ans;
}