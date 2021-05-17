string Solution::reverseString(string A) {
	string ans = "";
	stack<char> s;
	for (char x : A)
		s.push(x);

	while (!s.empty()) {
		ans.push_back(s.top());
		s.pop();
	}

	return ans;
}
