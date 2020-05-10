#include <iostream>
#include <utility>
#include <vector>
#include <queue>
using namespace std;


bool isValidMove(int x, int y, int n, int m) {
	return (x <= n && y <= m && x > 0 && y > 0);
}

int knight(int n, int m, int C, int D, int E, int F) {

	if (C == E && D == F)
		return 0;
	queue<pair<int, int>> q;
	q.push(make_pair(C, D));
	vector<vector<int> > vis(n + 1, vector<int>(m + 1, 0));
	vis[C][D] = 1;
	int c = 0;
	while (!q.empty()) {
		vector<int> x = { 2, 2, 1, -1, -2, -2, 1, -1 };
		vector<int> y = { -1, 1, 2, 2, 1, -1, -2, -2 };
		c += 1;
		int qsize = q.size();
		for (int j = 0; j < qsize; j++) {
			pair<int, int> temp = q.front();
			q.pop();
			for (int i = 0; i < 8; i++) {
				int a = temp.first;
				int b = temp.second;
				if (isValidMove(x[i] + a, y[i] + b, n, m) && vis[x[i] + a][y[i] + b] == 0) {
					q.push(make_pair(x[i] + a, y[i] + b));
					vis[x[i] + a][y[i] + b] = 1;
					if (x[i] + a == E && y[i] + b == F)
						return c;
				}
			}
		}

	}
	return -1;

}

/*
int main() {
	cout << knight(8, 8, 1, 1, 8, 8);
}*/