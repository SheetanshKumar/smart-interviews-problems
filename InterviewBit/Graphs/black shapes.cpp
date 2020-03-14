bool issafe(vector<string>& arr, vector<vector<bool>>& vis, int i, int j) {
	return (i >= 0 && j >= 0 && i < arr.size() && j < arr[0].size() && arr[i][j] == 'X' && vis[i][j] == false);
}


void bfs(vector<string>& arr, vector<vector<bool>>& vis, int x, int y) {

	int r[] = { -1, 1, 0, 0 };
	int c[] = { 0, 0, 1, -1 };
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	vis[x][y] = true;
	while (!q.empty()) {
		int i = q.front().first;
		int j = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
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
			if (arr[i][j] == 'X' && vis[i][j] == false)
			{
				bfs(arr, vis, i, j);
				ans += 1;
			}
		}
	}
	return ans;
}
int Solution::black(vector<string> &A) {
    if(A.size()==0 || A[0].size()==0)
        return 0;
    return findislands(A, A.size(), A[0].size());
}
