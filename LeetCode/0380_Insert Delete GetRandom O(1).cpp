#include <unordered_map>
#include <vector>
using namespace std;

class RandomizedSet {
	vector<int> vec;
	unordered_map<int, int> um;
public:
	RandomizedSet() {
		vec.clear();
		um.clear();
	}

	bool insert(int val) {
		if (um.count(val))
			return false;
		vec.resize(um.size() + 1);
		vec[um.size()] = val;
		um[val] = um.size();
		return true;
	}

	bool remove(int val) {
		if (um.count(val))
		{
			swap(vec[um[val]], vec[um.size() - 1]);
			um[vec[um[val]]] = um[val];
			um.erase(val);
			return true;
		}
		return false;
	}

	int getRandom() {
		int r = rand() % um.size();
		return vec[r];
	}
};

/**
* Your RandomizedSet object will be instantiated and called as such:
* RandomizedSet* obj = new RandomizedSet();
* bool param_1 = obj->insert(val);
* bool param_2 = obj->remove(val);
* int param_3 = obj->getRandom();
*/