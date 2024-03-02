#include <stack>
#include <map>

class MinStack {
	std::map<int, int> map;
	std::stack<int> st;
public:
	MinStack() {

	}

	void push(int val) {
		map[val]++;
		st.push(val);
	}

	void pop() {
		if (map[st.top()] == 1)
			map.erase(st.top());
		else map[st.top()]--;
		st.pop();
	}

	int top() {
		return st.top();
	}

	int getMin() {
		return map.begin()->first;
	}
};