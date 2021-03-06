int getRev(int x) {
	int rev = 0;
	while (x) {
		rev |= x & 1;
		x >>= 1;
		rev <<= 1;
	}

	rev >>= 1;
	return rev;
}

int Solution::solve(int A) {
	int cnt = 1;
	int len = 1;

	while (cnt < A) {
		len++;
		int numsTillLen = 1 << ((len - 1) / 2);
		cnt += numsTillLen;

	}


	cnt -= 1 << ((len - 1) / 2);


	int offset = A - cnt - 1;

	int ans = 1 << (len - 1);
	ans |= offset << (len / 2);

	int rev = ans >> (len / 2);
	rev = getRev(rev);

	ans |= rev;

	return ans;

}

//or

int convertToNum(string s) {
	int sz = s.size();
	int num = 0;
	int i = sz - 1;
	while (i >= 0) {
		num += (s[i] - '0') * pow(2, sz - i - 1);
		i--;
	}

	return num;
}

int Solution::solve(int A) {
	queue<string> q;
	q.push("11");

	if (A == 1)
		return 1;

	if (A == 2)
		return 3;

	int cnt = 2;
	while (!q.empty()) {
		string ele = q.front();
		// cout << ele << endl;
		if (cnt == A)
			return convertToNum(ele);
		int sz = ele.size();
		if (sz & 1) {
			int i = (sz - 1) / 2;
			ele.insert(i, 1, ele[i]);
			q.push(ele);
			q.pop();
		} else {
			int i = (sz - 1) / 2;
			string ele2 = ele;
			ele.insert(i + 1, 1, '0');
			ele2.insert(i + 1, 1, '1');
			q.push(ele);
			q.push(ele2);
			q.pop();
		}

		cnt++;
	}
}


//or

string generatePstring(int x) {
	int sz = log2(x) + 1;
	string s(sz, '0');
	int i = sz - 1;
	while (x) {
		s[i] = (x & 1) + '0';
		x >>= 1;
		i--;
	}

	return s;

}

int generatePnum(string s) {
	int sz = s.size();
	int num = 0;
	int i = sz - 1;
	while (i >= 0) {
		num += (s[i] - '0') * pow(2, sz - i - 1);
		i--;
	}

	return num;
}

int generateP(int x) {
	if (x == 1)
		return 1;

	int palindrome = generateP(x - 1);
	// cout << "palindrome " << palindrome << endl;
	string s = generatePstring(palindrome);

	int sz = s.size();
	int i = (sz - 1) / 2;
	int j = i;
	if (!(sz & 1)) {
		j = i + 1;
	}

	while (i >= 0 && j < sz) {
		if (s[i] == '0') {
			s[i] = s[j] = '1';
			return generatePnum(s);
		}

		int k = 0, cnt = 0;
		for (int k = 0; k < sz; k++) {
			if (s[k] == '1')
				cnt++;
		}

		if (cnt == sz) {
			int n = generatePnum(s);
			string ss = generatePstring(n + 2);
			return generatePnum(ss);
		}


		else {
			while (i >= 0 && j < sz && s[i] == '1') {
				s[i] = s[j] = '0';
				i--, j++;
			}

			s[i] = s[j] = '1';

			return generatePnum(s);
		}
	}



}




int Solution::solve(int A) {
	return generateP(A);
}
