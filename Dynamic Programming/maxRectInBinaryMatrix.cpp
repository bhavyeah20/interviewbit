//maximal area rectangle

int maximalRectangle(vector<vector<char>>& A) {
	if (A.empty())
		return 0;
	int n = A.size();
	int m = A[0].size();
	int curr, maxx = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (A[i][j] == '0')
				continue;

			int level = i;
			int jMax = m;
			while (level < n && A[level][j] == '1') {
				int j1 = j;
				for (j1; j1 < jMax; j1++)
					if (A[level][j1] == '0') break;

				curr = (level - i + 1) * (j1 - j);
				maxx = max(maxx, curr);
				jMax = j1;
				level++;
			}
		}
	}
	return maxx;
}

// or


int maximalRectangle(vector<vector<char>>& A) {
	if (A.empty())
		return 0;
	int n = A.size();
	int m = A[0].size();
	vector<vector<int> > area(n, vector<int> (m, 0));
	int curr = 0, maxx = 0;
	for (int i = 0; i < n; i++) {
		int cnt = 0;
		for (int j = m - 1; j >= 0; j--) {
			if (A[i][j] == '0') {
				cnt = 0;
			}

			else {
				cnt++;
				area[i][j] = cnt;
			}
		}
	}

	for (int j = 0; j < m; j++) {
		stack<int> s;
		for (int i = 0; i < n; i++) {
			while (!s.empty() && area[s.top()][j] > area[i][j]) {
				int t = area[s.top()][j];
				s.pop();
				curr = s.empty() ? t * i : t * (i - s.top() - 1);
				maxx = max(curr, maxx);
			}
			s.push(i);
		}

		while (!s.empty()) {
			int t = area[s.top()][j];
			s.pop();
			curr = s.empty() ? t * n : t * (n - s.top() - 1);
			maxx = max(curr, maxx);
		}
	}
	return maxx;
}
