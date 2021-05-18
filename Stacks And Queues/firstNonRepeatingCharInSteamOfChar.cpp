string Solution::solve(string A) {

	queue<char> q;
	string ans = "";
	vector<int> alpha(26, 0);

	for (int i = 0; i < A.size(); i++) {

		alpha[A[i] - 'a']++;

		q.push(A[i]);


		while (!q.empty() && alpha[q.front() - 'a'] > 1)
			q.pop();

		if (q.empty()) {
			ans.push_back('#');
		}

		else {
			ans.push_back(q.front());
		}


	}

	return ans;
}
