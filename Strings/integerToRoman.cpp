string Solution::intToRoman(int A) {
	unordered_map<int, string> mp;
	mp[1] = "I";
	mp[5] = "V";
	mp[10] = "X";
	mp[50] = "L";
	mp[100] = "C";
	mp[500] = "D";
	mp[1000] = "M";
	mp[4] = "IV";
	mp[9] = "IX";
	mp[40] = "XL";
	mp[90] = "XC";
	mp[400] = "CD";
	mp[900] = "CM";
	vector<int> romans({1, 5, 10, 50, 100, 500, 1000});
	string s = to_string(A);
	int sz = s.size();
	s = "";

	while (sz--) {
		int firstDigit = A / pow(10, sz);
		int closest = firstDigit * pow(10, sz);
		A -= closest;
		if (mp.find(closest) != mp.end()) {
			s += mp[closest];
		} else {
			while (closest) {
				int romanArrayIdx = upper_bound(romans.begin(), romans.end(), closest) - romans.begin() - 1;
				int closestRoman = romans[romanArrayIdx];
				s += mp[closestRoman];
				closest -= closestRoman;
			}
		}
	}

	return s;

}