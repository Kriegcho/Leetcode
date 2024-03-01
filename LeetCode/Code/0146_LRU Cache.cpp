#include <unordered_map>
#include <list>

class LRUCache {
	std::unordered_map<int, int> keyVal;
	std::list<int> cache;
	using iter = std::list<int>::iterator;
	std::unordered_map<int, iter> map;
	int cap;
public:
	LRUCache(int capacity) {
		cap = capacity;
	}

	int get(int key) {
		if (keyVal.find(key) != keyVal.end())
		{
			if (map.find(key) != map.end())
			{
				cache.erase(map[key]);
				cache.push_back(key);
				iter end = cache.end();
				map[key] = --end;
			}
			return keyVal[key];
		}
		return -1;
	}

	void put(int key, int value) {
		if (map.find(key) != map.end())
			cache.erase(map[key]);
		else
		{
			int n = cache.size();
			if (n >= cap)
			{
				keyVal[cache.front()] = -1;
				map.erase(cache.front());
				cache.pop_front();
			}
		}
		cache.push_back(key);
		iter end = cache.end();
		map[key] = --end;
		keyVal[key] = value;
	}
};