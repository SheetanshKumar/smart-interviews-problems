struct  Node {
	int key, val;
	struct Node* prev;
	struct Node *next;
};

struct Node* newNode(int key, int val) {
	struct Node* pt = (struct Node*)malloc(sizeof(Node));
	pt->val = val;
	pt->key = key;
	pt->prev = NULL;
	pt->next = NULL;
	return pt;
}

unordered_map<int, int> newmap;
unordered_map<int, Node*> mp;
int k, c;
struct Node * head;
struct Node * back;
LRUCache::LRUCache(int capacity) {
    newmap.clear();
    mp.clear();
    k = capacity;
    c = 0;
    head = NULL;
    back = NULL;
}

int LRUCache::get(int key) {
    if(mp.find(key) == mp.end())
        return -1;

    struct Node* temp = mp[key];
    if (temp!= back && temp == head) {
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
	return newmap[key];
}

void LRUCache::set(int key, int value) {
    if(head == NULL){
        head = newNode(key, value);
        back = head;
        mp[key] = head;
        newmap[key] =value;
    }
    if (c < k && mp.find(key) == mp.end()) {
			back->next = newNode(key, value);
			back->next->prev = back;
			back = back->next;
			mp[key] = back;
			newmap[key] = value;
			c += 1;
	}
	else
	{
		if (c < k)
			c += 1;
		else {
			mp.erase(head->key);
			newmap.erase(key);
			struct Node* temp2 = head;
			head = head->next;
			head->prev = NULL;
			temp2->next = NULL;
			free(temp2);
		}
		struct Node* temp = newNode(key, value);
		mp[key] = temp;
		newmap[key] =value;
		back->next = temp;
		temp->prev = back;
		back = temp;
	}
}
