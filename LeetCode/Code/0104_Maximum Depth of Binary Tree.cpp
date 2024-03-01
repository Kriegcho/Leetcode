struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
	void solve(TreeNode* node, int level, int& ans)
	{
		if (node == nullptr)
			return;
		if (ans < level)
			ans = level;
		solve(node->left, level + 1, ans);
		solve(node->right, level + 1, ans);
	}
public:
	int maxDepth(TreeNode* root) {
		int ans = 0;
		solve(root, 1, ans);
		return ans;
	}
};