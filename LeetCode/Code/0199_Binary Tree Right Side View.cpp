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
	void solve(TreeNode* node, int level, vector<int>& ans)
	{
		if (node == nullptr)
			return;
		if (ans.size() < level)
			ans.push_back(node->val);
		else
			ans[level - 1] = node->val;
		solve(node->left, level + 1, ans);
		solve(node->right, level + 1, ans);
	}
public:
	vector<int> rightSideView(TreeNode* root) {
		vector<int> ans;
		solve(root, 1, ans);
		return ans;
	}
};