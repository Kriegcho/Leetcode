#include <unordered_map>

class Node {
public:
	int val;
	Node* next;
	Node* random;

	Node(int _val) {
		val = _val;
		next = nullptr;
		random = nullptr;
	}
};


class Solution {
public:
	Node * copyRandomList(Node* head) {
		std::unordered_map<Node*, Node*> map1, map2;
		Node *p = head, *ans = nullptr;
		while (p != nullptr)
		{
			Node* np = new Node(p->val);
			if (ans == nullptr)
				ans = np;
			map1[p] = np;
			map2[np] = p;
			p = p->next;
		}
		p = ans;
		while (p != nullptr)
		{
			p->next = map1[map2[p]->next];
			p->random = map1[map2[p]->random];
			p = p->next;
		}
		return ans;
	}
};