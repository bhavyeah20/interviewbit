string Solution::solve(string A) {
	string ans = "", w;
	stringstream ss(A);
	while (ss >> w)
		ans = " " + w + ans;
	return (ans.substr(1));
}

// or

string Solution::solve(string A) {

	int n = A.size();
	int i = n - 1;

	string ans = "";
	string word = "";

	int j = 0;

	while (j < n && A[j] == ' ')
		j++;

	// cout<<"j "<<j<<endl;

	while (i >= 0) {

		while (i >= 0 && A[i] == ' ') {
			i--;
		}

		while (i >= 0 && A[i] != ' ') {
			word.push_back(A[i]);
			i--;
		}

		reverse(word.begin(), word.end());
		ans += word;
// 		cout<<i<<endl;
		if (i != j - 1 && i != -1)
			ans.push_back(' ');

		word = "";
	}

	return ans;
}