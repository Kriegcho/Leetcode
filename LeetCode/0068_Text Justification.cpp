#include <vector>
using namespace std;


class Solution {
public:
	vector<string> fullJustify(vector<string>& words, int maxWidth) {
		int cur_length = 0;
		vector<string> line, ans;
		for (string s : words)
		{
			if ((cur_length + s.length() + (line.empty() ? 0 : 1)) > maxWidth)
			{
				int delta = maxWidth - cur_length;
				if (line.size() == 1)
				{
					string l = line[0];
					for (int i = 0; i < delta; i++)
						l += ' ';
					ans.push_back(l);
				}
				else
				{
					int a = delta / (line.size() - 1), b = delta % (line.size() - 1);
					string l;
					for (int i = 0; i < line.size(); i++)
					{
						if (i > 0)
							for (int j = 0; j <= (i <= b ? a + 1 : a); j++)
								l += ' ';
						l += line[i];
					}
					ans.push_back(l);
				}
				line.clear();
				line.push_back(s);
				cur_length = s.length();
			}
			else
			{
				cur_length += s.length() + (line.empty() ? 0 : 1);
				line.push_back(s);
			}
		}
		// 最后一行
		string l;
		for (int i = 0; i < line.size(); i++)
		{
			if (i > 0) l += ' ';
			l += line[i];
		}
		for (int i = cur_length; i < maxWidth; i++)
			l += ' ';
		ans.push_back(l);
		return ans;
	}
};