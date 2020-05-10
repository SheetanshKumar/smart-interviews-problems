#include <iostream>
#include <vector>
#include <string>

using namespace std;


bool isValid(vector<vector<int>> mat, int x, int y, int n) {
	int xi[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
	int yi[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

	for (int i = 0; i < 8; i++) {
		if (x + xi[i] >= 0 && x + xi[i] < n && y + yi[i] < n && y + yi[i] >= 0)
		{
			if (mat[x + xi[i]][y + yi[i]] == 1)
				return false;
		}
	}
	return true;
}

bool checkNqueen(vector<vector<int>> mat, int n) {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (mat[i][j] == 1) {
				cnt += 1;
				if (!isValid(mat, i, j, n))
					return false;
			}
		}
	}
	return cnt==n;
}

void printMatrix(vector<vector<int>> mat, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << mat[i][j] << " ";
		cout << endl;
	}
	cout << endl;
}

bool getNQueenUtil(vector<vector<int>> mat, int cidx, int n, vector<vector<vector<int>>> &ans) {

	if (cidx >= n)
		return true;

	for (int i = cidx; i < n; i++) {
		mat[i][cidx] = 1;
		if (isValid(mat, i, cidx, n)) {
			
			//printMatrix(mat, n);
			if (getNQueenUtil(mat, cidx + 1, n, ans))
			{
				printMatrix(mat, n);
				if (checkNqueen(mat, n))
					ans.push_back(mat);
				return true;
			}
			
		}	
		mat[i][cidx] = 0;
	}
	return false;
}

void getNQueen(int n, vector<vector<vector<int>>> &ans) {
	vector<vector<int>> mat(n + 1, vector<int>(n + 1, 0));
	printMatrix(mat, n);
	getNQueenUtil(mat, 0, n, ans);
}
/*
int main() {
	int n = 4;
	vector<vector<vector<int>>> ans;
	getNQueen(n, ans);
	for (int k = 0; k < ans.size(); k++) {
		printMatrix(ans[k], n);
		cout << endl;
	}
	return 0;
}*/