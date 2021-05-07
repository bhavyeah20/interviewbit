int Solution::power(string A) {

	int i = 0;
	int curr = 0;
	string quot = A;
	int rem = 0;
	while (quot != "2") {
		int	N = quot.size();
		i = 0;
		while (i < N) {
			curr = (quot[i] - '0') + rem * 10;
			if (curr < 2) {
				i++;
				curr *= 10;
				curr += quot[i] - '0';
			}

			rem = curr % 2;
			quot += to_string(curr / 2);

			i++;
		}

		if (rem == 1)
			return 0;
	}

	return 1;

}
