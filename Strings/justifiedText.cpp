void convert(string s, int len, vector<string> &ans, int words, int cnt) {

	int spacesToDistribute = len - cnt;
	int gap = words - 1;

	if (gap) {
		int space = spacesToDistribute / gap;
		int mod = spacesToDistribute % gap;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == ' ') {
				s.insert(i, space, ' ');
				i += space - 1;
			}
		}

		while (mod--) {
			for (int i = 0; i < s.size(); i++) {
				while (s[i] == ' ') {
					i++;
				}
				s.insert(i, 1, ' ');
			}
		}
	}

	else {
		int space = spacesToDistribute / 2;
		int mod = spacesToDistribute % 2;
		s.insert(s.size(), space, ' ');
	}

	ans.push_back(s);
}




vector<string> Solution::fullJustify(vector<string> &A, int len) {

	vector<string> ans;
	if (!A.size())
		return ans;


	string ians = "";
	int curr = 0;
	int words = 0;
	int chars = 0;

	for (int i = 0; i < A.size(); i++) {

		string x = A[i];
		curr += x.size();

		if (curr <= len) {
			ians += x;
			words++;
			chars += x.size();
			if (curr == len || curr + 1 == len) {
				convert(ians, len, ans, words, chars);
				ians = "";
				curr = 0;
				words = 0;
				chars = 0;
				continue;
			}

			curr++;
			ians += " ";
		}

		else {
			curr -= x.size();
			convert(ians, len, ans, words, chars);
			ians = "";
			curr = 0;
			words = chars = 0;
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


5 What must be shall be
B 12