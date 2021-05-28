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
