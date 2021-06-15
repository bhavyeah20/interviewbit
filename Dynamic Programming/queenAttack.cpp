vector<vector<int> > Solution::queenAttack(vector<string> &A) {
	unordered_map<int, int> row, col, rDiag, lDiag;

	int n = A.size(), m = A[0].size();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (A[i][j] == '1') {
				row[i]++;
				col[j]++;
				lDiag[i + j]++;
				rDiag[i - j + max(n, m)]++;
			}
		}
	}

	vector<vector<int> > ans(n, vector<int> (m, 0));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int cnt = 0;
			if (row[i] == 1 && A[i][j] == '0')
				cnt++;

			else if (row[i] >= 2)
				cnt++;

			if (col[j] == 1 && A[i][j] == '0')
				cnt++;

			else if (col[j] >= 2)
				cnt++;

			if (lDiag[i + j] == 1 && A[i][j] == '0')
				cnt++;

			else if (lDiag[i + j] >= 2)
				cnt++;

			if (rDiag[i - j + max(n, m)] == 1 && A[i][j] == '0')
				cnt++;

			else if (rDiag[i - j + max(n, m)] >= 2)
				cnt++;

			ans[i][j] = cnt;

		}
	}

	return ans;


}


// dp array
vector<vector<int> > dp[8];

//checks if cell (i, j) is valid or not
bool valid(int i, int j, int n, int m) {
	return !(i < 0 or i >= n or j < 0 or j >= m);
}

//direction vectors
int dir1[8] = { -1, -1, 0, 1, 1, 1, 0, -1};
int dir2[8] = {0, 1, 1, 1, 0, -1, -1, -1};

//returns dp(i, j, k) as defined in hint
int rec(int i, int j, int k, vector<string> & A, int n, int m) {

	//memoisation
	int &ret = dp[k][i][j];
	if (ret != -1)return ret;

	ret = 0;

	//new positions
	int ni = i + dir1[k];
	int nj = j + dir2[k];

	//if valid
	if (valid(ni, nj, n, m)) {
		if (A[ni][nj] == '1') ret++;
		else ret += rec(ni, nj, k, A, n, m);
	}

	return ret;
}

vector<vector<int> > Solution::queenAttack(vector<string> &A) {
	//init dp array
	int n = A.size(), m = A[0].size();
	for (int i = 0; i < 8; i++) {
		dp[i].clear();
		dp[i].resize(n, vector<int>(m, -1));
	}

	vector< vector<int> > ret(n, vector<int>(m, 0));

	//calculate dp for all positions
	for (int k = 0; k < 8; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				ret[i][j] += rec(i, j, k, A, n, m);
			}
	return ret;
}