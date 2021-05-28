//Generic K sum = K - 2 sum + 2 ptr

vector<vector<int> > kSum(vector<int> &A, int start, int k, int target) {
	int n = A.size();
	vector<vector<int> > ans;

	if (k == 2) {
		int s = start;
		int e = n - 1;
		while (s < e) {
			if ((s > start && A[s] == A[s - 1]) || A[s] + A[e] < target)
				s++;

			else if ((e < n - 1  && A[e] == A[e + 1]) || A[s] + A[e] > target)
				e--;

			else {
				ans.push_back({A[s], A[e]});
				s++, e--;
			}
		}
		return ans;
	}

	for (int i = start; i < n - k + 1; i ++) {
		if (i > start && A[i] == A[i - 1])
			continue;
		vector<vector<int> > temp  = kSum(A, i + 1, k - 1, target - A[i]);
		for (auto &v : temp) {
			v.insert(v.begin(), A[i]);
			ans.push_back(v);
		}
	}
	return ans;
}

vector<vector<int> > Solution::fourSum(vector<int> &A, int B) {
	sort(A.begin(), A.end());
	return kSum(A, 0, 4, B);
}


//or


vector<vector<int> > Solution::fourSum(vector<int> &A, int B) {
	int n = A.size();
	sort(A.begin(), A.end());
	vector<vector<int> > ans;
	int sum = 0;
	for (int i = 0; i < n - 3; i++) {
		sum = 0;
		if (i > 0 && A[i] == A[i - 1])
			continue;

		sum += A[i];
		for (int j = i + 1; j < n - 2; j++) {
			if (j > i + 1 && A[j] == A[j - 1])
				continue;

			sum += A[j];

			int k = j + 1;
			int e = n - 1;
			int t = B - sum;
			while (k < e) {

				if ((k > j + 1 && A[k] == A[k - 1]) || A[k] + A[e] < target)
					k++;

				else if ((e < n - 1  && A[e] == A[e + 1]) || A[k] + A[e] > target)
					e--;

				else
					ans.push_back({A[i], A[j], A[k], A[e]});
			}

			sum -= A[j];
		}
		sum -= A[i];
	}
	return ans;
}

