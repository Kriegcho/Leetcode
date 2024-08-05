#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
	string kthDistinct(vector<string>& arr, int k) {
		unordered_map<string, int> um;
		for (const auto& s : arr)
			um[s]++;
		int ind = 0;
		for (const auto& s : arr)
			if (um[s] == 1)
			{
				ind++;
				if (ind == k)
					return s;
			}
		return "";
	}
};