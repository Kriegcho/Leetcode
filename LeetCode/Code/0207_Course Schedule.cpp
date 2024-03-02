#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		vector<vector<int>> pre(numCourses);
		vector<int> post(numCourses, 0);
		for (auto vec : prerequisites)
		{
			pre[vec[0]].push_back(vec[1]);
			post[vec[1]]++;
		}
		queue<int> q;
		for (int i = 0; i < numCourses; i++)
			if (post[i] == 0)
				q.push(i);

		while (!q.empty())
		{
			for (auto j : pre[q.front()])
			{
				post[j]--;
				if (post[j] == 0)
					q.push(j);
			}
			q.pop();
		}
				
		for (auto i : post)
			if (i != 0)
				return false;
		return true;
	}
};

int main()
{
	Solution s;
	vector<vector<int>> vec{ {1, 4}, {2,4},{3,1},{3,2} };
	s.canFinish(5, vec);
}