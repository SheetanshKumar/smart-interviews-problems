#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
using namespace std;

pair<int, int> BFSModified(vector<vector<int>> &G, int s, int n) {
	queue<int> q;
	vector<int> vis(n+1, -1);
	q.push(s);
	vis[s] = 0;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
			for (int v = 0; v < G[u].size(); v++) {
				if (vis[G[u][v]] == -1) {
					q.push(G[u][v]);
					vis[G[u][v]] = vis[u] + 1;
				}
			}
	}
	int count = 0;
	int node;

	for (int i = 0; i < vis.size(); i++)
	{
		if (vis[i] > count) {
			count = vis[i];
			node = i;
		}
	}
	return make_pair(node, count);
}

/*
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
		pair<int, int> firstres = BFSModified(G, 1, n);
		pair<int, int> result = BFSModified(G, firstres.first, n);
		cout << result.second << endl;
	}
	
}*/