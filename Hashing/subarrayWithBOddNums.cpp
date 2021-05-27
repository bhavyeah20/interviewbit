int Solution::solve(vector<int> &A, int B) {
	int n = A.size();
	for (int &x : A) {
		if (x & 1)
			x = 1;
		else
			x = 0;
	}

	unordered_map<int, int> mp;  // currSum -> cnt;

	// currSumNew - currSumOld = target

	mp[0] = 1;
	int cnt = 0, sum = 0;

	for (int i = 0; i < n; i++) {
		sum += A[i];
		int target = sum - B;
		if (mp.find(target) != mp.end) {
			cnt += mp[target];
		}

		mp[sum]++;
	}

	return cnt;
}



