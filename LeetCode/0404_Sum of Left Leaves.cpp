struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
	void solve(TreeNode* node, int& ans, bool left)
	{
		if (!node)
			return;
		if (!node->left && !node->right)
		{
			if (left)
				ans += node->val;
		}
		else
		{
			solve(node->left, ans, true);
			solve(node->right, ans, false);
		}
	}
public:
	int sumOfLeftLeaves(TreeNode* root) {
		int ans = 0;
		bool left = false;
		solve(root, ans, left);
		return ans;
	}
};