int Solution::lengthOfLastWord(const string A) {
	int n = A.size();
	int i = n - 1;

	if (!n)
		return 0;

	while (i >= 0) {
		while (i >= 0 && A[i] == ' ')
			i--;

		if (i == -1)
			return 0;

		int j = i;
		while (i >= 0 && A[i] != ' ')
		{
			i--;
		}

		return j - i;
	}
}


// or

// stringstream ss(A);

// string s;
// int cnt = 0;
// while (ss >> s)
// 	cnt++;
// return s.size();