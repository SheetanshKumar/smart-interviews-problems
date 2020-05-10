#include <unordered_map>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define mod 1000000007
using namespace std;
unordered_map<int, int> mp;
int calc(char str[], int idx, int len, int ctr) {
	if (idx >= len) {
		return (ctr + 1) % mod;
	}
	if (mp.count(idx)) {
		// cout<<idx<<"->"<<mp[idx]<<endl;
		return ctr + mp[idx];
	}
	int temp = ctr;
	ctr = calc(str, idx + 1, len, ctr);
	if (idx + 1 < len) {
		if (str[idx] != '0' && (str[idx] - '0') * 10 + (str[idx + 1] - '0') <= 25) {
			ctr = calc(str, idx + 2, len, ctr);
		}
	}
	// cout<<idx<<" "<<mp[idx]<<endl;
	mp[idx] = (ctr - temp) % 1000000007;
	return ctr % mod;
}
/*
int main() {
	int t, len, str;
	cin >> t;
	while (t--) {
		int ctr = 0;
		char str[10009];
		mp.clear();
		cin >> len;
		for (int i = 0; i < len; i++)  cin >> str[i];
		ctr = calc(str, 0, len, ctr);
		cout << ctr << endl;
	}
	return 0;
}*/