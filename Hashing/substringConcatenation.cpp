vector<int> findSubstring(string A, vector<string>& B) {
	unordered_map<string, int> mp;
	vector<int> res;
	for (string x : B)
		mp[x]++;

	int n = A.size();
	int words = B.size();
	int len = B[0].size();

	for (int i = 0; i <= n - (words * len); i++) {
		unordered_map<string, int> temp;
		int counter = words;
		for (int j = i; j <= n - len; j += len) {
			string t = A.substr(j, len);
			if (mp.find(t) == mp.end())
				break;

			temp[t]++;

			if (temp[t] > mp[t])
				break;

			counter--;

			if (!counter) {
				res.push_back(i);
				break;
			}
		}

	}

	return res;
}
