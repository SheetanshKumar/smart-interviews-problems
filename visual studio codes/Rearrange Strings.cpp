#include <iostream>
#include <queue>
#include <utility>
using namespace std;

void solve_arrange() {
	string s;
	cin >> s;
	priority_queue<pair<int, char>> maxHeap;

	int count[26] = { 0 };
	for (int i = 0; i < s.size(); i++)
		count[s[i] - 'a']++;
	for (char c = 'a'; c <= 'z'; c++)
		if (count[c - 'a'] != 0)
			maxHeap.push(make_pair(count[c - 'a'], c));
	// 	for(int i = 0; i < 26; i++)
	// 	    cout << count[i] << " ";
	// 	cout << endl;
	string ans = "";
	pair<int, char> prev;
	prev = make_pair(-1, '0');
	while (!maxHeap.empty()) {
		pair<int, char> current = maxHeap.top();
		maxHeap.pop();
		ans = ans + current.second;

		if (prev.first > 0)
			maxHeap.push(prev);
		current = make_pair(current.first - 1, current.second);
		prev = current;
	}
	//cout << ans << endl;
	if (ans.size() != s.size())
		cout << 0 << endl;
	else
		cout << 1 << endl;
}

/*
int main() {
	int t;
	cin >> t;
	while (t--) {
		solve_arrange();
	}
}*/