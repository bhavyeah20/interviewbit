int compareStrings(string s1, string s2) {
	int n = s1.size();
	int m = s2.size();

	int i = 0, j = 0;

	while (i < n && s1[i] == '0')
		i++;

	while (j < n && s2[j] == '0')
		j++;

	if (i == n)
		s1 = "0";
	else
		s1.erase(0, i);

	if (j == n)
		s2 = "0";
	else
		s2.erase(0, j);

	i = 0, j = 0;

	n = s1.size();
	m = s2.size();

	if (n > m)
		return 1;

	if (m > n)
		return -1;

	while (i < n && j < m) {
		if (s1[i] - '0' > s2[j] - '0')
			return 1;

		else if (s1[i] - '0' < s2[j] - '0')
			return -1;

		i++, j++;
	}

	return 0;
}


int Solution::compareVersion(string A, string B) {
	long long int n = A.size();
	long long int m = B.size();
	long long int i = 0, j = 0;

	while (i < n && j < m) {
		long long int startI = i;
		while (i < n && A[i] != '.') {
			i++;
		}

		string s1 = A.substr(startI, i - startI);

		string num1 = (s1 == "") ? "0" : s1;



		long long int startJ = j;
		while (j < m && B[j] != '.') {
			j++;
		}

		string s2 = B.substr(startJ, j - startJ);

		string num2 = (s2 == "") ? "0" : s2;



		if (!compareStrings(num1, num2)) {
			i++, j++;

			continue;
		}
		return compareStrings(num1, num2);


	}


	if (i == n || i == n + 1 ) {
		while (j < m) {
			long long int startJ = j;
			while (j < m && B[j] != '.') {
				j++;
			}

			string s2 = B.substr(startJ, j - startJ);

			string num2 = (s2 == "") ? "0" : s2;

			j++;

			if (!compareStrings("0", num2)) {
				j++;

				continue;
			}
			return compareStrings("0", num2);
		}

		return 0;

	}

	if (j == m || j == m + 1) {
		while (i < n) {
			long long int startI = j;

			while (i < n && A[i] != '.') {
				i++;
			}

			string s1 = A.substr(startI, j - startI);

			string num1 = (s1 == "") ? "0" : s1;

			i++;

			if (!compareStrings(num1, "0")) {
				i++;

				continue;
			}
			return compareStrings(num1, "0");
		}

		return 0;
	}


}