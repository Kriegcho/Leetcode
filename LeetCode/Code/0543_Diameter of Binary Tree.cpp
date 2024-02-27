#include <map>
#include <tuple>

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
	map<TreeNode*, tuple<int, int, int>> mapNode; // 存的是层数，左右子树的深度（从根开始计）

	int calcHeight(TreeNode* root, int level)
	{
		if (root == nullptr)
			return level;
		int lh = calcHeight(root->left, level + 1);
		int rh = calcHeight(root->right, level + 1);
		mapNode[root] = make_tuple(level, lh, rh);
		return lh > rh ? lh : rh;
	}

	void getAnswer(TreeNode* root, int& ans)
	{
		if (root == nullptr)
			return;
		int ltemp = get<1>(mapNode[root]) - get<0>(mapNode[root]) - 1;
		int rtemp = get<2>(mapNode[root]) - get<0>(mapNode[root]) - 1;
		int temp = (ltemp > 0 ? ltemp : 0) + (rtemp > 0 ? rtemp : 0);
		if (ans < temp)
			ans = temp;
		getAnswer(root->left, ans);
		getAnswer(root->right, ans);
	}

public:
	int diameterOfBinaryTree(TreeNode* root) {
		calcHeight(root, 0);
		int ans = 0;
		getAnswer(root, ans);
		return ans;
	}
};