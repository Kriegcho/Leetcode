#include <set>

class MedianFinder {
	std::multiset<int> s;
	std::multiset<int>::iterator it;
public:
	MedianFinder() {
		it = s.end();
	}

	void addNum(int num) {
		s.insert(num);
		if (it == s.end())
			it = s.begin();
		else
		{
			int n = s.size();
			if (n % 2 == 1 && num >= *it)
				it++;
			if (n % 2 == 0 && num < *it)
				it--;
		}
	}

	double findMedian() {
		int n = s.size();
		if (n % 2 == 0)
		{
			double ans = 1.0 * (*it + *++it) / 2;
			it--;
			return ans;
		}
		else
			return *it;
	}
};