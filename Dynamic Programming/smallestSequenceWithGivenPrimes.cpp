vector<int> Solution::solve(int A, int B, int C, int D) {
	vector<int> dp(1, 1);
	int i = 0, j = 0, k = 0;

	while (D--) {
		int curr = min(A * dp[i], min(B * dp[j], C * dp[k]));
		dp.push_back(curr);
		if (curr == A * dp[i]) {
			i++;
		}

		if (curr == B * dp[j]) {
			j++;
		}

		if (curr == C * dp[k]) {
			k++;
		}
	}

	dp.erase(dp.begin());
	return dp;
}

//or

Implement Heap starting with i = 1, and next i is top of heap;

1
2 3 5 (1 * 2, 1 * 3, 1 * 5)
3 4 5 6 10(2 * 2, 2 * 3, 2 * 5)
4 5 6 9 10 15(3 * 2, 3 * 3, 3 * 5)
5 6 8 9 10 12 15 20

//or

vector<int> Solution::solve(int A, int B, int C, int D) {
	vector<bool> dp(1000001, 0);
	vector<int> ans;


	int cnt = 0;
	dp[A] = 1, dp[B] = 1, dp[C] = 1;
	for (int i = 1; cnt < D ; i++) {

		if (i == A || i == B || i == C) {
			ans.push_back(i);
			cnt++;
			continue;
		}


		if (i % A == 0 && dp[i / A]) {
			ans.push_back(i);
			cnt++;
			dp[i] = 1;
		}
		else if (i % B == 0 && dp[i / B]) {
			ans.push_back(i);
			cnt++;
			dp[i] = 1;
		}
		else if (i % C == 0 && dp[i / C]) {
			ans.push_back(i);
			cnt++;
			dp[i] = 1;
		}
	}



	return ans;
}
