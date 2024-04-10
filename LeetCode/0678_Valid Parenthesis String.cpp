#include <string>
#include <list>

using namespace std;

class Solution {
public:
	bool checkValidString(string s) {
		list<char> ls;
		int len = s.length();
		for (char c : s)
		{
			switch (c)
			{
			case '(':
			case '*':
				ls.push_back(c);
				break;
			case ')':
			{
				if (ls.empty())
					return false;
				bool find = false;
				auto itf = ls.end();
				for (auto itr = ls.begin(); itr != ls.end(); itr++)
					if (*itr == '(')
					{
						itf = itr;
						find = true;
					}
				if (find)
				{
					if (ls.size() == 1)
						ls.clear();
					else
						ls.erase(itf);
				}
				else
					ls.pop_back();
			}
			break;
			}
		}
		int sc = 0;
		while (!ls.empty())
		{
			if (ls.back() == '*')
				sc++;
			else if (ls.back() == '(')
			{
				if (sc == 0)
					return false;
				else
					sc--;
			}
			ls.pop_back();
		}
		return true;
	}
};