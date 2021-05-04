string Solution::longestCommonPrefix(vector<string> &A) {
	int n = A.size();
	sort(A.begin(), A.end());
	string ans = A[0];
	string curr = A[n - 1];
	int a = 0, b = 0;
	while (a < ans.size() && b < curr.size() && ans[a] == curr[b]) {
		a++, b++;
	}

	ans = ans.substr(0, a);

	return ans;
}

// or

// string Solution::longestCommonPrefix(vector<string> &A) {
// 	int n = A.size();
// 	sort(A.begin(), A.end());
// 	string ans = A[0];
// 	for (int i = 1; i < n; i++) {
// 		string curr = A[i];
// 		int a = 0, b = 0;
// 		while (a < ans.size() && b < curr.size() && ans[a] == curr[b]) {
// 			a++, b++;
// 		}

// 		ans = ans.substr(0, a);
// 	}

// 	return ans;
// }


