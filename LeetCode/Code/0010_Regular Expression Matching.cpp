#include <string>
#include <cctype>
using namespace std;

class Solution {
public:
	bool isMatch(string s, string p) { // 思路：遍历模式串p，同时将s的当前位置pos向右移动。边界情况细节较多，解决错误用例花了些时间。
		if (s.empty() && p.empty()) return true;
		else if (p.empty()) return false;
		int pos = 0;
		for (int i = 0; i < p.length(); i++)
		{
			if (pos == s.length()) // 匹配串已走完，若模式串还有剩余，必须满足每两个字符都是x*的格式，*表示取0，否则就是失配
			{
				if (p[i] == '*') return false;
				else if (i < p.length() && p[i + 1] == '*') i++;
				else return false;
			}
			else if (isalpha(p[i]))
			{
				if (p[i] != s[pos]) // 模式串是字母，且与匹配串当前位置失配，若模式串下一个不是'*'，失配，否则将模式串下标步进2继续匹配
				{
					if (i < p.length())
					{
						if (p[i + 1] == '*') i++; // 循环体内还有一次自增
						else return false;
					}
					else return false; // 模式串读到了最后，失配
				}
				else // 字母匹配成功，若模式串下一个字符是'*'，匹配串位置不动。交给下一段处理'*'的逻辑处理。
				{
					if (i < p.length() && p[i + 1] == '*') {}
					else pos++;
				}
			}
			else if (p[i] == '*')
			{
				bool f = isMatch(s.substr(pos), p.substr(i + 1)); // 这里是把'*'作0用，匹配成功就不需要后续逻辑了
				if (f) return f;
				int c = 0;
				while (1)
				{
					if (s[pos + c] == p[i - 1] || p[i - 1] == '.') // 这个while循环是将*除0的所有可能取值代入去匹配一次，成功一次就可以退出
					{
						if (pos + c + 1 == s.length() && i < p.length() - 1) f |= isMatch("", p.substr(i + 1)); // 边界，当匹配串走完了，就和上面一样必须是x*的格式 
						else if (pos + c + 1 == s.length() && i == p.length() - 1) return true; // 刚好都走完了，匹配成功
						else if (pos + c + 1 >= s.length()) break;
						if (f) return f;
						f |= isMatch(s.substr(pos + c + 1), p.substr(i + 1)); // 匹配每一个可能的*取值，即c+1
						if (f) return f;
						c++;
					}
					else break;
				}
				return f;
			}
			else if (p[i] == '.') // 和字母匹配成功的逻辑一样
			{
				if (i < p.length() && p[i + 1] == '*') {}
				else pos++;
			}
		}
		if (pos < s.length()) return false;
		return true;
	}
};