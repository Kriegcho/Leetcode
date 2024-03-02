struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
	bool isPalindrome(ListNode* head) {
		int cnt = 0;
		ListNode* node = head;
		while (node != nullptr)
		{
			cnt++;
			node = node->next;
		}
		ListNode* first = nullptr;
		node = head;
		int k = 0;
		while (k < cnt / 2)
		{
			ListNode* next = node->next;
			node->next = first;
			first = node;
			node = next;
			k++;
		}
		if (cnt % 2 == 1)
			node = node->next;
		ListNode* fnode = first;
		for (int i = 0; i < k; i++)
		{
			if (fnode->val != node->val)
				return false;
			fnode = fnode->next;
			node = node->next;
		}
		return true;
	}
};