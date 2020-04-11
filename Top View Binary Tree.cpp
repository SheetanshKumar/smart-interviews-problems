void topView(Node * root) {
    map<int, vector<int>> hm;
    queue<pair<Node *, int>> q;
    q.push(make_pair(root, 0));
    vector<int> v;
    hm.insert(make_pair(0, v));
    hm[0].push_back(root->data);
    while(!q.empty()){
        pair <Node *, int> temp = q.front();
        q.pop();
        if(temp.first->left){
            if(hm.find(temp.second -1) == hm.end()){
                vector<int> vec;
                hm.insert(make_pair(temp.second -1, vec));
            }
            hm[temp.second -1].push_back(temp.first->left->data);
            q.push(make_pair(temp.first->left, temp.second-1));
        }
        if(temp.first->right){
            if(hm.find(temp.second +1) == hm.end()){
                vector<int> vec;
                hm.insert(make_pair(temp.second +1, vec));
            }
            hm[temp.second +1].push_back(temp.first->right->data);
            q.push(make_pair(temp.first->right, temp.second+1));
        }

    }
    for (auto const& pair: hm)
        if(pair.second.size() > 0)
            cout << pair.second[0] << " ";

}

// using level order traversal and storing into ordered map for each vertical level.