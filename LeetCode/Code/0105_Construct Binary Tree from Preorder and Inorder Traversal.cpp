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
	TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int pl, int pr, int il, int ir)
	{
		int pos = il;
		for (int i = il; i <= ir; i++)
			if (inorder[i] == preorder[pl])
			{
				pos = i;
				break;
			}
		int ln = pos - il, rn = ir - pos;
		TreeNode *left(nullptr), *right(nullptr);
		if (ln > 0)
			left = solve(preorder, inorder, pl + 1, pl + ln, il, pos - 1);
		if (rn > 0)
			right = solve(preorder, inorder, pl + ln + 1, pr, pos + 1, ir);
		return new TreeNode(preorder[pl], left, right);
	}
public:
	TreeNode * buildTree(vector<int>& preorder, vector<int>& inorder) {
		int n = preorder.size();
		return solve(preorder, inorder, 0, n - 1, 0, n - 1);
	}
};