#include<bits/stdc++.h>

using namespace std;
int solve(vector<vector<int> > &A) {
	int n = A.size(), m = A[0].size();
	for (int i = 0; i < n; i++) {
		int cnt = 0;
		for (int j = m - 1; j >= 0 ; j--) {
			if (!A[i][j])
				cnt = 0;

			else
				A[i][j] = ++cnt;
		}
	}


	int curr = 0, maxArea = 0;
	for (int j = 0; j < m; j++) {
		stack<int> s;
		for (int i = 0; i < n; i++ ) {
			while (!s.empty() && A[s.top()][j] > A[i][j]) {
				int top = A[s.top()][j];
				s.pop();
				int len = s.empty() ? i : i - s.top() + 1;

				if (len == top)
					maxArea = max(maxArea, top * len);
			}
			s.push(i);
		}

		while (!s.empty()) {
			int top = A[s.top()][j];
			s.pop();
			int len = s.empty() ? n : n - s.top() + 1;

			if (len == top)
				maxArea = max(maxArea, top * len);
		}


	}

	return maxArea;
}


int main() {
	vector<vector<int> > v({
		{0, 0, 1, 0, 0, 0, 0, 0},
		{1, 1, 1, 1, 1, 1, 1, 0}

	});
	cout << solve(v);
}
