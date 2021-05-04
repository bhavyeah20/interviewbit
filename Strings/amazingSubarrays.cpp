bool isVowel(char x) {
	if (tolower(x) == tolower('a') || tolower(x) == tolower('e') || tolower(x) == tolower('i') || tolower(x) == tolower('o') || tolower(x) == tolower('u'))
		return 1;
	return 0;
}

int Solution::solve(string A) {
	int cnt = 0, mod = 10003;
	for (int i = 0; i < A.size(); i++) {
		if (isVowel(A[i])) {
			cnt = (cnt % mod + (A.size() - i) % mod) % mod;
		}
	}

	return cnt;
}
