int Solution::solve(vector<int> &A, int B) {
	unordered_set<int> st;
	int a = A.size();
	int cnt = 0;
	for (int i = 0; i < a; i++)
	{
		int xr = A[i] ^ B;
		if (st.find(xr) == st.end())
			st.insert(A[i]);
		else
			cnt++;
	}
	return cnt;
}

//or

int Solution::solve(vector<int> &A, int B) {
	int cnt = 0;
	unordered_map<int, bool> mp;
	for (int x : A)
		mp[x] = 1;

	for (int x : A) {
		if (mp[x ^ B]) {
			cnt++;
		}
	}

	return cnt / 2;
}
