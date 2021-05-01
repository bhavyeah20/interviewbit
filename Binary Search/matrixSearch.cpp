int Solution::searchMatrix(vector<vector<int> > &A, int B) {

	int m = A.size();
	int n = A[0].size();

	vector<int> cols(m, 0);

	for (int i = 0; i < m; i++)
		cols[i] = A[i][0];

	int posCol = -1;

	posCol = lower_bound(cols.begin(), cols.end(), B) - cols.begin();

	if (cols[posCol] == B)
		return 1;

	posCol--;

	if (posCol == -1)
		return 0;

	int posRow;

	posRow = lower_bound(A[posCol].begin(), A[posCol].end(), B) - A[posCol].begin();

	if (A[posCol][posRow] == B)
		return 1;

	return 0;
}

// or

// int Solution::searchMatrix(vector<vector<int> > &A, int B) {
// 	int N = A.size();
// 	int M = A[0].size();
// 	int start = 0, end = N * M - 1;
// 	while (start <= end) {
// 		int mid = start + (end - start) / 2;
// 		int x = mid / M;
// 		int y = mid % M;
// 		if (A[x][y] == B) return 1;
// 		if (B < A[x][y]) end = mid - 1;
// 		else start = mid + 1;
// 	}
// 	return 0;
// }
