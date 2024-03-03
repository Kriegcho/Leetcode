﻿#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
	TreeNode * lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root == nullptr || root == p || root == q)
			return root;
		TreeNode* l = lowestCommonAncestor(root->left, p, q);
		TreeNode* r = lowestCommonAncestor(root->right, p, q);
		if (l == nullptr && r == nullptr)
			return nullptr;
		return l == nullptr ? r : l;
	}
};