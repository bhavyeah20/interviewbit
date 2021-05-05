string Solution::solve(string A, int B) {
	string ans = "";
	int n = A.size();
	if (B == 1)
		return ans;

	if (n == 1)
		return A;
	for (int i = 0; i < n - 1; i++) {
		if (A[i + 1] != A[i]) {
			ans.push_back(A[i]);
			continue;
		}


		int j = i;
		while (i < n - 1 && A[i + 1] == A[i]) {
			i++;
		}

		j = i - j + 1;

		j = j >= B ? j - B : j;
		while (j--) {
			ans.push_back(A[i]);
		}



	}
	if (n > 1 && A[n - 1] != A[n - 2]) {
		ans.push_back(A[n - 1]);
	}


	return ans;
}
