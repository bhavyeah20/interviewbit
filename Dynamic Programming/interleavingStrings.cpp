class Solution {
public:
	bool isValid(string s1, string s2, string s3, int i, int j, int k) {

		if (i == s1.length() && j == s2.length())
			return k == s3.length();


		if (i < s1.length()) {
			if (s1[i] == s3[k]) {
				if (isValid(s1, s2, s3, i + 1, j, k + 1))
					return true;
			}
		}

		if (j < s2.length()) {
			if (s2[j] == s3[k]) {
				if (isValid(s1, s2, s3, i, j + 1, k + 1))
					return true;
			}
		}

		return false;
	}

	bool isInterleave(string s1, string s2, string s3) {
		return isValid(s1, s2, s3, 0, 0, 0);
	}
};

// memoized

class Solution {
public:

	unordered_map<string, int> mp;
	bool isValid(string s1, string s2, string s3, int i, int j) {

		if (i == s1.length() && j == s2.length())
			return i + j == s3.length();

		string key = to_string(i) + " " + to_string(j);
		if (mp.find(key) != mp.end())
			return mp[key];

		bool one = 0, two = 0;

		if (i < s1.length()) {
			if (s1[i] == s3[i + j]) {
				if (isValid(s1, s2, s3, i + 1, j))
					one = 1;
			}
		}

		if (j < s2.length()) {
			if (s2[j] == s3[i + j]) {
				if (isValid(s1, s2, s3, i, j + 1))
					two = 1;
			}
		}

		return mp[key] = one | two;
	}

	bool isInterleave(string s1, string s2, string s3) {
		mp.clear();
		return isValid(s1, s2, s3, 0, 0);
	}
};
//tabular


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