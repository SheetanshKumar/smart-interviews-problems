#include <iostream>
#include <vector>
using namespace std;

bool isPalindrome(string str, int x, int y) {
	while (x<y)
		if (str[x++] != str[y--])
			return false;
	
	return true;
}

void getPartition(string str, vector<string> temp, vector<vector<string>>& ans, int idx) {
	if (idx == str.length())
	{
		ans.push_back(temp);
		return;
	}
	for (int i = idx; i < str.size(); i++) {
		if (isPalindrome(str, idx, i)) {
			//cout << str.substr(idx, i) << endl;
			temp.push_back(str.substr(idx, i+1-idx));
			getPartition(str, temp, ans, i + 1);
			temp.pop_back();
		}
	}
}


vector<vector<string>> palindromicPartition(string str) {
	vector <string> temp;
	vector<vector<string>> ans;
	int c = 0;
	getPartition(str, temp, ans, 0);
	return ans;
}

/*
int main()
{
	string s = "aab";
	vector<vector<string>> res = palindromicPartition(s);
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[i].size(); j++)
			cout << res[i][j] << " ";
		cout << endl;
	}
}*/