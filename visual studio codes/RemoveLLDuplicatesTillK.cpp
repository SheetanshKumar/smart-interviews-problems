#include <iostream>
using namespace std;

typedef struct Node {
	int val;
	Node* next;
	Node(int x) : val(x), next(NULL) {};
};


Node* solve(Node* head, int k) {
	Node* ptr = head;
	while (ptr != NULL) {
		int count = 0;
		while (ptr->next != NULL && ptr->next->val == ptr->val) {
			count++;
			if (count == k)
				break;
			ptr = ptr->next;
		}
		if (count == k) {
			Node* temp = ptr;
			int flag = 0;
			while (temp->next != NULL && temp->next->val == temp->val) {
				flag = 1;
				temp = temp->next;
			}
			if (flag == 0)
				ptr->next = temp;
			else
				ptr->next = temp->next;
		}
		ptr = ptr->next;
	}
	return head;
}

int main() {
	Node* head = new Node(1);
	Node* ptr = head;
	ptr->next = new Node(1);
	ptr = ptr->next;
	ptr->next = new Node(1);
	ptr = ptr->next;
	ptr->next = new Node(1);
	ptr = ptr->next;
	ptr->next = new Node(1);
	ptr = ptr->next;
	ptr->next = new Node(1);
	ptr = ptr->next;
	ptr->next = new Node(1);
	ptr = ptr->next;
	ptr->next = new Node(1);
	ptr = ptr->next;
	ptr->next = NULL;
	int k = 3;
	//Node* result = head;
	Node* result = solve(head, k);
	while (result != NULL)
	{
		cout << result->val << " ";
		result = result->next;
	}
}