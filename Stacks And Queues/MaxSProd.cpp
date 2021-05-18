int Solution::maxSpecialProduct(vector<int> &A) {
	long long mod = 1e9 + 7;
	long long n = A.size();
	vector<long long> left(n, -1), right(n, -1);
	stack<long long> leftS, rightS;

	for (long long i = 0; i < n; i++) {
		while (!rightS.empty() && A[rightS.top()] <= A[i]) {
			long long topIdx = rightS.top();
			rightS.pop();
			left[topIdx] = rightS.empty() ? -1 : rightS.top();
		}

		rightS.push(i);
	}

	for (long long i =  n - 1; i >= 0; i--) {
		while (!leftS.empty() && A[leftS.top()] <= A[i]) {
			long long topIdx = leftS.top();
			leftS.pop();
			right[topIdx] = leftS.empty() ? -1 : leftS.top();
		}

		leftS.push(i);
	}


	long long ans =  INT_MIN;


	for (long long i = 0; i < n; i++) {
		if (left[i] != -1 && right[i] != -1) {
			long long prod = (left[i] % mod) * (right[i] % mod);
			if (prod > ans)
				ans = prod;
			ans %= mod;
		}
	}

	return ans ==  INT_MIN ? 0 : ans % mod;
}
