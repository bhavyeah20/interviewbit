int Solution::paint(int A, int B, vector<int> &C) {
	long long int mod = 10000003;
	long long int n = C.size();
	long long int s = *max_element(C.begin(), C.end());
	long long int e = 0;
	for (long long int x : C) {
		e += x;
	}
	long long int res = 0;
	while (s <= e) {
		long long int mid = s + (e - s) / 2;
		long long int cnt = 0, curr = 0;
		for (long long int i = 0; i < n; i++) {
			curr += C[i];
			if (curr > mid) {
				curr = 0;
				cnt++;
				i--;
			}
		}

		cnt++;

		if (cnt <= A) {
			res = mid;
			e = mid - 1;
		}

		else {
			s = mid + 1;
		}
	}

	return (res % mod * B % mod) % mod;
}
