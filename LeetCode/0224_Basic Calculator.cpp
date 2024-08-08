#include <vector>
#include <string>
using namespace std;

class Solution {

public:
	int calculate(string s) {
		vector<int> nums;
		vector<char> ops;
		int num = 0;
		bool flag = true, num_f = false;
		char last = ' ';
		for (char c : s)
		{
			if (c == ' ') continue;
			if (num_f && !(c >= '0' && c <= '9'))
			{
				nums.push_back(flag ? num : -num);
				num = 0;
				num_f = false;
			}
			switch (c)
			{
			case '+':
				ops.push_back(c);
				flag = true;
				num = 0;
				break;
			case '-':
				flag = false;
				ops.push_back('+');
				if (last == '(' || last == ' ')
					nums.push_back(0);
				break;
			case '(':
				ops.push_back(c);
				if (!flag) ops.push_back('-');
				flag = true;
				break;
			case ')':
				while (ops.back() != '(')
				{
					if (ops.back() == '+')
					{
						int op2 = nums.back();
						nums.pop_back();
						int op1 = nums.back();
						nums.pop_back();
						nums.push_back(op1 + op2);
					}
					else if (ops.back() == '-')
					{
						int op1 = nums.back();
						nums.pop_back();
						nums.push_back(-op1);
					}
					ops.pop_back();
				}
				ops.pop_back();
				flag = true;
				break;
			default:
				num *= 10;
				num += c - '0';
				num_f = true;
			}
			last = c;
		}
		if (num_f)
			nums.push_back(flag ? num : -num);

		while (!ops.empty())
		{
			int op2 = nums.back();
			nums.pop_back();
			int op1 = nums.back();
			nums.pop_back();
			nums.push_back(op1 + op2);
			ops.pop_back();
		}
		return nums.back();
	}
};