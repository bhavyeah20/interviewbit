int Solution::colorful(int A) {
	unordered_map<int, bool> mp;

	//or to_string
	vector<int> a;
	while (A) {
		a.push_back(A % 10);
		A /= 10;
	}

	reverse(a.begin(), a.end());

	for (int i = 0; i < a.size(); i++) {
		long long prev = 1;
		long long curr = 1;
		for (int j = i; j < a.size(); j++) {
			curr = prev * a[j];
			if (mp.find(curr) != mp.end())
				return 0;

			mp[curr] = 1;
			prev = curr;
		}
	}

	return 1;
}
