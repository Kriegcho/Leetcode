#include <unordered_map>

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode * removeZeroSumSublists(ListNode* head) {
		std::unordered_map<int, ListNode*> um; // 到当前节点的和
		ListNode* node = head;
		int sum = 0;
		while (node != nullptr)
		{
			sum += node->val;
			if (sum == 0)
			{
				head = node->next;
				node = head;
				um.clear();
			}
			else
			{
				if (um.count(sum))
				{
					um[sum]->next = node->next; // 重新拼接
					return removeZeroSumSublists(head);
				}
				else
					um[sum] = node;
				node = node->next;
			}
		}
		return head;
	}
};