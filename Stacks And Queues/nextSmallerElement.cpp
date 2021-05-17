vector<int> Solution::prevSmaller(vector<int> &A) {
	int n = A.size();
	stack<int> s;
	for (int i = 0; i < n ; i++) {
		while (!s.empty() && s.top() >= A[i])
			s.pop();

		int t = A[i];

		if (s.empty())
			A[i] = -1;

		else
			A[i] = s.top();

		s.push(t);

	}

	return A;
}
