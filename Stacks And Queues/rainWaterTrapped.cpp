// O(n^2), O(1)

int Solution::trap(const vector<int> &A) {
	int n = A.size();
	int waterHeld = 0;
	for (int i = 0; i < n; i++) {
		int leftMax = -1, rightMax = -1;
		for (int j = i - 1; j >= 0; j--) {
			leftMax = max(leftMax, A[j]);
		}

		for (int j = i + 1; j < n; j++) {
			rightMax = max(rightMax, A[j]);
		}

		waterHeld += max(0, min(leftMax, rightMax) - A[i]);
	}

	return waterHeld;
}

//O(n), O(n)

int Solution::trap(const vector<int> &A) {
	int n = A.size();
	int waterHeld = 0;
	if (n < 3)
		return 0;
	vector<int> leftMax(n, A[0]);
	vector<int> rightMax(n, A[n - 1]);
	for (int i = 1; i < n; i++) {
		leftMax[i] = max(leftMax[i - 1], A[i]);
	}
	for (int i = n - 2; i >= 0; i--) {
		rightMax[i] = max(rightMax[i + 1], A[i]);
	}

	for (int i = 0; i < n; i++) {
		waterHeld += max(0, min(leftMax[i], rightMax[i]) - A[i]);
	}

	return waterHeld;
}

// O(n), O(1)

int Solution::trap(const vector<int> &A) {
	int n = A.size();
	int waterHeld = 0;
	if (n < 3)
		return 0;
	int leftMax =  A[0];
	int rightMax = A[n - 1];

	int i = 1, j = n - 2;

	while (i <= j) {
		leftMax = max(leftMax, A[i]);
		rightMax = max(rightMax, A[j]);

		if (leftMax < rightMax) {
			waterHeld += leftMax - A[i];
			i++;
		} else {
			waterHeld += rightMax - A[j];
			j--;
		}
	}

	return waterHeld;
}

//O(n), O(n)

int Solution::trap(const vector<int> &A) {
	int n = A.size();
	int waterHeld = 0;
	if (n < 3)
		return 0;

	stack<int> s; // maintain decreasing value to store a U valley


	for (int i = 0 ; i < n; i++) {
		while (!s.empty() && A[s.top()] < A[i]) {
			int top = A[s.top()];
			s.pop();
			if (s.empty())
				break;

			int distance = i - s.top() - 1;
			int height = min(A[s.top()], A[i]) - top;
			waterHeld += distance * height;
		}

		s.push(i);
	}

	return waterHeld;
}
