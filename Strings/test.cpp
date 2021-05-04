#include<bits/stdc++.h>

using namespace std;

vector<int> prefixFunction(string &s) {
	vector<int> pi(s.size(), 0);
	pi[0] = 0;
	int n = s.size();
	int len = 0; //pi(i)
	for (int i = 1; i < n; i++) {
		if (s[len] == s[i]) {
			len++;
			pi[i] = len;
			continue;
		}

		while (len > 0 && s[len] != s[i]) {
			len = pi[len - 1];
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

	// if (j == pi.size())
	// 	return i - j;

	// return -1;
}

int main() {
	string s = "AABAACAADAABAABA";
	string pat = "AABA";
	KMP(s, pat);

	cout << endl;
}