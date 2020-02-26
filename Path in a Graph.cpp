/*
Given an undirected graph, you have to find if there exists a path between 2 given nodes of the graph.

Input Format

First line of input contains T - number of test cases. First line of each test case contains N - number of nodes and M - number of edges. Its followed by M lines, each contains a pair (u,v) - denoting an undirected edge between node u and node v. The next line contains Q - number of queries. Its followed by Q lines, each contains a pair (u,v) - denoting an query to check if there exits a path between node u and node v.

Constraints

1 <= T <= 1000
1 <= N <= 100
0 <= M,Q <= min(N*N, 100)
1 <= u,v <= N

Output Format

For each test case, first print the test case number as shown. For each query of a test case, print "Yes" if path exists between the nodes of the query, print "No" otherwise, separated by newline.

Sample Input 0

2
5 3
1 3
2 4
3 2
4
1 5
3 4
4 5
1 4
10 9
3 4
5 1
2 5
4 6
2 3
6 3
1 4
8 9
8 10
5
2 4
8 4
9 10
10 5
9 7

Sample Output 0

Test Case #1:
No
Yes
No
Yes
Test Case #2:
Yes
No
Yes
No
No

*/

#include <iostream>
#include <utility>
#include <vector>

using namespace std;

bool pathExistsDFS(vector<vector<int>> &G, int src, int dest, vector<bool> &vis) {
    if (src == dest)
        return true;
    if (vis[src] == true)
        return false;
    vis[src] = true;
    for (int i = 0; i < G[src].size(); i++) {
        if (vis[G[src][i]] == false) {
            if (pathExistsDFS(G, G[src][i], dest, vis) == true)
                return true;
        }
    }
    return false;
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
        int q;
        cin >> q;
        cout << "Test Case #" << i + 1 << ":\n";
        for (int j = 0; j < q; j++) {
            int src, dest;
            cin >> src >> dest;
            vector<bool> vis(n+1, false);
            if (pathExistsDFS(G, src, dest, vis))
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }
}