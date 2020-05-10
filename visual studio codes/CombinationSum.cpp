#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void createCombination(vector<int>& arr, int target, vector<vector<int>>& ans,
	vector<int>& temp, int idx) {
	if (target == 0) {
		ans.push_back(temp);
		return;
	}
	for (int i = idx; i < arr.size(); i++) {
		if (arr[i] > target)
			break;
		temp.push_back(arr[i]);
		createCombination(arr, target - arr[i], ans, temp, i);
		temp.pop_back();
	}
}

vector<vector<int>> getCombinationSumSet(vector<int> arr, int target) {
	vector<vector<int>> ans;
	vector<int> temp;
	vector<int> uniquearr;
	sort(arr.begin(), arr.end());
	for (int i = 0; i < arr.size(); i++) {
		if (i == 0 || arr[i] != arr[i - 1]) {
			uniquearr.push_back(arr[i]);
		}
	}
	createCombination(uniquearr, target, ans, temp, 0);
	return ans;
}
/*
int main()
{
	vector<int> arr = { 2,3,4,4 };
	int target = 8;
	vector<vector<int>> res = getCombinationSumSet(arr, target);
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[i].size(); j++) {
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
}*/