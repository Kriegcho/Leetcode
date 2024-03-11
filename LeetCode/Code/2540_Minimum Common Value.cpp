#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
	int getCommon(vector<int>& nums1, vector<int>& nums2) {
		int n1 = nums1.size(), n2 = nums2.size();
		int l1 = 0, l2 = 0;
		while (l1 < n1 && l2 < n2)
		{
			if (nums1[l1] == nums2[l2])
				return nums1[l1];
			else if (nums1[l1] < nums2[l2])
				l1++;
			else
				l2++;
		}
		return -1;
	}
};