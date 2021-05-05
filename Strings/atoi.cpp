int Solution::atoi(const string A) {
	int i = 0;
	int x = 0;
	int f = 0;
	int n = A.size();
	while (i < n && A[i] == ' ')
		i++;

	if (A[i] == '-')
		f = -1, i++;

	else if (A[i] == '+')
		f = 1, i++;

	while (A[i] - '0' >= 0 && A[i] - '0' <= 9) {
		if (INT_MAX / 10 < x || (INT_MAX / 10 == x && INT_MAX % 10 < A[i] - '0'))
			return f == -1 ? INT_MIN : INT_MAX;
		x *= 10;
		x += A[i] - '0';
		i++;
	}

	return f == -1 ? -x : x;
}