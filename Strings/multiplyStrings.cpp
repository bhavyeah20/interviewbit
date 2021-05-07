string multiply(string num1, string num2) {
	int m = num1.size(), n = num2.size();
	string ans(m + n, '0');
	for (int i = m - 1; i >= 0; i--) {
		for (int j = n - 1; j >= 0; j--) {
			int sum = (num1[i] - '0') * (num2[j] - '0') + (ans[i + j + 1] - '0');
			ans[i + j + 1] = sum % 10 + '0';
			ans[i + j] += sum / 10;
		}
	}
	for (int i = 0; i < m + n; i++) {
		if (ans[i] != '0') {
			return ans.substr(i);
		}
	}
	return "0";
}

// or

// string Solution::multiply(string s1, string s2) {

// 	int n = s1.size(); //56 i
// 	int m = s2.size(); //283 j

// 	string v = "";

// 	for (int i = 0; i < m + n; i++)
// 		v.push_back('0');
// 	int carry = 0, num = 0, ele = 0;

// 	reverse(s1.begin(), s1.end());
// 	reverse(s2.begin(), s2.end());

// 	for (int i = 0; i < n; i++) {
// 		string s = "";
// 		for (int j = 0; j < m; j++) {
// 			num = (s2[j] - '0') * (s1[i] - '0') + carry;
// 			ele = num % 10;
// 			carry = num / 10;
// 			s += to_string(ele);
// 		}

// 		while (carry) {
// 			s += to_string(carry % 10);
// 			carry /= 10;
// 		}

// 		carry = 0;
// 		int idx = i;


// 		for (int j = 0; j < s.size(); j++) {
// 			num = (v[i] - '0') + (s[j] - '0') + carry;
// 			v[i] = (num % 10) + '0';
// 			carry = num / 10;
// 			i++;
// 		}

// 		while (carry) {
// 			num = v[i] - '0' +  carry;
// 			v[i] = (num % 10) + '0';
// 			carry = num / 10;
// 			i++;
// 		}

// 		i = idx;
// 	}


// 	int sz = v.size() - 1;

// 	while (v[sz] == '0')
// 		sz--;


// 	v.erase(sz + 1);

// 	reverse(v.begin(), v.end());
// 	if (v.empty())
// 		return "0";
// 	return v;
// }