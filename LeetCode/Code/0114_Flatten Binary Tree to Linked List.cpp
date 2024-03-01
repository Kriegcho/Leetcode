struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
	TreeNode* solve(TreeNode* node) // 返回先序遍历的最后一个节点
	{
		if (node->left == nullptr && node->right == nullptr)
			return node;
		TreeNode *left = node, *right = node;
		if (node->left != nullptr)
		{
			left = solve(node->left);
			left->right = node->right;
			right = left;
		}
		if (node->right != nullptr)
		{
			right = solve(node->right);
			left->right = node->right;
		}
		if (node->left != nullptr)
			node->right = node->left;
		node->left = nullptr;
		
		return right;
	}
public:
	void flatten(TreeNode* root) {
		if (root == nullptr)
			return;
		solve(root);
	}
};