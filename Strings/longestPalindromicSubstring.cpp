//2 ptrs
int computeLongest(string s, int mid) {
	int n = s.size();
	int len = INT_MIN;
	int i = mid, j;
	j = i + 1;
	while (i >= 0 && j < n && s[i] == s[j]) {
		i--, j++;
	}

	len = j - i - 1;

	i = mid - 1, j = mid + 1;

	while (i >= 0 && j < n && s[i] == s[j]) {
		i--, j++;
	}

	len = max(len, j - i - 1);

	return len;
}

string Solution::longestPalindrome(string A) {
	int n = A.size();
	int len = INT_MIN;
	int pos = -1;
	for (int i = 0; i < n; i++) {
		int curr = computeLongest(A, i);
		if (curr > len) {
			pos = i;
			len = curr;
		}
	}

	return A.substr(pos - (len - 1) / 2, len);

}


//lps

int prefix(string s) {
	int n = s.size();
	int i = 0, j = 0;
	vector<int> pi(n, 0);

	for (int i = 1; i < n; i++) {
		j = pi[i - 1];
		while (j > 0 && s[i] != s[j])
			j = pi[j - 1];

		if (s[i] == s[j])
			j++;

		pi[i] = j;
	}

	return pi[n - 1];
}


string Solution::longestPalindrome(string A) {

	int n = A.size();
	int len = INT_MIN;
	int pos = 0;
	for (int i = 0; i < n; i++) {
		string x = A.substr(i);
		string y = x;
		reverse(x.begin(), x.end());
		x = y + "$" + x;
		int curr = prefix(x);
		if (curr > len) {
			pos = i;
			len = curr;
		}
	}


	return A.substr(pos, len);

}

// recursion + memo

map<pair<int, int>, bool> mp;
pair<int, int> ans;
ans.first = ans.second = INT_MIN;
int N = 0;
void checkP(string s, int start, int end) {
	if (mp.find(make_pair(start, end)) != mp.end())
		return;

	if (start > end)
		return;
	mp[make_pair(start, end)] = 1;
	int n = end - start + 1;
	int mid = start + (end - start) / 2;
	int i = mid, j;
	if (n & 1)
		j = i;
	else
		j = i + 1;

	while (i >= start && j <= end && s[i] == s[j])
		i--, j++;

	if (i != start - 1) {
		if (end > 0)
			checkP(s, start, end - 1);
		if (start < N - 1)
			checkP(s, start + 1, end);
		return;
	}

	if ((end - start > ans.second - ans.first) || (end - start == ans.second - ans.first && start < ans.first))
		ans.first = start, ans.second = end;
	return;
}

string Solution::longestPalindrome(string A) {
	int n = A.size();
	if (!n)
		return "";
	if (n == 1)
		return A;
	N = n;
	checkP(A, 0, n - 1);
	return A.substr(ans.first, ans.second - ans.first + 1);

}

