

void nextSwap(string A, int idx, int b, vector<string> &ans) {
	if (b == 0) {
		if (ans < A)
			ans = A;
		return;
	}



	for (int i = )


		swap(A[idx], A[idx + 1]);
	nextSwap(A, idx + 1, b - 1, ans);

	swap(A[idx], A[idx + 1]);
	nextSwap(A, idx + 1, b, ans);
}

string Solution::solve(string A, int B) {
	vector<string> ans;
	nextSwap(A, 0, B, ans);
	sort(ans.begin(), ans.end());
	return ans[ans.size() - 1];

}
