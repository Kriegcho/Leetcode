#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
	int countStudents(vector<int>& students, vector<int>& sandwiches) {
		int si = 0;
		int n = students.size();
		deque<int> dq;
		for (int i = 0; i < n; i++)
		{
			if (students[i] == sandwiches[si])
				si++;
			else
				dq.push_back(i);
		}

		int dqf = dq.front();
		int len = dq.size();
		int count = 0;
		while (count < len)
		{
			if (students[dqf] == sandwiches[si])
			{
				si++;
				if (si == n)
					return 0;
				count = 0;
			}
			else
			{
				dq.push_back(dqf);
				count++;
			}
			dq.pop_front();
			len = dq.size();
			dqf = dq.front();
		}
		return len;
	}
};