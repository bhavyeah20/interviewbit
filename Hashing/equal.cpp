//Hashing pair sum to indices O(n^2)

vector<int> Solution::equal(vector<int> &A) {
	int n = A.size();
	vector<int> ans;
	unordered_map<int, pair<int, int> > mp; // sum->i,j

	for (int c = 0; c < n; c++) {
		for (int d = c + 1; d < n; d++) {
			int sum = A[c] + A[d];

			if (mp.find(sum) != mp.end()) {
				int a = mp[sum].first, b = mp[sum].second;

				if (a < b && c < d && a < c && b != d && b != c) {
					vector<int> temp = {a, b, c, d};
					if (ans.empty() || temp < ans)
						ans = temp;
				}
			}

			if (mp.find(sum) == mp.end())
				mp[sum] = {c, d};
		}
	}

	return ans;
}



//Hashing element to indices O(n^3)


vector<int> Solution::equal(vector<int> &A) {
	int n = A.size();
	vector<int> ans;
	unordered_map<int, vector<int> > mp;

	for (int i = 0; i < n; i++) {
		mp[A[i]].push_back(i);
	}

	for (int a = 0; a < n; a++) {
		for (int b = a + 1; b < n; b++) {
			int sum = A[a] + A[b];
			for (int c = 0; c < n; c++) {
				if (a == c || b == c)
					continue;
				if (mp.find(sum - A[c]) != mp.end()) {
					for (auto d : mp[sum - A[c]]) {
						if (c == d)
							continue;
						if (a < c && c < d && b != d) {
							ans = {a, b, c, d};
							return ans;
						}
					}
				}
			}
		}
	}
	return ans;
}
