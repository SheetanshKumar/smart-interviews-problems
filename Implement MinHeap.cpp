//https://www.hackerrank.com/contests/smart-interviews/challenges/si-implement-min-heap/copy-from/1320540950

/*Perform Insert, delMin and getMin operations on a Min Heap. Implement Min Heaps and avoid using inbuilt library.

Input Format

First line of input contains T - number of operations. Its followed by T lines, each line contains either "insert x" or "delMin" or "getMin".

Constraints

1 <= T <= 106
-109 <= x <= 109

Output Format

For each "getMin" operation, print the minimum element, separated by newline. If the heap is empty, print "Empty".

Sample Input 0

10
insert 5
getMin
delMin
getMin
insert -15
insert 10
insert -30
getMin
delMin
getMin

Sample Output 0

5
Empty
-30
-15

*/

#include <bits/stdc++.h>
using namespace std;

class MinHeap
{

public :
    vector<int> v;
    MinHeap() {
        v.push_back(-1);
    }

    int size() {
        return v.size();
    }

    void insert(int x) {
        v.push_back(x);
        int idx = v.size() - 1;

        while (idx > 1 && v[idx] < v[idx / 2]) {
            swap(v[idx], v[idx / 2]);
            idx = idx / 2;
        }
    }

    int getMin() {
      // printf("%d\n", size());
        if(size() > 1)
            return v[1];
        else
            return INT_MAX;
    }

   void deleteMin() {
        if (v.size() <= 1)
        {
            //cout << "stack empty" << endl;
            return;
        }
        int element = v[v.size() - 1];
        v[1] = element;
        v.pop_back();
        int idx = 1;
        while((2*idx +1 < v.size() && v[idx] > v[2 * idx+1])
        || (2*idx < v.size() && v[idx] > v[2 * idx]))
        {
            if(2*idx +1 < v.size()){
                if (v[2*idx+1] > v[2*idx]){
                    swap(v[idx], v[2 * idx]);
                    idx = 2 * idx;
                }
                else{
                    swap(v[idx], v[2 * idx+1]);
                    idx = 2 * idx+1;
                }
            }
            else{
                 swap(v[idx], v[2 * idx]);
                 idx = 2 * idx;
            }
        }
    }
};


int main() {
   int t;
    cin >> t;
    MinHeap obj;
    //obj.v.push_back(-1);
    for(int i = 0 ; i < t; i++){
        string st;
        cin >> st;
        if (st[0] ==  'i'){
            int n;
            cin >> n;
            obj.insert(n);
            //printf("%d\n", obj.size());
        }
        else if(st[0] == 'g'){
            int x = obj.getMin();
            if(x != INT_MAX)
                printf("%d\n", x);
            else
                printf("Empty\n");
        }
        else{
            obj.deleteMin();
        }
    }
    return 0;
}
