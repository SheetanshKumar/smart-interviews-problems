/*
https://www.interviewbit.com/problems/longest-consecutive-sequence/
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

Example:
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.
*/

int Solution::longestConsecutive(const vector<int> &arr) {
    unordered_set<int> st;
    for(int i = 0 ; i < arr.size(); i++){
        st.insert(arr[i]);
    }

    int count = 1;
    for(int i = 0 ; i < arr.size(); i++){
        int temp = 0;
        if(st.find(arr[i]-1)== st.end()){
            int a = arr[i];
            while(st.find(a) != st.end()){
                temp++;
                a++;
            }
        }
        if(temp>count)
            count = temp;
    }
    return count;
}
