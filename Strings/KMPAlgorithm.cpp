#include<bits/stdc++.h>

using namespace std;

vector<int> prefixFunction(string &s) {
	vector<int> pi(s.size(), 0);
	pi[0] = 0;
	int n = s.size();
	int len = 0; //pi(i)
	for (int i = 1; i < n; i++) {
		// j = pi[j - 1];
		if (s[len] == s[i]) {
			len++;
			pi[i] = len;
			continue;
		}

		while (len > 0 && s[len] != s[i]) {
			len = pi[len - 1];	//what is the longest proper prefix using this length of suffix
			// (aaba)(aaba)x for x check for 4 length suffix which is also a prefix
			//  0101  2234
		}

		if (s[len] == s[i])
			len++;

		pi[i] = len;
	}

	return pi;
}

void KMP(string &s, string &pat) {
	vector<int> pi = prefixFunction(pat);
	int i = 0, j = 0;
	for (i = 0; i < s.size() && j < pi.size(); i++) {
		if (s[i] == pat[j]) {
			j++;
			if (j == pi.size()) {
				cout << i - j + 1 << " ";
				j = pi[j - 1];
			}
			continue;
		}

		if (j) {
			i--, j = pi[j - 1];
			continue;
		}

	}

}

vector<int> prefix(string s) {
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

	return pi;
}

void strStr(const string A, const string pat) {

	if (!pat.size() || !A.size())
		return;
	vector<int> pi = prefix(pat);
	int j = 0;
	for (int i = 0; i < A.size(); i++) {
		if (A[i] == pat[j]) {
			j++;
			if (j == pat.size()) {
				cout << i - j + 1 << " ";
				j = pi[j - 1];
			}
			continue;
		}
		if (!j) {
			i--;
			j = pi[j - 1];
		}
	}



}


int main() {
	string s = "bbaabbbbbaabbaabbbbbbabbbabaabbbabbabbbbababbbabbabaaababbbaabaaaba";
	string pat = "babaaa";
	KMP(s, pat);
	cout << endl;
	strStr(s, pat);
}
