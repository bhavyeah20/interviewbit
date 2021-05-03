int Solution::search(const vector<int> &A, int B) {
	int n = A.size();

	int start = 0;
	int end = n - 1;

	int idx = -1;
	while (start < end) {
		int mid = start + (end - start) / 2;
		if (A[start] < A[end]) {
			idx = start;
			break;
		}

		if (A[start] <= A[mid]) {
			start = mid + 1;
		}

		else
			end = mid;


	}
	if (idx == -1)
		idx = start;
	int idx1 = binary_search(A.begin(), A.begin() + idx, B);
	if (idx1) {
		return lower_bound(A.begin(), A.begin() + idx, B) - A.begin();
	}

	int idx2 = binary_search(A.begin() + idx, A.end(), B);
	if (idx2) {
		return lower_bound(A.begin() + idx, A.end(), B) - A.begin();
	}

	return -1;

}

// or

// int Solution::search(const vector<int> &A, int B) {
// 	int n = A.size();
// 	int low = 0, high = n - 1;
// 	while (low <= high) {
// 		int mid = low + (high - low) / 2;
// 		if (A[mid] == B) return mid;
// 		else if (A[0] <= A[mid]) { //i.e. left part is sorted
// 			if (A[0] <= B && B < A[mid]) high = mid - 1; //B lies on left part
// 			else low = mid + 1;
// 		} else { //right part is sorted
// 			if (A[mid] < B && B <= A[n - 1]) low = mid + 1; //B lies on right part
// 			else high = mid - 1;
// 		}
// 	}
// 	return -1;
// }
