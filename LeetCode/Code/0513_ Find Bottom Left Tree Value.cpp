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
	void solve(TreeNode* root, int level, vector<int>& ans)
	{
		if (root == nullptr)
			return;
		if (ans.size() < level)
			ans.push_back(root->val);
		solve(root->left, level + 1, ans);
		solve(root->right, level + 1, ans);
	}
public:
	int findBottomLeftValue(TreeNode* root) {
		vector<int> ans;
		solve(root, 1, ans);
		return ans.back();
	}
};