int Solution::singleNumber(const vector<int> &A) {
	int maxx = *max_element(A.begin(), A.end());
	int digit = log2(maxx) + 1;
	int ans = 0, cnt = 0;
	for (int i = 0; i < digit; i++) {
		for (int j = 0; j < A.size(); j++) {
			if (A[j] & (1 << i))
				cnt++;
		}

		ans |= ((cnt % 3) << i);
		cnt = 0;
	}

	return ans;
}

// or


int singleNumber(const vector<int> &A) {
	int n = A.size();
	int ones = 0, twos = 0, threes = 0;
	for (int i = 0; i < n; i++) {
		twos |= ones & A[i];
		ones ^= A[i];
		threes = ones & twos;
		ones &= ~threes;
		twos &= ~threes;
	}
	return ones;
}

// ones store elements occuring once
// twos store elements occuring twice
// threes removes ones and twos
// final ans is ones as XOR is asso + comm