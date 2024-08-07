#include <string>
#include <vector>
using namespace std;

class Solution {
	vector<string> nums{"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", 
		"Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
	vector<string> decs{ "", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };
	vector<string> thous{ "", "Thousand", "Million", "Billion" };
	string conv(int n)
	{
		int a = n / 100, b = (n % 100) / 10, c = n % 10;
		string res{ "" };
		if (a > 0)
			res += nums[a] + " Hundred";
		if (b > 1)
		{
			res += (res.empty() ? "" : " ") + decs[b];
			if (c > 0) res += " " + nums[c];
		}
		else
		{
			int d = n % 100;
			if (d > 0) res += (res.empty() ? "" : " ") + nums[d];
		}
		return res;
	}
public:
	string numberToWords(int num) {
		if (num == 0) return "Zero";
		vector<int> vec;
		while (num)
		{
			vec.push_back(num % 1000);
			num /= 1000;
		}
		string ans{ "" };
		for (int i = vec.size() - 1; i >= 0; i--)
		{
			string tmp = conv(vec[i]);
			string pre =  tmp.empty() ? "" : (ans.empty() ? "" : " ") + tmp;
			if (!pre.empty())
			{
				ans += pre;
				if (i > 0)
				{
					ans += " ";
					ans += thous[i];
				}
			}
		}
		return ans;
	}
};