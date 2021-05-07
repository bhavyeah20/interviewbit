
class Solution {
public:
	string intToRoman(int num) {
		// 1000, 2000, 3000
		string M[] = {"", "M", "MM", "MMM"};
		// 100, 200, 300, .. 900
		string C[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
		// 10, 20, ... 90
		string X[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
		// 1, 2, ... 9
		string I[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
		return M[num / 1000] + C[(num % 1000) / 100] + X[(num % 100) / 10] + I[num % 10];
	}
};



string Solution::intToRoman(int A) {

	string numerals[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX",
	                     "V", "IV", "I"
	                    };
	int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

	if (A < 1 && A > 3999)
		return "";

	int i = 0;
	string res = "";
	while (A > 0)
	{
		if (A - values[i] >= 0)
		{
			res += numerals[i];
			A = A - values[i];
		}
		else
		{
			i++;
		}
	}


	return res;
}

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
