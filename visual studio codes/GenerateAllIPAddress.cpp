#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
using namespace std;

void generateIP(string s, int idx, unordered_set<string> &ans, vector<int> segments, int count) {

	if (idx == s.size() && count == 4) {
		string s = to_string(segments[0]) + '.'+to_string(segments[1]) + '.' + to_string(segments[2]) 
			+ '.' + to_string(segments[3]);
		//cout << s << endl;
		ans.insert(s);
		return;
	}
	if (count >= 4)
		return;
	for (int i = 1; i <= 3; i++) {
		if (idx+i > s.size())
			break;
		string temp = s.substr(idx, i);
		int val = stoi(temp);
		if (val > 255 || (temp[0] == '0' && temp.size() > 1))
			break;
		segments[count] = val;
		generateIP(s, idx + i, ans, segments, count+1);
		segments[count] = -1;
	}
}
/*
int main() {
	string s = "11211";
	unordered_set<string> res;
	string current = "";
	vector<int> segments(4);
	//string temp = "We think";
	//cout << temp.substr(3, 3);
	generateIP(s, 0, res, segments, 0);
	for (auto s: res)
		cout <<s << endl;
	return 0;
}*/