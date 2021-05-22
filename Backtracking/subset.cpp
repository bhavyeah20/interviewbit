void nextComb(int left, vector<int> comb, vector<vector<int> > &ans, vector<int> A) {
	ans.push_back(comb);

	int n = A.size();
	for (int i = left; i < n; i++) {
		comb.push_back(A[i]);
		nextComb(i + 1, comb, ans, A);

		comb.pop_back();
	}

}


vector<vector<int> > Solution::subsets(vector<int> &A) {
	sort(A.begin(), A.end());
	vector<vector<int> > ans;
	nextComb(0, vector<int> (), ans, A);
	return ans;
}
