#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> combinationSum(bool* cand, int minc, int target)
	{
		if (target < minc) // 剪枝
			return vector<vector<int>>(0);

		vector<vector<int>> ans;
		for (int i = minc; i <= target; i++)
		{
			if (cand[i])
			{
				if (i == target)
					ans.push_back({ target });
				else
				{
					vector<vector<int>> temp = combinationSum(cand, i, target - i); // 这里将minc改变成i是为了去重
					for (auto vec : temp)
					{
						vec.push_back(i);
						ans.push_back(vec);
					}
				}
			}
		}

		return ans;
	}

	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		bool cand[41];
		for (int i = 0; i < 41; i++)
			cand[i] = false;
		int minc = target;
		for (auto c : candidates)
		{
			cand[c] = true;
			if (minc > c)
				minc = c;
		}
		return combinationSum(cand, minc, target);
	}
};