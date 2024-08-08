#include <vector>
#include <string>
using namespace std; 

class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		vector<int> vec;
		for (string s : tokens)
		{
			if (s == "+")
			{
				int op1 = vec.back();
				vec.pop_back();
				int op2 = vec.back();
				vec.pop_back();
				vec.push_back(op2 + op1);
			}
			else if (s == "-")
			{
				int op1 = vec.back();
				vec.pop_back();
				int op2 = vec.back();
				vec.pop_back();
				vec.push_back(op2 - op1);
			}
			else if (s == "*")
			{
				int op1 = vec.back();
				vec.pop_back();
				int op2 = vec.back();
				vec.pop_back();
				vec.push_back(op2 * op1);
			}
			else if (s == "/")
			{
				int op1 = vec.back();
				vec.pop_back();
				int op2 = vec.back();
				vec.pop_back();
				vec.push_back(op2 / op1);
			}
			else
			{
				int i = stoi(s);
				vec.push_back(i);
			}
		}
		return vec.back();
	}
};