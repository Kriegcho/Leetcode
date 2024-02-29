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
	bool solve(TreeNode* node, vector<int>& ans)
	{
		if (node == nullptr)
			return true;
		bool flag = solve(node->left, ans);
		if (!flag)
			return false;
		int n = ans.size();
		// 中序遍历的结果是严格递增的
		if (n > 0 && node->val <= ans[n - 1])
			return false;
		ans.push_back(node->val);
		flag = solve(node->right, ans);
		return flag;
	}
public:
	bool isValidBST(TreeNode* root) {
		vector<int> ans;
		return solve(root, ans);
	}
};