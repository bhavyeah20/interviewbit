string Solution::addBinary(string A, string B) {
	string ans = "";
	int i = A.size() - 1, j = B.size() - 1;
	int carry = 0;
	int num = 0;
	while (i >= 0 || j >= 0 || carry) {
		num = carry;
		if (i >= 0)

			num += (A[i] - '0');

		if (j >= 0)
			num += (B[j] - '0');


		carry = num / 2;
		ans.push_back((num % 2) + '0');
		i--, j--;
	}

	reverse(ans.begin(), ans.end());
	return ans;


}
