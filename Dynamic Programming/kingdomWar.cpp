bool check(int row, int col, vector<vector<int> > &A) {
	int n = A.size(), m = A[0].size();
	int total = 0;
	for (int i = n; i >= row; i--) {
		for (int j = m; j >= col; j--) {
			total += A[i][j];

			if (total < 0)
				return false;
		}
	}

	return true;
}

int Solution::solve(vector<vector<int> > &A) {
	int n = A.size(), m = A[0].size();

	int i = n - 1, j = m - 1;
	if (A[i][j] <= 0)
		return A[i][j];

	int row = i, col = j;

	while (row >= 0 && A[row][j] >= 0) {
		row--;
	}

	while (col >= 0 && A[i][col] >= 0) {
		col--;
	}

	row = max(row, col);
	col = max(row, col);
	row++, col++;

	while (!check(row, col, A)) {
		row++, col++;
	}

	int total = 0;
	for (int ii = row; ii <= i; ii++) {
		for (int jj = col; jj <= j; jj++)
			total += A[ii][jj];
	}

	return total;

}


