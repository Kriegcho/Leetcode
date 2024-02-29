#include <vector>

using namespace std; 

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
	bool solve(TreeNode* node, int level, vector<int>& vec)
	{
		if (node == nullptr)
			return true;
		if (node->val % 2 != level % 2)
			return false;
		if (vec.size() < level)
			vec.push_back(node->val);
		else
		{
			if (node->val % 2 == 0)
			{
				if (node->val > vec[level - 1])
					return false;
			}
			else
				if (node->val < vec[level - 1])
					return false;
			vec[level - 1] = node->val;
		}
		return solve(node->left, level + 1, vec) && solve(node->right, level + 1, vec);
	}
public:
	bool isEvenOddTree(TreeNode* root) {
		vector<int> vec;
		return solve(root, 1, vec);
	}
};