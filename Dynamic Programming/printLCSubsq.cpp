
void LCS(int start, int pI, string x, string y, string curr, string &ans) {
	if (start == x.size()) {
		if (ans.length() < curr.length())
			ans = curr;
		return ;
	}


	for (int i = start; i < x.size(); i++) {
		for (int j = pI; j < y.size(); j++) {
			if (x[i] == y[j]) {
				curr.push_back(x[i]);
				LCS(i + 1, j + 1, x, y, curr, ans);

				curr.pop_back();
			}
		}
	}
}
