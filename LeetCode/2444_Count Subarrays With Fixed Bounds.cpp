#include <vector>
using namespace std; 

class Solution {
	long long solve(int l, int r, vector<int>& nums, int minK, int maxK)
	{
		long long res = 0;
		if (minK == maxK)
		{
			res = (r - l);
			res *= (r - l - 1);
			res /= 2;
			return res;
		}

		int minpos = -1, maxpos = -1;
		int le = l;
		for (int i = l + 1; i < r; i++)
		{
			if (nums[i] == minK && minpos == -1)
				minpos = i;
			if (nums[i] == maxK && maxpos == -1)
				maxpos = i;
			if (minpos != -1 && maxpos != -1)
				break;
		}
		if (minpos == -1 || maxpos == -1)
			return 0;
		bool flag = minpos < maxpos;
		while (1)
		{
			long long lc = (flag ? minpos : maxpos) - le;
			long long rc = r - (flag ? maxpos : minpos);
			res += lc * rc;
			le = (flag ? minpos : maxpos);

			bool find = false;
			for (int i = (flag ? minpos : maxpos) + 1; i < r; i++)
			{
				int& pos = flag ? minpos : maxpos;
				if (nums[i] == (flag ? minK : maxK))
				{
					pos = i;
					find = true;
					break;
				}
			}
			if (!find)
				break;
			flag = minpos < maxpos;
		}
		return res;
	}
public:
	long long countSubarrays(vector<int>& nums, int minK, int maxK) {
		if (minK > maxK)
			return 0;
		long long ans = 0;
		vector<int> vec{ -1 };
		int n = nums.size();
		for (int i = 0; i < n; i++)
			if (nums[i] < minK || nums[i] > maxK)
				vec.push_back(i);
		vec.push_back(n);
		for (int i = 0; i < vec.size() - 1; i++)
			ans += solve(vec[i], vec[i + 1], nums, minK, maxK);
		return ans;
	}
};