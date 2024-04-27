#include <unordered_map>

class Solution {
	std::unordered_map<int, int> um;
public:
	int tribonacci(int n) {
		if (n == 0)
			um[n] = 0;
		else if (n <= 2)
			um[n] = 1;
		else
		{
			um[n] = (um.count(n - 1) ? um[n - 1] : tribonacci(n - 1))
				+ (um.count(n - 2) ? um[n - 2] : tribonacci(n - 2))
				+ (um.count(n - 3) ? um[n - 3] : tribonacci(n - 3));
		}
		return um[n];
	}
};