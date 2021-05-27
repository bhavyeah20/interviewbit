vector<int> Solution::solve(vector<int> &A) {

	unordered_map<int, set<int>> mp;
	for (int i = 0; i < A.size(); i++) {
		if (mp.find(A[i]) == mp.end()) {
			mp[A[i]].insert(i);
		}
		else {
			auto it = mp[A[i]].begin();
			int idx = *it;

			mp[A[i]].erase(it);
			mp[A[i]].insert(i);
			mp[A[i] + 1].insert(idx);

			A[idx] = A[i] + 1;

		}

	}

	return A;

}


