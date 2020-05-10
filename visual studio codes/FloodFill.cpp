#include <iostream>
using namespace std;

int arr[100][100];

bool isValid(int x, int y, int n, int m, int prev) {
	return (x >= 0 && y >= 0 && x < n && y < m && arr[x][y] == prev);
}
void floodfill(int n, int m, int k, int x, int y, int prev) {

	if (isValid(x, y, n, m, prev)) {
		arr[x][y] = k;
	}
	else
		return;

	floodfill(n, m, k, x + 1, y, prev);
	floodfill(n, m, k, x - 1, y, prev);
	floodfill(n, m, k, x, y + 1, prev);
	floodfill(n, m, k, x, y - 1, prev);
}

void solve() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	int x, y, k;
	cin >> x >> y >> k;
	floodfill(n, m, k, x, y, arr[x][y]);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << arr[i][j] << " ";
		}
	}
	cout << endl;
}
/*
int main() {
	int t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}*/