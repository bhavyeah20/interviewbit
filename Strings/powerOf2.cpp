int Solution::power(string A) {

	long long int i = 0;
	long long int curr = 0;
	string quot = A;
	long long int rem = 0;
	while (quot != "2") {
		long long int	N = quot.size();
		i = 0;
		rem = 0;
		curr = 0;
		string newQuot = "";
		while (i < N) {
			curr = (quot[i] - '0') + rem * 10;
			if (curr < 2) {
				if (i) {
					newQuot.push_back('0');
				}
				i++;
				curr *= 10;
				curr += quot[i] - '0';

			}

			rem = curr % 2;
			newQuot.push_back((curr / 2) + '0');

			i++;
		}
		quot = newQuot;
		if (rem == 1)
			return 0;
	}

	return 1;

}

// or

// void mult(string &s) {
// 	string ans = "";
// 	reverse(s.begin(), s.end());
// 	int carry = 0;
// 	for (int i = 0; i < s.size(); i++) {
// 		int num = (s[i] - '0') * 2 + carry;
// 		int ele = num % 10;
// 		carry = num / 10;
// 		ans.push_back(ele + '0');

// 	}

// 	while (carry) {
// 		ans.push_back((carry % 10) + '0');
// 		carry /= 10;
// 	}
// 	// cout<<ans<<endl;
// 	reverse(ans.begin(), ans.end());
// 	s = ans;
// }


// // int power(string A) {
// int Solution::power(string A) {

// 	string s = "2";
// 	if (s == A)
// 		return 1;

// 	while (s.size() < A.size()) {
// 		mult(s);
// 	}

// 	if (s.size() > A.size())
// 		return 0;

// 	while (s[0] - '0' < A[0] - '0' && s.size() == A.size()) {
// 		// cout<<s<<endl;
// 		mult(s);
// //         cout<<s<<endl;
// 	}

// 	if (s != A)
// 		return 0;

// 	return 1;
// }


string divideBy2(string num) {
	string quot = "";
	int a = 0, i = 0;
	while (i < num.size()) {
		a = a * 10 + num[i] - '0';
		while (a < 2 && i < num.size() - 1) {
			if (quot != "")quot += '0';
			a = a * 10 + num[++i] - '0';
		}
		quot += '0' + a / 2;
		a = a % 2;
		i++;
	}
	return quot;
}

int Solution::power(string A) {
	if (A.size() == 1 && (A[0] - '0') < 2)return 0;
	while ((A[A.size() - 1] - '0') % 2 == 0) {
		A = divideBy2(A);
	}
	if (A.size() == 1 && A[0] == '1')return 1;
	return 0;
}