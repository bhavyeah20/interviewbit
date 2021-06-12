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
