#include <iostream>
#include <vector>
using namespace std;

class MinHeap
{

public:
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
		if (size() > 1)
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
		while ((2 * idx + 1 < v.size() && v[idx] > v[2 * idx + 1]) || (2 * idx < v.size() && v[idx] > v[2 * idx]))
		{
			if (2 * idx + 1 < v.size()) {
				if (v[2 * idx + 1] > v[2 * idx]) {
					swap(v[idx], v[2 * idx]);
					idx = 2 * idx;
				}
				else {
					swap(v[idx], v[2 * idx + 1]);
					idx = 2 * idx + 1;
				}
			}
			else {
				swap(v[idx], v[2 * idx]);
				idx = 2 * idx;
			}
		}
	}
};

/*
int main()
{
	MinHeap obj1;
	obj1.insert(5);
	obj1.insert(2);
	obj1.insert(100);
	cout << obj1.getMin() << endl;
	obj1.deleteMin();
	//obj1.deleteMin();
	cout << obj1.getMin() << endl;
}
//*/