vector<int> Solution::searchRange(const vector<int> &A, int B) {
	// vector<int> ans(2, -1);
	// ans[0] = lower_bound(A.begin(), A.end(), B) - A.begin();
	// if (A[ans[0]] != B) {
	// 	ans[0] = ans[1] = -1;
	// 	return ans;
	// }

	// ans[1] = upper_bound(A.begin(), A.end(), B) - A.begin() - 1;
	// return ans;

	vector<int> ans(2, -1);
	int s = 0, e = A.size() - 1;
	int res = -1;
	while (s <= e) {
		int mid = s + (e - s) / 2;
		if (A[mid] == B) {
			res = mid;
			e = mid - 1;
		}

		else if (A[mid] < B)
			s = mid + 1;

		else
			e = mid - 1;
	}

	if (res == -1) {
		return ans;
	}

	ans[0] = res;

	s = 0, e = A.size() - 1;
	while (s <= e) {
		int mid = s + (e - s) / 2;
		if (A[mid] == B) {
			res = mid;
			s = mid + 1;
		}

		else if (A[mid] < B)
			s = mid + 1;

		else
			e = mid - 1;
	}

	ans[1] = res;
	return res;

}
