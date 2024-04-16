struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
	void solve(TreeNode* node, int level, int val, int depth)
	{
		if (!node)
			return;
		if (level == depth - 2)
		{
			TreeNode* new_node = new TreeNode(val);
			new_node->left = node->left;
			node->left = new_node;
			new_node = new TreeNode(val);
			new_node->right = node->right;
			node->right = new_node;
		}
		else
		{
			solve(node->left, level + 1, val, depth);
			solve(node->right, level + 1, val, depth);
		}
	}
public:
	TreeNode * addOneRow(TreeNode* root, int val, int depth) {
		if (depth == 1)
		{
			TreeNode* new_root = new TreeNode(val);
			new_root->left = root;
			return new_root;
		}
		int level = 0;
		solve(root, level, val, depth);
		return root;
	}
};