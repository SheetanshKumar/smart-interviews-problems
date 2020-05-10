#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

bool issafe(vector<string>& arr, vector<vector<bool>>& vis, int i, int j) {
	return (i >= 0 && j >= 0 && i < arr.size() && j < arr[0].size() && arr[i][j] == '1' && vis[i][j] == false);
}


void bfs(vector<string>& arr, vector<vector<bool>>& vis, int x, int y) {

	int r[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
	int c[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	vis[x][y] = true;
	while (!q.empty()) {
		int i = q.front().first;
		int j = q.front().second;
		q.pop();
		for (int k = 0; k < 8; k++) {
			if (issafe(arr, vis, i + r[k], j + c[k])) {
				vis[i + r[k]][j + c[k]] = true;
				q.push(make_pair(i + r[k], j + c[k]));
			}
		}
	}
}

int findislands(vector<string>& arr, int r, int c) {
	int ans = 0;
	vector<vector<bool>> vis(r, vector<bool>(c, false));
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++)
		{
			if (arr[i][j] == '1' && vis[i][j] == false)
			{
				bfs(arr, vis, i, j);
				ans += 1;
			}
		}
	}
	return ans;
}

/*
int main() {
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int r, c;
		cin >> r >> c;
		vector<string> arr;
		for (int j = 0; j < r; j++)
		{
			string s;
			cin >> s;
			arr.push_back(s);
		}
		cout << findislands(arr, r, c) << endl;
	}
}*/