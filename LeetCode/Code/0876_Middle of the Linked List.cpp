#include <vector>

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode * middleNode(ListNode* head) {
		std::vector<ListNode*> vec;
		int n = 0;
		ListNode* node = head;
		while (node != 0)
		{
			n++;
			vec.push_back(node);
			node = node->next;
		}
		return vec[n / 2];
	}
};