struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode * reverseBetween(ListNode* head, int left, int right) {
		int pos = 1;
		ListNode *head_l = nullptr, *tail = nullptr, *cur = head;
		for (int i = 1; i < left; i++)
		{
			if (i == 1) head_l = cur;
			tail = cur;
			cur = cur->next;
		}
		ListNode *head_m = nullptr, *tail_m = nullptr;
		for (int i = left; i <= right; i++)
		{
			ListNode* next = cur->next;
			if (i == left)
			{
				tail_m = cur;
				head_m = cur;
			}
			else
			{
				cur->next = head_m;
				head_m = cur;
			}
			cur = next;
		}
		tail_m->next = cur;

		if (head_l)
		{
			tail->next = head_m;
			return head_l;
		}
		else
			return head_m;
	}
};