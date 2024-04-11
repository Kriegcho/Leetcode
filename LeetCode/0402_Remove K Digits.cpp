#include <string>
#include <stack>
#include <deque>
using namespace std;

class Solution {
public:
	string removeKdigits(string num, int k) {
		int len = num.length(), delta = len - k;
		if (delta <= 0)
			return "0";
		deque<int> ans_dq;
		for (int i = 0; i < len; i++)
		{
			while (!ans_dq.empty() && num[ans_dq.back()] > num[i] && k-- > 0)
				ans_dq.pop_back();
			ans_dq.push_back(i);
		}
		string ans;
		bool flag = false;
		for (int i = 0; i < delta;i++)
		{
			if (num[ans_dq[i]] != '0')
				flag = true;
			if (flag)
				ans += num[ans_dq[i]];
		}
		if (ans.empty())
			ans = "0";
		return ans;
	}
};