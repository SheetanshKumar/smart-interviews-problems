/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
typedef pair<int, ListNode*> pi;
ListNode * mergeKSorted(vector<ListNode*> &A, priority_queue<pi, vector<pi>, greater<pi> > &pq)
{
    pi top = pq.top();
    pq.pop();
    if(top.second->next != NULL)
    {
        pq.push(make_pair(top.second->next->val, top.second->next));
    }
    ListNode * head = new ListNode(top.first);
    ListNode * ptr = head;
    while(!pq.empty()){
        top = pq.top();
        pq.pop();
        ListNode *temp = new ListNode(top.first);
        ptr->next = temp;
        ptr = ptr->next;
        if(top.second->next != NULL)
        {
            pq.push(make_pair(top.second->next->val, top.second->next));
        }
    }
    return head;
}


ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
      priority_queue<pi, vector<pi>, greater<pi> > pq;

      for(int i = 0 ; i < A.size(); i++){
          pq.push(make_pair(A[i]->val, A[i]));
      }
      return mergeKSorted(A, pq);
}
