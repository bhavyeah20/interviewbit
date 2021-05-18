int Solution::trap(const vector<int> &A) {
	int n = A.size();
	stack<int> s;
	vector<int> posLeft(n, -1), posRight(n, -1);
	int waterHeld = 0, total = 0;

	int pL, pR;

	for (int i = 0; i < n; i++) {
		while (!s.empty() && A[s.top()] <= A[i]) {
			posLeft[s.top()] = pL;
			s.pop();
		}

		if (s.empty())
			pL = i;

		s.push(i);
	}


	while (!s.empty())
		s.pop();

	for (int i =  n - 1; i >= 0; i--) {
		while (!s.empty() && A[s.top()] <= A[i]) {
			posRight[s.top()] = pR;
			s.pop();
		}

		if (!s.empty())
			pR = i;
		s.push(i);
	}

	for (int i = 0; i < n; i++) {
		if (posLeft[i] != -1 && posRight[i] != -1 && posLeft[i] != i && posRight[i] != i) {
			waterHeld = (min(A[posLeft[i]], A[posRight[i]]) - A[i]);
			total += waterHeld;

			cout << i << " " << waterHeld << " " << total << endl;
		}
	}

	return total;
}
