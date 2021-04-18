int Solution::solve(vector<int> &A, int B) {
	int n = A.size();
	int cnt = 0;
	int initI = 0, finalI = 0, finalJ = 0;
	int cntMax = INT_MIN;
	for (int i = 0; i < n; i++) {
		if (A[i])
			cnt++;
		else
			cnt--;

		if (cnt < 0) {
			initI = i + 1;
			continue;
		}

		if (cnt > cntMax || (cnt == cntMax && i - initI > finalJ - finalI))
			cntMax = cnt, finalI = initI, finalJ = i;
	}

	int b = B;
	int lcurr = 0, rcurr = 0;
	for (int i = finalI; i <= finalJ; i++)
	{
		if (!A[i])
			b--;

		if (!b)
			break;

		lcurr++;
	}
	b = B;
	for (int i = finalJ; i >= finalI; i--)
	{
		if (!A[i])
			b--;

		if (!b)
			break;

		rcurr++;
	}

	if (!b)
		return max(lcurr, rcurr);

	if (lcurr > rcurr) {
		for (int i = finalJ + 1; i < n; i++) {
			if (!A[i])
				b--;

			if (!b)
				break;

			lcurr++;
		}

		return lcurr;
	}
	else {
		for (int i = finalJ - 1; i >= 0; i--)
		{
			if (!A[i])
				b--;

			if (!b)
				break;

			rcurr++;
		}
		return rcurr;
	}




}
