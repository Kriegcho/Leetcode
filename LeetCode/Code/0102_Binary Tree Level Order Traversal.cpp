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
	void solve(TreeNode* node, vector<vector<int>>& ans, int level)
	{
		if (node == nullptr)
			return;
		int n = ans.size();
		if (n < level)
			ans.push_back({ node->val });
		else
			ans[level - 1].push_back(node->val);
		solve(node->left, ans, level + 1);
		solve(node->right, ans, level + 1);
	}
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> ans;
		solve(root, ans, 1);
		return ans;
	}
};