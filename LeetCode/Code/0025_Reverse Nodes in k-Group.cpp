#include <stack>
#include <vector>
using namespace std;

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode() : val(0), next(nullptr) {}
*     ListNode(int x) : val(x), next(nullptr) {}
*     ListNode(int x, ListNode *next) : val(x), next(next) {}
* };
*/

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode * reverseKGroup(ListNode* head, int k) {
		ListNode* last = head;
		vector<ListNode*> ans;
		stack<ListNode*> st;
		int c = 1;
		while (head)
		{
			if (c == 1) last = head;
			st.push(head);
			if (c < k) c++;
			else
			{
				while (!st.empty())
				{
					ans.push_back(st.top());
					st.pop();
				}
				c = 1;
			}
			head = head->next;
		}
		for (int i = 0; i + 1 < ans.size(); i++) ans[i]->next = ans[i + 1];
		ans[ans.size() - 1]->next = c > 1 ? last : 0;
		return ans[0];
	}
};
