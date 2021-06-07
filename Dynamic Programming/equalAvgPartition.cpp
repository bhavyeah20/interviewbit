bool build(vector<int> &A, int sum , int elements, int i, vector<int> &p) {
	if (elements == 0 && sum == 0)
		return true;

	if (sum == 0)
		return false;

	if (i == A.size())
		return false;

	if (A[i] <= sum) {
		p.push_back(A[i]);
		if (build(A, sum - A[i], elements - 1, i + 1, p))
			return true;

		p.pop_back();
	}

	if (build(A, sum, elements, i + 1, p))
		return true;

	return false;
}

vector<vector<int> > avgset(vector<int> &A) {
	int n = A.size();
	int sum = 0;
	for (int x : A)
		sum += x;

	vector<int> p;
	for (int i = 1; i <= n / 2; i++) {
		p.clear();
		if ((sum * i) % n == 0) {
			if (build(A, (sum * i) / n, i, 0, p))
				break;
		}
	}
	vector<int> q;
	unordered_map<int, int> mp;
	for (int x : p)
		mp[x]++;

	for (int x : A) {
		if (mp[x])
			mp[x]--;

		else
			q.push_back(x);
	}

	sort(p.begin(), p.end());
	sort(q.begin(), q.end());


	vector<vector<int> > ans(2);
	ans[0] = p, ans[1] = q;
	return ans;
}


// memoized
bool build(vector<int> &A, int elements, int i, int sum , vector<int> &p, vector<vector<vector<bool> > > &dp) {
	if (elements == 0)
		return sum == 0;

	if (i >= A.size())
		return false;

	if (dp[elements][i][sum] == false)
		return false;

	if (A[i] <= sum) {
		p.push_back(A[i]);
		if (build(A, elements - 1, i + 1, sum - A[i], p, dp))
			return true;

		p.pop_back();
	}

	if (build(A, elements, i + 1, sum, p, dp))
		return true;

	return dp[elements][i][sum] = false;
}

vector<vector<int> > Solution::avgset(vector<int> &A) {
	int n = A.size();
	int sum = 0;
	for (int x : A)
		sum += x;
	vector<vector<vector<bool> > > dp(n + 1, vector<vector<bool> > (n + 1, vector<bool> (sum + 1, true)));
	sort(A.begin(), A.end());
	vector<int> p;
	for (int i = 1; i <= n / 2; i++) {
		p.clear();
		if ((sum * i) % n == 0) {
			if (build(A, i, 0, (sum * i) / n, p, dp))
				break;
		}

	}
	vector<vector<int> > ans;

	if (p.empty())
		return ans;

	vector<int> q;
	unordered_map<int, int> mp;
	for (int x : p)
		mp[x]++;

	for (int x : A) {
		if (mp[x])
			mp[x]--;

		else
			q.push_back(x);
	}

	ans.push_back(p);
	ans.push_back(q);

	return ans;
}