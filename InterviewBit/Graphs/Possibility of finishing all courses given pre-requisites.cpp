/*
https://www.interviewbit.com/problems/possibility-of-finishing-all-courses-given-prerequisites/
There are a total of A courses you have to take, labeled from 1 to A.

Some courses may have prerequisites, for example to take course 2 you have to first take course 1, which is expressed as a pair: [1,2].

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

Return 1 if it is possible to finish all the courses, or 0 if it is not possible to finish all the courses.

Input Format:

The first argument of input contains an integer A, representing the number of courses.
The second argument of input contains an integer array, B.
The third argument of input contains an integer array, C.

Output Format:

Return a boolean value:
    1 : If it is possible to complete all the courses.
    0 : If it is not possible to complete all the courses.

Constraints:

1 <= A <= 6e4
1 <= length(B) = length(C) <= 1e5
1 <= B[i], C[i] <= A

Example:

Input 1:
    A = 3
    B = [1, 2]
    C = [2, 3]

Output 1:
    1

Explanation 1:
    It is possible to complete the courses in the following order:
        1 -> 2 -> 3

Input 2:
    A = 2
    B = [1, 2]
    C = [2, 1]

Output 2:
    0

Explanation 2:
    It is not possible to complete all the courses.

*/


bool dfs(vector<vector<int>> &G, unordered_set<int> &white,  unordered_set<int> &grey,  unordered_set<int> &black, int vertex){
    white.erase(vertex);
    grey.insert(vertex);
    for(int i = 0; i < G[vertex].size(); i++){
        if(black.find(G[vertex][i]) != black.end())
            continue;
        if(grey.find(G[vertex][i]) != grey.end())
            return true;
        if(dfs(G, white, grey, black, G[vertex][i]))
            return true;
    }
    grey.erase(vertex);
    black.insert(vertex);
    return false;
}

bool canFinish(int n, vector<vector<int>>& pairs) {
    unordered_set<int> white;
    unordered_set<int> grey;
    unordered_set<int> black;
    for(int i = 0 ; i < n; i++){
       white.insert(i);
    }
    vector<vector<int>> G(n+1);
    for(int i = 0; i < pairs.size(); i++){
        G[pairs[i][0]].push_back(pairs[i][1]);
    }
    for (int i = 0; i < n; i++){
        if(white.find(i) == white.end())
            continue;
        if(dfs(G, white, grey, black, i))
            return false;
    }
    return true;
}

int Solution::solve(int A, vector<int> &B, vector<int> &C) {
    vector<vector<int>> pairs;
    for (int i = 0; i < B.size(); i++){
        vector<int> pair;
        pair.push_back(B[i]);
        pair.push_back(C[i]);
        pairs.push_back(pair);
    }
    return canFinish(A, pairs);
}
