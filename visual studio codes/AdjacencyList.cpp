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
		int q;
		cin >> q;
		cout << "Test Case #" << i + 1 << ":\n";
		for (int j = 0; j < q; j++) {
			int src, dest;
			cin >> src >> dest;
			vector<bool> vis(n + 1, false);
			if (pathExistsDFS(G, src, dest, vis))
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
		}
	}
}*/