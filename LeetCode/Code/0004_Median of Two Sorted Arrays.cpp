#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int tl = nums1.size() + nums2.size();
		bool f = tl % 2;
		int l1 = 0, l2 = 0, c = 0;
		double ans;
		while (l1 < nums1.size() || l2 < nums2.size())
		{
			int t;
			if (l1 < nums1.size() && l2 < nums2.size())
			{
				t = min(nums1[l1], nums2[l2]);
				if (nums1[l1] < nums2[l2]) l1++;
				else l2++;
			}
			else if (l1 < nums1.size())
			{
				t = nums1[l1];
				l1++;
			}
			else
			{
				t = nums2[l2];
				l2++;
			}
			c++;
			if (f && c == (tl + 1) / 2)
			{
				ans = t;
				break;
			}
			else if (!f)
			{
				if (c == tl / 2) ans += t;
				else if (c == tl / 2 + 1)
				{
					ans += t;
					ans = ans / 2;
					break;
				}
			}
		}
		return ans;
	}
};