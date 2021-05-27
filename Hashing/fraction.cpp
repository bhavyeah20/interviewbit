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


string Solution::fractionToDecimal(int a, int b) {

	string s = "";
	long long A = a, B = b;

	if (!A)
		return "0";

	long long q, r;
	bool sign = A < 0 ^ B < 0;
	if (sign)
		s.push_back('-');


	if (A < 0)
		A *= -1;

	if (B < 0)
		B *= -1;
	q = A / B;
	r = A % B;

	s += to_string(q);
	if (!r) {
		return s;
	}

	s.push_back('.');
	unordered_map<long long, long long> mp;//rem -> len
	while (r) {
		r *= 10;
		if (mp.find(r) != mp.end()) {
			s.insert(s.begin() + mp[r], '(');
			s.push_back(')');
			return s;
		}
		mp[r] = s.length();

		s += to_string(r / B);
		r %= B;

	}

	return s;

}
