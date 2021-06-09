#include<bits/stdc++.h>

using namespace std;

vector<bool> dp(10000000000001, 0);

vector<int> solve(int A, int B, int C, int D) {
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


int main() {
	vector<int> v =  solve(2, 3, 5, 1000);
	for (int x : v)
		cout << x << " ";
}
