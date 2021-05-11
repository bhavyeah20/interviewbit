int Solution::solve(int A) {

	int cnt = 0;
	while (A) {
		if (A & 1)
			break;

		A >>= 1;
		cnt++;
	}

	return cnt;
}

int Solution::solve(int A) {

	int num = A & -A;

	int cnt = log2(num);

	return cnt;
}

