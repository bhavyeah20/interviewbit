// with permutations

int Solution::solve(vector<vector<int> > &A) {
	int n = A.size(), m = A[0].size();
	int curr , maxx = 0;
	vector<vector<int> > area(n, vector<int> (m, 0));

	for (int j = 0; j < m; j++) {
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (!A[i][j])
				cnt = 0;
			else {
				cnt++;
				area[i][j] = cnt;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		// sort(area[i].begin(), area[i].end(), greater<int> ());
		//or

		int count[n + 1] = {0};
		for (int j = 0; j < m; j++)
			count[area[i][j]]++;

		int col = 0;
		for (int row = n; row >= 0; row--) {
			while (count[row]) {
				area[i][col] = row;
				col++;
				count[row]--;
			}
		}


		for (int j = 0; j < m && area[i][j]; j++) {
			curr = area[i][j] * (j + 1);
			maxx = max(maxx, curr);
		}
	}

	return maxx;
}
