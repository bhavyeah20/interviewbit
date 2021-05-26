string Solution::fractionToDecimal(int a, int b) {

	unordered_map<long long, int> mp; // num -> index
	string s;
	bool flag = 0;
	int i = 0;
	long long digit;
	bool sign = 0;

	sign = a < 0 ^ b < 0;

	long long A = a, B = b;

	A = A < 0 ? -A : A;
	B = B < 0 ? -B : B;

	while (A) {
		if (A < B && !flag) {
			if (!s.empty())
				s.push_back('.'), i++;
			else
				s = "0.", i += 2;
			flag = 1;
		}

		if (A < B)
			A *= 10;


		if (mp.find(A) != mp.end()) {
			s.insert(s.begin() + mp[A], '(');
			s.push_back(')');
			return s;
		}
		mp[A] = i;
		digit = A / B;
		s += to_string(digit);

		A -= digit * B;
		i++;

	}

	if (s.empty())
		return "0";


	if (sign)
		s.insert(s.begin(), '-');
	return s;


}