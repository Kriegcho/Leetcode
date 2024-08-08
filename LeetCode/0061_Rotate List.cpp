struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode * rotateRight(ListNode* head, int k) {
		ListNode *cur = head, *last = head;
		int cnt = 0;
		while (cur)
		{
			cnt++;
			cur = cur->next;
			if (cur) last = cur;
		}
		if (cnt <= 1) return head;
		k %= cnt;
		if (k == 0) return head;
		k = cnt - k;
		cur = head;
		for (int i = 0; i < k; i++)
		{
			ListNode* next = cur->next;
			if (i == k - 1)
				cur->next = nullptr;
			cur = next;
		}
		last->next = head;
		return cur;
	}
};