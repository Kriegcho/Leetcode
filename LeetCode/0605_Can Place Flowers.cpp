#include <vector>
using namespace std; 

class Solution {
public:
	bool canPlaceFlowers(vector<int>& flowerbed, int n) {
		int ans = 0, len = flowerbed.size();
		if (n > len / 2 + 1)
			return false;
		for (int i = 0; i < len; i++)
			if (flowerbed[i] == 0)
			{
				bool flag = true;
				if (i > 0)
					flag &= flowerbed[i - 1] == 0;
				if (i < len - 1)
					flag &= flowerbed[i + 1] == 0;
				if (flag)
				{
					ans++;
					flowerbed[i] = 1;
				}
			}
		return ans >= n;
	}
};