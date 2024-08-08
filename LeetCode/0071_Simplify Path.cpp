#include <vector>
using namespace std;

class Solution {
public:
	string simplifyPath(string path) {
		vector<string> vec;
		string tmp;
		for (char c : path)
		{
			if (c == '/')
			{
				if (!tmp.empty())
				{
					if (tmp == "/..")
					{
						if (!vec.empty()) vec.pop_back();
					}
					else if (tmp != "/." && tmp != "/")
						vec.push_back(tmp);
					tmp.clear();
					
				}
				tmp += c;
			}
			else
				tmp += c;
		}
		if (tmp == "/..")
		{
			if (!vec.empty()) vec.pop_back();
		}
		else if (tmp != "/." && tmp != "/")
			vec.push_back(tmp);

		string ans;
		for (auto s : vec)
			ans += s;
		if (ans.empty()) ans = "/";
		return ans;
	}
};