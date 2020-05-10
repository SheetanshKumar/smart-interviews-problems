#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
using namespace std;

pair<int, int> BFSModified2(vector<vector<int>>& G, int s, int n) {
	queue<int> q;
	vector<int> vis(n + 1, -1);
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

void printGraph(vector<vector<int>> &G) {
	for (int i = 0; i < G.size(); i++) {
		for (int j = 0; j < G[i].size(); j++)
		{
			cout << G[i][j] << "\t";
		}
		cout << endl;
	}
}

int solve(vector<int>& A) {
	if (A.size() == 1 && A[0] == -1)
		return 0;

	int n, m;
	n = A.size();
	m = n - 1;
	vector<vector<int>> G(n + 1);
	for (int j = 0; j < m+1; j++) {
		int u, v;
		u = j;
		v = A[j];
		if(v == -1)
			continue;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	printGraph(G);
	pair<int, int> firstres = BFSModified2(G, 1, n);
	pair<int, int> result = BFSModified2(G, firstres.first, n);
	return result.second;
}

/*
int main()
{
	vector<int> A {-1};
	//int n;
	//cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		A.push_back(x);
	}
	cout << solve(A);
	return 0;
}*/