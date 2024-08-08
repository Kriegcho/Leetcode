struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode * deleteDuplicates(ListNode* head) {
		ListNode *ans = nullptr, *tail = nullptr;
		ListNode* cur = head;
		int cur_val = 101;
		while (cur)
		{
			if (cur->next && cur->next->val == cur->val)
			{
				cur_val = cur->val;
				cur = cur->next->next;
			}
			else if (cur->val == cur_val)
			{
				cur = cur->next;
			}
			else
			{
				if (tail)
				{
					tail->next = cur;
					tail = cur;
				}
				else
				{
					ans = cur;
					tail = cur;
				}
				cur = cur->next;
			}
			if (!cur && tail)
				tail->next = cur; // 尾部
		}
		return ans;
	}
};