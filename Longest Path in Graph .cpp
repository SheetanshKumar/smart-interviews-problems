#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
using namespace std;

pair<int, int> BFSModified(vector<vector<int>> G, int s, int n) {
    queue<int> q;
    vector<int> vis(n+1, -1);
    q.push(s);
    vis[s] = 0;
    int count = 0;
    int node;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
            for (int v = 0; v < G[u].size(); v++) {
                if (vis[G[u][v]] == -1) {
                    q.push(G[u][v]);
                    vis[G[u][v]] = vis[u] + 1;
                    if(count < vis[u] + 1){
                        count = vis[u] + 1;
                        node = G[u][v];
                    }
                }
            }
    }

    return make_pair(node, count);
}


int main() {
    int t = 0;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> G(n + 1);
        for (int j = 0; j < m; j++) {
            int u, v;
            cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }

        if(G.size() == 1)
        {
            cout << G[0].size() << endl;
            continue;
        }
        pair<int, int> firstres = BFSModified(G, 1, n);
        pair<int, int> result = BFSModified(G, firstres.first, n);
        cout << result.second << endl;
    }

}