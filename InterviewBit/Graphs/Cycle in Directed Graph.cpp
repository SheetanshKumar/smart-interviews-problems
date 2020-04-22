bool dfs(vector<vector<int>> &G, unordered_set<int> &white,  unordered_set<int> &grey,  unordered_set<int> &black, int vertex){
    white.erase(vertex);
    grey.insert(vertex);
    for(int i = 0; i < G[vertex].size(); i++){
        if(black.find(G[vertex][i]) != black.end())
            continue;
        if(grey.find(G[vertex][i]) != white.end())
            return true;
        if(dfs(G, white, grey, black, G[vertex][i]))
            return true;
    }
    grey.erase(vertex);
    black.insert(vertex);
    return false;
}
bool canFinish(int n, vector<vector<int>>& pairs) {
    unordered_set<int> white;
    unordered_set<int> grey;
    unordered_set<int> black;
    for(int i = 0 ; i < n; i++){
       white.insert(i);
    }
    vector<vector<int>> G(n+1);
    for(int i = 0; i < pairs.size(); i++){
        G[pairs[i][0]].push_back(pairs[i][1]);
    }
    for (int i = 0; i < n; i++){
        if(white.find(i) == white.end())
            continue;
        if(dfs(G, white, grey, black, i))
            return false;
    }
    return true;
}