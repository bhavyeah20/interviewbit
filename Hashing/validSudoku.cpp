int Solution::isValidSudoku(const vector<string> &A) {
	int n = A.size();
	unordered_map<int, bool> hashRow[n], hashCol[n];
	unordered_map<int, bool> hashSub[(int)sqrt(n)][(int)sqrt(n)];


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (A[i][j] == '.')
				continue;
			int val = A[i][j] - '0';

			if (hashRow[i][val])
				return 0;

			if (hashCol[j][val])
				return 0;

			if (hashSub[i / 3][j / 3][val])
				return 0;

			hashRow[i][val] = 1;
			hashCol[j][val] = 1;
			hashSub[i / 3][j / 3][val] = 1;

		}
	}

	return 1;

}
