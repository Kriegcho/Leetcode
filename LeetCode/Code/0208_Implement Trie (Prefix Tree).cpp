#include <string>
#include <vector>

using namespace std; 

class TrieNode { // 字典树
public:
	bool leaf_; // 是否为叶节点，表征是否是单词的结尾（与实际意义的树叶节点有差异）
	vector<TrieNode*> sub;

	TrieNode()
		: leaf_(false), sub(26, nullptr)
	{

	}

	void init(const string& s, int pos)
	{
		if (pos == s.length())
			return;
		bool leaf = (pos == s.length() - 1);
		char c = s[pos];
		if (sub[c - 'a'] == nullptr)
			sub[c - 'a'] = new TrieNode();
		if (leaf)
			sub[c - 'a']->leaf_ = leaf;
		sub[c - 'a']->init(s, pos + 1);
	}

	bool find(const string& s, int pos, bool word)
	{
		if (sub[s[pos] - 'a'] == nullptr)
			return false;
		else if (pos == s.length() - 1)
		{
			if (word)
				return sub[s[pos] - 'a']->leaf_;
			return true;
		}
		return sub[s[pos] - 'a']->find(s, pos + 1, word);
	}
};

class Trie {
	TrieNode root;
public:
	Trie() {
		
	}

	void insert(string word) {
		root.init(word, 0);
	}

	bool search(string word) {
		return root.find(word, 0, true);
	}

	bool startsWith(string prefix) {
		return root.find(prefix, 0, false);
	}
};