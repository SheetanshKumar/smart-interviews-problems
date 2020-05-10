#include <iostream>
#include <utility>
#include <vector>
#include <queue>

using namespace std;



void bfs(vector<vector<int>>& G, int x, vector<bool>& vis) {
	queue<int> q;
	q.push(x);
	vis[x] = true;

	while (!q.empty()) {
		int y = q.front();
		q.pop();
		for (int i = 0; i < G[y].size(); i++) {
			if (!vis[G[y][i]])
				q.push(vis[G[y][i]]);
		}
	}
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
		vector<bool> vis(n + 1, false);
		for (int j = 0; j < n; j++) {
			int count = 0;

		}
	}
}*/