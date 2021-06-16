#include<iostream>

using namespace std;

<<<<<<< HEAD
int main() {

	// int n ;
	// cin >> n;


	cout<<"Num is ";
=======
int calc(string A, int i, int j) {
	int w = 0, b = 0;

	for (int idx = i; idx <= j; idx++) {
		if (A[idx] == 'B')
			b++;
		else
			w++;
	}

	return b * w;
}

int cost(string A, int i, int j, int cuts, vector<vector<int> > &dp) {
	if (cuts == 0)
		return dp[cuts][i] = calc(A, i, j);

	if (dp[cuts][i] != -1)
		return dp[cuts][i];

	int ans = 10000000;
	for (int k = i; k < j; k++) {
		int curr = calc(A, i, k) + cost(A, k + 1, j, cuts - 1, dp);

		ans = min(curr, ans);
	}

	return dp[cuts][i] = ans;
}

int arrange(string A, int B) {
	if (!B)
		return -1;

	if (A.size() < B)
		return -1;
	vector<vector<int> > dp(B, vector<int> (A.size(), -1));
	int a =  cost(A, 0, A.size() - 1, B - 1, dp);
	// for (auto it : dp) {
	// 	for (auto x : it) {
	// 		cout << setw(10) << x << " ";
	// 	}
	// 	cout << endl;
	// }
	return a;
}


int main() {
	string A = "BWWWWBBWWBWBWWBBBBBWBWWBBBWWWWBBBW";
	int B = 28;
	cout << arrange(A, B);
>>>>>>> c9dfe9fb8deb4c18ff19c36a6917c10374b9e82e
}
