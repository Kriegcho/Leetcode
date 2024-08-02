#include <vector>
using namespace std;

class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int i1 = m - 1, i2 = n - 1;
		int cur = m + n - 1;
		while (i1 >= 0 || i2 >= 0)
		{
			if (i1 < 0)
			{
				nums1[cur] = nums2[i2];
				i2--;
				cur--;
			}
			else if (i2 < 0)
			{
				nums1[cur] = nums1[i1];
				i1--;
				cur--;
			}
			else
			{
				if (nums1[i1] > nums2[i2])
				{
					nums1[cur] = nums1[i1];
					i1--;
					cur--;
				}
				else
				{
					nums1[cur] = nums2[i2];
					i2--;
					cur--;
				}
			}
		}
	}
};