int Solution::solve(vector<vector<int> > &A) {
	int n = A.size(), m = A[0].size();
	for (int i = 0; i < n; i++) {
		int cnt = 0;
		for (int j = m - 1; j >= 0 ; j--) {
			if (!A[i][j])
				cnt = 0;

			else
				A[i][j] = ++cnt;
		}
	}

	int curr = 0, maxArea = 0;
	for (int j = 0; j < m; j++) {
		stack<int> s;
		for (int i = 0; i < n; i++ ) {
			while (!s.empty() && A[s.top()][j] > A[i][j]) {
				int top = A[s.top()][j];
				s.pop();
				int len = s.empty() ? i : i - s.top() - 1;

				if (len == top)
					maxArea = max(maxArea, top * len);
			}
			s.push(i);
		}

		while (!s.empty()) {
			int top = A[s.top()][j];
			s.pop();
			int len = s.empty() ? n : n - s.top() - 1;

			if (len == top)
				maxArea = max(maxArea, top * len);
		}


	}

	return maxArea;
}

// or

int Solution::solve(vector<vector<int> > &A) {
	int n = A.size(), m = A[0].size();
	int maxArea = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m ; j++) {
			if (!A[i][j])
				continue;

			if (i == 0 || j == 0 && A[i][j] == 1) {
				maxArea = max(maxArea, 1);
				continue;
			}

			A[i][j] = 1 + min(A[i][j - 1], min(A[i - 1][j - 1], A[i - 1][j]));

			maxArea = max(maxArea, A[i][j]);

		}
	}



	return maxArea * maxArea;
}
