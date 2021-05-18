int Solution::largestRectangleArea(vector<int> &A) {
	int N = A.size();

	stack<int> right;

	int area = INT_MIN;
	for (int i = 0; i < N; i++) {
		while (!right.empty() && A[right.top()] > A[i]) {
			int t = A[right.top()];
			right.pop();
			int currArea = right.empty() ? t * i : t * (i - right.top() - 1);
			area = max(area, currArea);
		}

		right.push(i);
	}

	while (!right.empty()) {
		int t = A[right.top()];
		right.pop();
		int currArea = right.empty() ? t * N : t * (N - right.top() - 1);
		area = max(area, currArea);
	}


	return area;

}


//10 90 58 69 70 82 100 13 57 47 18

