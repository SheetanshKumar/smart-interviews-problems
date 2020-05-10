#include <iostream>
using namespace std;

typedef struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {};
	
};


ListNode* findMid(ListNode* head) {
	if (head == NULL || head->next == NULL) {
		return head;
	}
	ListNode* slow = head;
	ListNode* fast = head;

	fast = head->next;
	while (fast != NULL) {
		fast = fast->next;
		if (fast != NULL) {
			slow = slow->next;
			fast = fast->next;
		}
	}
	return slow;
	/*
	while (fast != NULL && fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;*/
}

ListNode* merge(ListNode* head1, ListNode* head2) {
	ListNode* head = NULL;
	ListNode* temp = NULL;
	while (head1 != NULL && head2 != NULL) {
		if (head1->val <= head2->val) {
			if (head == NULL) {
				head = head1;
				temp = head;
			}
			else {
				temp->next = head1;
				temp = temp->next;
			}
			head1 = head1->next;
		}
		else {
			if (head == NULL) {
				head = head2;
				temp = head;
			}
			else {
				temp->next = head2;
				temp = temp->next;

			}
			head2 = head2->next;
		}
	}
	while (head1 != NULL) {
		temp->next = head1;
		temp = temp->next;
		head1 = head1->next;
	}
	while (head2 != NULL) {
		temp->next = head2;
		temp = temp->next;
		head2 = head2->next;
	}
	return head;
}

ListNode* mergeSort(ListNode* head) {
	if (head == NULL || head->next == NULL)
		return head;
	ListNode* mid = findMid(head);
	ListNode* head2 = mid->next;
	mid->next = NULL;
	return merge(mergeSort(head), mergeSort(head2));
}
/*
int main() {
	struct ListNode* node = new ListNode(0);
	struct ListNode* pt = node;
	pt->next = new ListNode(1);
	pt = pt->next;
	pt->next = new ListNode(2);
	pt = pt->next;
	pt->next = new ListNode(300);
	pt = pt->next;
	pt->next = new ListNode(15);
	pt = pt->next;
	pt->next = new ListNode(20);

	struct ListNode* node2 = new ListNode(1);
	pt = node2;
	pt->next = new ListNode(6);
	pt = pt->next;
	pt->next = new ListNode(8);
	pt = pt->next;
	pt->next = new ListNode(16);
	pt = pt->next;
	pt->next = new ListNode(19);
	pt = pt->next;
	pt->next = new ListNode(25);
	

	//ListNode * sorted= merge(node, node2);

	ListNode* sorted = mergeSort(node);
	while (sorted != NULL) {
		cout << sorted->val << " ";
		sorted = sorted->next;
	}
}*/