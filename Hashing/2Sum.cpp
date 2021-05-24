vector<int> Solution::twoSum(const vector<int> &A, int B) {
	// for chaining i can have u_m<i, v<i>>
	unordered_map<int, int> mp;
	vector<int> ans;
	for (int i = 0; i < A.size(); i++) {
		int findd = B - A[i];
		if (mp.find(findd) == mp.end()) {
			if (mp.find(A[i]) != mp.end())
				continue;

			mp[A[i]] = i;
		}

		else {
			ans.push_back(mp[findd] + 1);
			ans.push_back(i + 1);

			break;
		}

	}

	return ans;
}
