long long int chop(vector<int> &A, int k) {
	long long int res = 0;
	for (int x : A) {
		long long int cut = x - k;
		if (cut > 0)
			res += cut;
	}

	return res;
}

int Solution::solve(vector<int> &A, int B) {
	int n = A.size();
	int s = 0;
	int e = *max_element(A.begin(), A.end());

	int ans = -1;
	while (s <= e) {
		int mid = s + (e - s) / 2;
		long long int res = chop(A, mid);
		if (res == B) {
			ans = mid;
			s = mid + 1;
		}

		else if ( res < B) {
			e = mid - 1;
		}

		else
			ans = mid, s = mid + 1;
	}

	return ans;
}
