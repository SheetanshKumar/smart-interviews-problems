#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
using namespace std;

typedef struct TrieNode {
	struct TrieNode* arr[2];
};

TrieNode* createNewNode() {
	TrieNode* node = new TrieNode;
	node->arr[0] = NULL;
	node->arr[1] = NULL;
	return node;
}

int checkBits(int x, int i) {
	return x & (1 << (i));
}

TrieNode* createTrie(TrieNode* node, vector<int> arr) {
	TrieNode* temp = node;
	for (int j = 0; j < arr.size(); j++) {
		temp = node;
		for (int i = 31; i >= 0; i--) {
			int pos = (checkBits(arr[j], i)) ? 1 : 0;
			if (pos == 1) {
				if (temp->arr[1] == NULL) {
					TrieNode* newnode = createNewNode();
					temp->arr[1] = newnode;
				}
				temp = temp->arr[1];
			}
			else {
				if (temp->arr[0] == NULL) {
					TrieNode* newnode = createNewNode();
					temp->arr[0] = newnode;
				}
				temp = temp->arr[0];
			}
		}
	}
	return node;
}

int getMaxXor(TrieNode* node, vector<int> arr) {
	TrieNode* temp = node;
	int ans = 0;
	for (int i = 0; i < arr.size(); i++) {
		int tempans = 0;

		//string s = bitset<32>(arr[i]).to_string();
		//cout << s << "\t"<< arr[i]<< endl;
		node = temp;
		for (int j = 31; j >= 0; j--) {
			int pos = checkBits(arr[i], j) ? 1 : 0;
			if (pos == 0) {
				if (node->arr[1] != NULL) {
					tempans = (tempans << 1) | 1;
					node = node->arr[1];
				}
				else {
					tempans = (tempans << 1);
					node = node->arr[0];
				}
			}
			else {
				if (node->arr[0] != NULL) {
					tempans = (tempans << 1);
					node = node->arr[0];
				}
				else {
					tempans = (tempans << 1) | 1;
					node = node->arr[1];
				}
			}

		}
		ans = max(tempans^arr[i], ans);
	}
	return ans;
}
/*
int main() {
	int t;
	cin >> t;
	while (t--) {
		TrieNode* node = createNewNode();
		int n;
		cin >> n;
		vector<int> arr(n, 0);
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		node = createTrie(node, arr);
		cout << getMaxXor(node, arr) << endl;
	}

	return 0;
}
*/
/*
Test case:
2
3
12 15 9
5
13 11 35 3 32


*/