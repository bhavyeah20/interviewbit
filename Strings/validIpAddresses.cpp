bool checkk(string s) {
	int n = s.size();
	if (!n || n > 3)
		return 0;

	int m = stoi(s);
	if (m < 0 || m > 255)
		return 0;

	for (int i = 0; i < n; i++) {
		if (s[0] == '0') {
			int j = i;
			while (s[i] == '0')
				i++;

			return (i - j == 1 && n == 1) ? 1 : 0;
		}
		else
			break;
	}

	return 1;
}

void insertt(vector<string> &ans, string A, int i, int j, int k) {
	string s = A.substr(0, i + 1) + '.' + A.substr(i + 1, j - i) + '.' + A.substr(j + 1, k - j) + '.' + A.substr(k + 1);
	ans.push_back(s);
}

vector<string> Solution::restoreIpAddresses(string A) {
	vector<string> ans;
	int n  = A.size();
	if (n < 4) {
		return ans;
	}

	for (int i = 0; i < n && i < 3; i++) {
		if (checkk(A.substr(0, i + 1))) {
			for (int j = i + 1; j < n && j <= i + 3; j++) {
				if (checkk(A.substr(i + 1, j - i))) {
					for (int k = j + 1; k < n && k <= j + 3; k++) {
						if (checkk(A.substr(j + 1, k - j)) && checkk(A.substr(k + 1)))
							insertt(ans, A, i, j, k);
					}
				}
			}
		}
	}

	return ans;
}
