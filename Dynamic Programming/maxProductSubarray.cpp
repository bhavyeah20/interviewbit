int Solution::maxProduct(const vector<int> &A) {
	int n = A.size();
	int dp1[n];
	int dp2[n];
	dp1[0] = A[0];
	dp2[0] = A[0];
	int maxx = A[0];

	for (int i = 1; i < n; i++) {
		dp1[i] = max({dp1[i - 1] * A[i], dp2[i - 1] * A[i], A[i]});
		dp2[i] = min({dp1[i - 1] * A[i], dp2[i - 1] * A[i], A[i]});

		maxx = max({maxx, dp1[i], dp2[i]});
	}

	return maxx;
}

//or

int maxProduct(vector<int>& A) {

	int n = A.size();
	int pos = A[0];
	int neg = A[0];
	int maxx = A[0];

	for (int i = 1; i < n; i++) {
		int newPos, newNeg;
		newPos = max({pos * A[i], neg * A[i], A[i]});
		newNeg = min({pos * A[i], neg * A[i], A[i]});

		pos = newPos , neg = newNeg;
		maxx = max({maxx, pos, neg});
	}

	return maxx;
}