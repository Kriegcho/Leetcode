struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
	void solve(TreeNode* node, int& ans, int sum)
	{
		if (node == nullptr)
			return;
		if (!node->left && !node->right)
			ans += sum + node->val;
		else
		{
			sum += node->val;
			sum *= 10;
			solve(node->left, ans, sum);
			solve(node->right, ans, sum);
		}
	}
public:
	int sumNumbers(TreeNode* root) {
		int ans = 0, sum = 0;
		solve(root, ans, sum);
		return ans;
	}
};