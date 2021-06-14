void sol(int A, int start, vector<int> &comb, vector<int> &combs, vector<int> &B) {

	for (int i = start; i < B.size(); i++) {
		if (A - B[i] >= 0) {
			comb.push_back(i);
			sol(A - B[i], i, comb, combs, B);

			comb.pop_back();
		}
	}

	if (combs.empty())
		combs = comb;

	else if (combs.size() < comb.size())
		combs = comb;

	else if (combs.size() == comb.size() && comb < combs)
		combs = comb;

}

vector<int> Solution::solve(int A, vector<int> &B) {
	vector<int> comb;
	vector<int> combs;

	sol(A, 0, comb, combs, B);

	return combs;

}

// or

vector<int> Solution::solve(int A, vector<int> &B) {
	int N = B.size();
	int minStren = *min_element(B.begin(), B.end());
	vector<int> ans;

	for (int i = 0; i < N && A > 0; i++) {
		int kicksNow = (A - B[i]) / minStren;
		int kicksMax = (A - minStren) / minStren;

		if (kicksMax == kicksNow && A - B[i] >= 0) {
			A -= B[i];
			ans.push_back(i);
			i--;
		}
	}

	return ans;
}

