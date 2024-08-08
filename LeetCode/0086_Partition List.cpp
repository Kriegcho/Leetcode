struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode * partition(ListNode* head, int x) {
		ListNode *left = nullptr, *left_tail = nullptr, *right = nullptr, *right_tail = nullptr;
		ListNode* cur = head;
		while (cur)
		{
			if (cur->val < x)
			{
				if (left_tail)
				{
					left_tail->next = cur;
					left_tail = cur;
				}
				else
				{
					left = cur;
					left_tail = cur;
				}
				cur = cur->next;
			}
			else
			{
				if (right_tail)
				{
					right_tail->next = cur;
					right_tail = cur;
				}
				else
				{
					right = cur;
					right_tail = cur;
				}
				cur = cur->next;
			}
		}
		if (right_tail) right_tail->next = nullptr;
		if (!left) return right;
		left_tail->next = right;
		return left;
	}
};