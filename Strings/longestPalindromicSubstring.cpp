map<pair<int, int>, bool> mp;
pair<int, int> ans;
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


// caacbabca

int maxlen(string A, int left, int right)
{
	int n = A.size();
	if (n == 0 || left > right)
	{
		return 0;
	}

	while ((left >= 0 && right < n) && (A[left] == A[right]))
	{


		left--;
		right++;
	}

	return right - left - 1;
}


string Solution::longestPalindrome(string A) {

	int n = A.size();
	int start = 0;
	int end = -1;
	int len;

	if (n == 1)
	{
		char a = A[0] ;
		string s ;
		s += a;
		return s;
	}

	for (int i = 0; i < n; i++)
	{
		int len1 = maxlen(A, i, i);
		int len2 = maxlen(A, i, i + 1);

		len = max(len1, len2);

		if (len > (end - start + 1))
		{
			start = i - (len - 1) / 2;
			end = i + (len / 2);
		}
	}

	return A.substr(start, end - start + 1);

}



// 1. o(n2) o(1) 2 pointers
// 2. o(n2) o(n2) lps
// 3. o(n2) o(n2) recursion