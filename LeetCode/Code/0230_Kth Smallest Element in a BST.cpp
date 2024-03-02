﻿struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
	int solve(TreeNode* root, int& k)
	{
		if (root->left)
		{
			int n = solve(root->left, k);
			if (k == 0)
				return n;
		}
		k--;
		if (k == 0)
			return root->val;
		if (root->right)
			return solve(root->right, k);;
		return root->val;
	}
public:
	int kthSmallest(TreeNode* root, int k) {
		return solve(root, k);
	}
};