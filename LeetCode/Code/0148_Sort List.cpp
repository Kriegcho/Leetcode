#include <utility>

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
	using HeadTail = std::pair<ListNode*, ListNode*>; // 头尾指针对，表示一条链表
	HeadTail solve(ListNode* head) // 三点中值+快速排序的思想
	{
		if (head == nullptr)
			return std::make_pair(nullptr, nullptr);
		ListNode *left = nullptr, *right = nullptr;
		// 是否需要取三点中值
		int count = 0;
		ListNode* node = head;
		while (node != nullptr)
		{
			count++;
			node = node->next;
		}
		ListNode *base = head;
		if (count > 16)
		{
			// 取三点中值
			ListNode *l = head, *r = nullptr, *m = nullptr;
			int ind = 0;
			ListNode* node = head;
			while (node != nullptr)
			{
				ind++;
				if (ind == count / 2)
					m = node;
				if (ind == count)
					r = node;
				node = node->next;
			}
			if (l->val < r->val)
			{
				if (r->val < m->val)
					base = r;
				else if (m->val < l->val)
					base = l;
				else
					base = m;
			}
			else
			{
				if (l->val < m->val)
					base = l;
				else if (m->val < r->val)
					base = r;
				else
					base = m;
			}
		}

		node = head;
		HeadTail htbase(base, base);
		while (node != nullptr)
		{
			if (node == base)
			{
				node = node->next;
				base->next = nullptr;
				continue;
			}
			ListNode* next = node->next;
			if (node->val < base->val)
			{
				node->next = left;
				left = node;
			}
			else if (node->val > base->val)
			{
				node->next = right;
				right = node;
			}
			else // 将相同的值处理掉，减少分割后的长度
			{
				node->next = htbase.first;
				htbase.first = node;
			}
			node = next;
		}
		HeadTail htl = solve(left);
		HeadTail htr = solve(right);
		if (htl.second == nullptr)
			htl.first = htbase.first;
		else
			htl.second->next = htbase.first;
		if (htr.first == nullptr)
			htr.second = htbase.second;
		else
			htbase.second->next = htr.first;

		return std::make_pair(htl.first, htr.second);
	}
public:
	ListNode * sortList(ListNode* head) {
		return solve(head).first;
	}
};