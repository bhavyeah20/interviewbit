int Solution::pow(int a, int b, int d) {
	if (!a)
		return 0;
	long long int res = 1;
	long long int A = a;
	while (b) {
		if (b & 1) {
			res = (res % d) * (A % d);
		}

		A = (A % d) * (A % d);
		b >>= 1;
	}

	return ((res % d) + d) % d;
	// return res;
}

