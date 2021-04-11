//  0 1 2 5
// 3
// 522




int Solution::solve(vector<  int> &A,   int B,   int C) {

	long long int flag = 0;

	int digits = 0;
	string s = to_string(C);
	reverse(s.begin(), s.end());
	C = stoi(s);
	digits = s.size();

	if (!A.size() || !C)
		return 0;
	if (B > digits)
		return 0;


	if (A[0] == 0)
		flag = 1;


	if (B < digits)
	{
		if (B == 1)
			return A.size();
		return ((A.size() - flag) * pow(A.size(), B - 1));
	}


	long long int ans = 0;
	long long int currDigit = B;

	if (B == 1)
		return lower_bound(A.begin(), A.end(), C) - A.begin();
	while (C)
	{

		long long int num = C % 10;

		long long int indexLb = lower_bound(A.begin(), A.end(), num) - A.begin();

		if (currDigit == B && flag)
			indexLb--;
		ans += indexLb * pow(A.size(), currDigit - 1);

		if (s[B - currDigit] != num)
			return ans;

		C /= 10;
		currDigit--;

	}

	return ans;
}

