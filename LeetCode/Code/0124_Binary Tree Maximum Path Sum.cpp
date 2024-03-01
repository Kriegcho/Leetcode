#include <algorithm>

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
	int solve(TreeNode* node, int& maxp) // maxp 从node起点的最大带权路径的权值
	{
		// 分治：左子树，右子树，带根相连三者取最大
		// 带根相连即求根分别向左右子树出发的一条最大带权路径
		if (node->left == nullptr && node->right == nullptr)
		{
			if (node->val > 0)
				maxp += node->val;
			return node->val;
		}
		int maxpl = INT_MIN, maxpr = INT_MIN, maxl = INT_MIN, maxr = INT_MIN;
		if (node->left != nullptr)
		{
			maxpl = node->val;
			maxl = solve(node->left, maxpl);
		}
		if (node->right != nullptr)
		{
			maxpr = node->val;
			maxr = solve(node->right, maxpr);
		}
		int maxslr = max(maxpl, maxpr);
		if (maxslr > 0)
			maxp += maxslr;
		return max(max(maxl, maxr), (maxpl > node->val ? maxpl - node->val : 0)  + (maxpr > node->val ? maxpr - node->val : 0) + node->val);
	}
public:
	int maxPathSum(TreeNode* root) {
		int maxs = root->val;
		return solve(root, maxs);
	}
};