string Solution::minWindow(string S, string T) {
	int ansStart = 0, ansEnd = INT_MAX;
	int start, end;
	vector<int> mp(255, 0); // val->cnt
	for (int i = 0; i < T.size(); i++) {
		mp[T[i]]++;
	}


	start = 0, end = 0;
	int counter = T.size();

	for (int end = 0; end < S.size(); end++) {

		if (mp[S[end]] > 0)
			counter--;

		mp[S[end]]--;


		while (!counter) {
			if (end - start < ansEnd - ansStart)
				ansStart = start, ansEnd = end;

			mp[S[start]]++;
			if (mp[S[start]] > 0)
				counter++;

			start++;

		}
	}

	return ansEnd == INT_MAX ? "" : S.substr(ansStart, ansEnd - ansStart + 1);
}

// or

bool check(unordered_map<char, int> mp, unordered_map<char, int> ansMp) {
	for (auto ele : mp) {
		if (ansMp[ele.first] < ele.second)
			return 0;
	}

	return 1;
}

string Solution::minWindow(string S, string T) {
	int ansStart = 0, ansEnd = INT_MAX;
	int start, end;
	unordered_map<char, int> mp; // val->cnt
	for (int i = 0; i < T.size(); i++) {
		mp[T[i]]++;
	}

	unordered_map<char, int> ansMp;

	start = 0, end = 0;


	for (int i = 0; i < S.size(); i++) {

		if (mp.find(S[i]) != mp.end()) {
			ansMp[S[i]]++;
		}


		if (check(mp, ansMp)) {
			end = i;

			while (start < S.size() && check(mp, ansMp)) {
				ansMp[S[start]]--;
				start++;
			}

			start = start - 1;

			if (end - start < ansEnd - ansStart) {
				ansEnd = end, ansStart = start;
			}

			start++;
		}
	}


	return ansEnd == INT_MAX ? "" : S.substr(ansStart, ansEnd - ansStart + 1);





}
