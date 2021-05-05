int Solution::solve(string A) {
	int cnt = 0;
	int o = 0, c = 0;
	for (char x : A) {
		if (x == '(')
			o++;

		else if (o > 0) {
			o--;
		}

		else
			c++;
	}

	return o + c;
}