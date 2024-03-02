struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode * reverseList(ListNode* head) {
		ListNode* ans = nullptr;
		ListNode* node = head;
		while (node != nullptr)
		{
			ListNode* next = node->next;
			node->next = ans;
			ans = node;
			node = next;
		}
		return ans;
	}
};