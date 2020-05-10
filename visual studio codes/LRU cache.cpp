#include <iostream>
#include <unordered_map>
using namespace std;

struct  Node {
	int val;
	struct Node* prev;
	struct Node *next;
};

struct Node* newNode(int val2) {
	struct Node* pt = (struct Node*)malloc(sizeof(Node));
	pt->val = val2;
	pt->prev = NULL;
	pt->next = NULL;
	return pt;
}

void LRUCache(vector<int> arr, int k) {
	unordered_map<int, Node*> mp;
	struct Node* head = newNode(arr[0]);
	struct Node* back = head;
	mp[arr[0]] = head;
	int count = 1;
	int pagefault = 1;
	for (int i = 1; i < arr.size(); i++) {
		if (count < k && mp.find(arr[i]) == mp.end()) {
			back->next = newNode(arr[i]);
			back->next->prev = back;
			back = back->next;
			mp[arr[i]] = back;
			count += 1;
		}
		else if (mp.find(arr[i]) != mp.end()) {
			struct Node* temp = mp[arr[i]];
			if (temp == back)
				continue;
			else if (temp == head) {
				head = head->next;
				head->prev = NULL;
			}
			else {
				temp->prev->next = temp->next;
				temp->next->prev = temp->prev;
			}
			temp->next = NULL;
			temp->prev = back;
			back->next = temp;
			back = temp;
		}
		else {
			if (count < k)
				count += 1;
			else {
				mp.erase(head->val);
				struct Node* temp2 = head;
				head = head->next;
				head->prev = NULL;
				temp2->next = NULL;
				free(temp2);
			}
			struct Node* temp = newNode(arr[i]);
			mp[arr[i]] = temp;
			back->next = temp;
			temp->prev = back;
			back = temp;
			
		}
	}
}