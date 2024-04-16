#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
	void reorderList(ListNode* head) {
		stack<ListNode*> s;
		ListNode* node = head;
		while (node)
		{
			s.push(node);
			node = node->next;
		}
		int n = s.size();
		if (n > 2)
		{
			n /= 2;
			ListNode* tail = head;
			while (n > 0)
			{
				s.top()->next = tail->next;
				tail->next = s.top();
				tail = s.top()->next;
				s.pop();
				n--;
			}
			n = s.size();
			if (n % 2 != 0)
			{
				tail->next = s.top();
				s.top()->next = nullptr;
			}
			else
				tail->next = nullptr;
		}
	}
};