struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
	bool solve(TreeNode* l, TreeNode* r)
	{
		if (l == nullptr && r == nullptr)
			return true;
		else if (l != nullptr && r != nullptr)
			return l->val == r->val && solve(l->left, r->right) && solve(l->right, r->left);
		return false;
	}
public:
	bool isSymmetric(TreeNode* root) {
		return solve(root->left, root->right);
	}
};