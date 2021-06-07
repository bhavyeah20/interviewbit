
// memoized
unordered_map<string, int> mp;

bool isValid(string A, int i, string B, int j, string C, int k) {
	if (i == A.length() && j == B.length())
		return k == C.length();

	string key = to_string(i) + " " + to_string(j) + " " + to_string(k);

	if (mp.find(key) != mp.end())
		return mp[key];

	if (i == A.length())
		return mp[key] = B[j] == C[k] && B.substr(j) == C.substr(k);

	if (j == B.length())
		return mp[key] = A[i] == C[k] && A.substr(i) == C.substr(k);

	bool one = 0, two = 0;

	if (A[i] == C[k])
		one = isValid(A, i + 1, B, j, C, k + 1);

	if (B[j] == C[k])
		two = isValid(A, i, B, j + 1, C, k + 1);

	return mp[key] = one | two;


}

int Solution::isInterleave(string A, string B, string C) {
	mp.clear();
	return isValid(A, 0, B, 0, C, 0);
}

//

class Solution {
public:

	bool isInterleave(string A, string B, string C) {
		if (A.length() + B.length() != C.length())
			return 0;

		bool dp[A.length() + 1][B.length() + 1];
		for (int i = 0; i <= A.length(); i++) {
			for (int j = 0; j <= B.length(); j++) {
				if (i == 0 && j == 0) {
					dp[i][j] = true;
					continue;
				}
				dp[i][j] = (i > 0 && A[i - 1] == C[i + j - 1] && dp[i - 1][j])
				           || (j > 0 && B[j - 1] == C[i + j - 1] && dp[i][j - 1]);
			}
		}
		return dp[A.length()][B.length()] ? 1 : 0;

	}




};