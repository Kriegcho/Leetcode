#include <string>
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
	void solve(TreeNode* node, string path, string& ans)
	{
		if (!node)
			return;
		if (!node->left && !node->right)
		{
			string tmp = (char)(node->val + 'a') + path;
			if (ans.empty())
				ans = tmp;
			else if (ans > tmp)
				ans = tmp;
		}
		else if (!node->left)
			solve(node->right, (char)(node->val + 'a') + path, ans);
		else if (!node->right)
			solve(node->left, (char)(node->val + 'a') + path, ans);
		else
			solve(node->left->val < node->right->val ? node->left : node->right, (char)(node->val + 'a') + path, ans);
	}
public:
	string smallestFromLeaf(TreeNode* root) {
		string ans;
		solve(root, "", ans);
		return ans;
	}
};