int Solution::solve(string A) {
	int n = A.size();
	int i = 0, j = n - 1;
	int cnt = 0;
	while (i < j) {
		if (A[i] != A[j]) {
			if (A[i + 1] == A[j])
				i++, cnt++;

			else if (A[j - 1] == A[i])
				j--, cnt++;

			else
				return 0;

			if (cnt > 1)
				return 0;
		}



		else {
			i++, j--;
		}
	}

	if (!cnt && !(n & 1))
		return 0;
	return 1;
}
