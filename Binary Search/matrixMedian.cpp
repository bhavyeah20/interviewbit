int Solution::findMedian(vector<vector<int> > &A) {
	int m = A.size();
	int n = A[0].size();

	int minn = INT_MAX, maxx = INT_MIN;
	int targetCnt = (m * n + 1) / 2; //median is >= these many elements

	for (int i = 0; i < m; i++) {
		minn = min(A[i][0], minn);
	}

	for (int i = 0; i < m; i++) {
		maxx = max(A[i][n - 1], maxx);
	}


	while (minn < maxx) {
		int mid = minn + (maxx - minn) / 2;
		int cnt = 0;
		for (int i = 0; i < m; i++) {
			cnt += upper_bound(A[i].begin(), A[i].end(), mid) - A[i].begin();
		}

		if (cnt < targetCnt) {
			minn = mid + 1;
		}

		else
			maxx = mid;
	}

	return minn;

}
