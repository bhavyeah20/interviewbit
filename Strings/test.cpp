#include<bits/stdc++.h>

using namespace std;

void convert(string s, int len, vector<string> &ans, int words, int cnt) {

	int spacesToDistribute = len - cnt;
	int gap = words - 1;

	if (gap) {
		// cout << "cp 8 " << endl;

		int space = spacesToDistribute / gap;
		int mod = spacesToDistribute % gap;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == ' ') {
				s.insert(i, space - 1, ' ');
				i += space - 1;
			}
			// cout << "yuhoo " << s.size() << endl;
		}
		// cout << "cp 9 " << endl;

		int currMod = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == ' ') {
				while (s[i] == ' ') {
					i++;
				}
				s.insert(i, 1, ' ');
				currMod++;

				if (currMod == mod)
					break;
			}
		}


		// cout << "cp 10 " << endl;

	}

	else {
		int space = spacesToDistribute / 2;
		int mod = spacesToDistribute % 2;
		s.insert(s.size(), space, ' ');
		// cout << "cp 11 " << endl;

	}

	ans.push_back(s);
}




vector<string> fullJustify(vector<string> &A, int len) {

	vector<string> ans;
	if (!A.size())
		return ans;

	// cout << "cp 1" << endl;
	string ians = "";
	int curr = 0;
	int words = 0;
	int chars = 0;

	for (int i = 0; i < A.size(); i++) {

		string x = A[i];
		curr += x.size();
		// cout << "cp 2" << endl;
		// cout << "a[i] is " << x << endl;

		if (curr <= len) {
			ians += x;
			words++;
			chars += x.size();
			if (curr == len || curr + 1 == len) {
				// cout << "cp 7 " << endl;
				// cout << "ians " << ians << endl;
				convert(ians, len, ans, words, chars);
				ians = "";
				curr = 0;
				words = 0;
				chars = 0;
				// cout << "cp 3" << endl;

				continue;
			}


			// cout << "cp 4" << endl;

			curr++;
			if (i == A.size() - 1) {
				ans.push_back(ians);
				break;
			}
			else
				ians += " ";


		}

		else {
			curr -= x.size();
			// cout << "cp 7 " << endl;
			// cout << "ians " << ians << endl;

			convert(ians, len, ans, words, chars);
			ians = "";
			curr = 0;
			words = chars = 0;
			// cout << "cp 5" << endl;
			i--;
			continue;
		}

	}

	int m = ans.size();
	string s = ans[m - 1];
	int i = 0;
	int j = m - 1;

	while (i < m && s[i] == ' ') {
		i++;
	}

	s.erase(0, i);

	while (j >= 0  && s[j] == ' ') {
		j--;
	}

	s.erase(j);

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ' ') {
			int j = i;
			while (s[i] == ' ')
				i++;

			s.erase(j, i - j - 1);
		}

	}

	return ans;
}

int main() {

	vector<string> v({
		"am", "fasgoprn", "lvqsrjylg", "rzuslwan", "xlaui", "tnzegzuzn", "kuiwdc", "fofjkkkm", "ssqjig", "tcmejefj", "uixgzm", "lyuxeaxsg", "iqiyip", "msv", "uurcazjc", "earsrvrq", "qlq", "lxrtzkjpg", "jkxymjus", "mvornwza", "zty", "q", "nsecqphjy"
	});

	vector<string> ans = fullJustify(v, 14);
	for (string x : ans)
		cout << x << endl;

}
